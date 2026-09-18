import os
import sys
import logging
from datetime import datetime, timezone

logging.basicConfig(level=logging.INFO, format="%(levelname)s: %(message)s")

ARCHITECTURE_FILE = "ARCHITECTURE.md"


class Architecture:
    """
    Scans the LeonardOS repository and regenerates the architecture document.

    Repository layout:
        arch/
        binaries/
        drivers/
        libraries/
        memory/
        platform/
        system/

    A 'component' is a directory at the repository root containing an
    'inc/' and/or 'code/' tree.

    Architecture implementations are handled specially:
        arch/<architecture>/<component>/

    For example:
        arch/aarch64/irq/
        arch/aarch64/seh/
        arch/aarch64/fpu/
        arch/aarch64/types/

    The generated document preserves this distinction instead of treating
    architecture directories as ordinary top-level components.
    """

    ROOT_DIRECTORIES = (
        "arch",
        "binaries",
        "drivers",
        "libraries",
        "memory",
        "platform",
        "system",
    )

    def __init__(self, verbosity: bool):
        self._verbosity = verbosity
        self._ROOT_DIR = os.path.join(os.getcwd(), "dev", "kernel")
        self._OUTPUT_FILE = os.path.join(os.getcwd(), ARCHITECTURE_FILE)

    # --------------------------------------------------------------------------
    # Scanning
    # --------------------------------------------------------------------------

    def _has_component_layout(self, path: str) -> bool:
        """Return True when a directory contains an 'inc/' or 'code/' tree."""
        return (
            os.path.isdir(os.path.join(path, "inc")) or
            os.path.isdir(os.path.join(path, "code"))
        )

    def _scan_component(self, component_path: str) -> dict:
        """
        Recursively scan a component.

        A component can contain:
            inc/
            src/
            code/

        'code/' contains subcomponents, which follow the same structure
        recursively.

        Example:
            test/
            ├── inc/
            └── code/
                ├── assert/
                │   ├── inc/
                │   └── src/
                ├── run/
                │   └── src/
                └── utils/
                    └── src/

        Returns:
            {
                "inc": bool,
                "src": bool,
                "code": {
                    <subcomponent>: {
                        "inc": bool,
                        "src": bool,
                        "code": {
                            ...
                        }
                    }
                }
            }
        """

        result = {
            "inc": os.path.isdir(os.path.join(component_path, "inc")),
            "src": os.path.isdir(os.path.join(component_path, "src")),
            "code": {},
        }

        code_dir = os.path.join(component_path, "code")

        if not os.path.isdir(code_dir):
            return result

        for entry in sorted(os.listdir(code_dir)):
            entry_path = os.path.join(code_dir, entry)

            if not os.path.isdir(entry_path):
                continue

            result["code"][entry] = self._scan_component(entry_path)

        return result

    def _scan_arch(self) -> dict:
        """
        Scan architecture implementations.

        Returns:
            {
                architecture: {
                    component: component_info
                }
            }
        """
        result = {}

        arch_root = os.path.join(self._ROOT_DIR, "arch")
        if not os.path.isdir(arch_root):
            return result

        for architecture in sorted(os.listdir(arch_root)):
            architecture_path = os.path.join(arch_root, architecture)

            if not os.path.isdir(architecture_path):
                continue

            components = {}

            for component in sorted(os.listdir(architecture_path)):
                component_path = os.path.join(architecture_path, component)

                if os.path.isdir(component_path) and self._has_component_layout(component_path):
                    components[component] = self._scan_component(component_path)

            if components:
                result[architecture] = components

                if self._verbosity:
                    logging.info(
                        f"Found architecture: {architecture}  "
                        f"components: {list(components.keys())}"
                    )

        return result

    def _scan_root_components(self) -> dict:
        """
        Scan all non-architecture top-level components.

        Returns:
            {
                root: {
                    component: component_info
                }
            }
        """
        result = {}

        for root in self.ROOT_DIRECTORIES:
            if root == "arch":
                continue

            root_path = os.path.join(self._ROOT_DIR, root)

            if not os.path.isdir(root_path):
                logging.warning(f"Root directory not found: {root_path}")
                continue

            components = {}

            for component in sorted(os.listdir(root_path)):
                component_path = os.path.join(root_path, component)

                if os.path.isdir(component_path) and self._has_component_layout(component_path):
                    components[component] = self._scan_component(component_path)

                    if self._verbosity:
                        logging.info(
                            f"Found component: {root}/{component}"
                        )

            result[root] = components

        return result

    def scan(self) -> dict:
        """
        Scan the repository.

        Returns:
            {
                "arch": {
                    <architecture>: {
                        <component>: <component_info>
                    }
                },
                "components": {
                    <root>: {
                        <component>: <component_info>
                    }
                }
            }
        """
        return {
            "arch": self._scan_arch(),
            "components": self._scan_root_components(),
        }

    # --------------------------------------------------------------------------
    # Rendering
    # --------------------------------------------------------------------------

    def _render_component_tree(
        self,
        component: str,
        info: dict,
        prefix: str,
        root_path: str,
    ) -> list:
        lines = []

        children = []

        if info["inc"]:
            children.append(("inc/", None))

        if info["src"]:
            children.append(("src/", None))

        if info["code"]:
            children.append(("code/", info["code"]))

        if not children:
            return lines

        for index, (name, content) in enumerate(children):
            last = index == len(children) - 1
            branch = "└──" if last else "├──"

            lines.append(f"{prefix}{branch} {name}")

            child_prefix = prefix + ("    " if last else "│   ")

            if content is not None:
                items = list(content.items())

                for sub_index, (subcomponent, sub_info) in enumerate(items):
                    sub_last = sub_index == len(items) - 1
                    sub_branch = "└──" if sub_last else "├──"

                    lines.append(
                        f"{child_prefix}{sub_branch} {subcomponent}/"
                    )

                    sub_prefix = child_prefix + (
                        "    " if sub_last else "│   "
                    )

                    lines.extend(
                        self._render_component_tree(
                            subcomponent,
                            sub_info,
                            sub_prefix,
                            os.path.join(root_path, "code"),
                        )
                    )

        return lines

    def _render_tree(self, data: dict) -> str:
        lines = ["```", "kernel/"]

        roots = []
        if data["arch"]:
            roots.append(("arch", data["arch"]))
        roots.extend(
            (root, data["components"][root])
            for root in self.ROOT_DIRECTORIES
            if root != "arch" and root in data["components"]
        )

        for root_index, (root, content) in enumerate(roots):
            root_last = root_index == len(roots) - 1
            root_branch = "└──" if root_last else "├──"

            lines.append(f"{root_branch} {root}/")

            root_prefix = "    " if root_last else "│   "

            if root == "arch":
                architectures = list(content.items())

                for arch_index, (architecture, components) in enumerate(architectures):
                    arch_last = arch_index == len(architectures) - 1
                    arch_branch = "└──" if arch_last else "├──"
                    lines.append(
                        f"{root_prefix}{arch_branch} {architecture}/"
                    )

                    arch_prefix = root_prefix + (
                        "    " if arch_last else "│   "
                    )

                    component_items = list(components.items())

                    for component_index, (component, info) in enumerate(component_items):
                        component_last = component_index == len(component_items) - 1
                        component_branch = "└──" if component_last else "├──"

                        lines.append(
                            f"{arch_prefix}{component_branch} {component}/"
                        )

                        component_prefix = arch_prefix + (
                            "    " if component_last else "│   "
                        )

                        lines.extend(
                            self._render_component_tree(
                                component,
                                info,
                                component_prefix,
                                f"arch/{architecture}",
                            )
                        )

            else:
                component_items = list(content.items())

                for component_index, (component, info) in enumerate(component_items):
                    component_last = component_index == len(component_items) - 1
                    component_branch = "└──" if component_last else "├──"

                    lines.append(
                        f"{root_prefix}{component_branch} {component}/"
                    )

                    component_prefix = root_prefix + (
                        "    " if component_last else "│   "
                    )

                    lines.extend(
                        self._render_component_tree(
                            component,
                            info,
                            component_prefix,
                            root,
                        )
                    )

        lines.append("```")
        return "\n".join(lines)

    def _count_components(self, data: dict) -> int:
        architecture_count = sum(
            len(components) for components in data["arch"].values()
        )

        root_count = sum(
            len(components) for components in data["components"].values()
        )

        return architecture_count + root_count

    def _count_subcomponents(self, data: dict) -> int:
        count = 0

        for components in data["arch"].values():
            count += sum(
                len(info["code"])
                for info in components.values()
            )

        for components in data["components"].values():
            count += sum(
                len(info["code"])
                for info in components.values()
            )

        return count

    def _render_markdown(self, data: dict) -> str:
        ts = datetime.now(timezone.utc).strftime("%Y-%m-%d %H:%M UTC")
        n_comp = self._count_components(data)
        n_sub = self._count_subcomponents(data)

        sections = []

        sections.append(
            f"# LeonardOS — Architecture\n\n"
            f"> Auto-generated by `tools/scripts/Architecture.py` — {ts}  \n"
            f"> **{n_comp}** component(s) · **{n_sub}** subcomponent(s)\n"
        )

        sections.append("\n## Kernel tree\n")
        sections.append(self._render_tree(data))

        return "\n".join(sections)

    # --------------------------------------------------------------------------
    # Public entry points
    # --------------------------------------------------------------------------

    def generate(self) -> None:
        """Scan the repository and write ARCHITECTURE.md at its root."""
        data = self.scan()
        content = self._render_markdown(data)

        with open(self._OUTPUT_FILE, "w") as f:
            f.write(content)

        logging.info(f"Architecture written to {self._OUTPUT_FILE}")

    def print_summary(self) -> None:
        """Print a compact architecture/component summary to stdout."""
        data = self.scan()

        print(f"\n{'─' * 56}")
        print(
            f"  LeonardOS architecture  "
            f"({self._count_components(data)} components)"
        )
        print(f"{'─' * 56}")

        if data["arch"]:
            print("  [arch]")
            for architecture, components in data["arch"].items():
                print(f"    [{architecture}]")
                for component, info in components.items():
                    print(f"      └─ {component}")

        for root in self.ROOT_DIRECTORIES:
            if root == "arch":
                continue

            components = data["components"].get(root, {})

            print(f"  [{root}]")
            for component in components:
                print(f"      └─ {component}")

        print(f"{'─' * 56}\n")


if __name__ == "__main__":
    verbosity = (
        True
        if len(sys.argv) > 1 and sys.argv[1] != "0"
        else False
    )

    architecture = Architecture(verbosity)
    architecture.generate()
    architecture.print_summary()
