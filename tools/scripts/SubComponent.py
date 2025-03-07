import os
import shutil
import logging
import sys
from Component import Component

logging.basicConfig(level=logging.INFO, format="%(levelname)s: %(message)s")

class SubComponent(Component):
    """
    Class to create a new sub-component for the kernel.
    """

    def __init__(self, verbosity: bool):
        """
        Initialize the sub-component name and directory.
        """
        super().__init__(verbosity)
        self._subcomponent_name = ""
        self._subcomponent_dir  = ""


    def check_for_component(self, component_name:str) -> bool:
        """
        Check if the parent component exists.
        """

        if component_name == "":
            component_name = input("Enter the name of the parent component: ").strip()

        if not component_name:
            logging.error("Invalid component name. Please enter a valid name.")
            return False, component_name

        if os.path.isdir(os.path.join(self._COMPONENT_ROOT_DIR, component_name)):
            self._component_dir  = os.path.join(self._COMPONENT_ROOT_DIR, component_name)
            self._component_name = component_name
            return True, component_name

        else:
            logging.warning(f"Component {component_name} does not exist.")
            return False, component_name


    def check_for_subcomponent(self, subcomponent_name:str) -> bool:
        """
        Check if the sub-component already exists.
        """

        if subcomponent_name == "":
            subcomponent_name = input("Enter the name of the new sub-component: ").strip()
            if not subcomponent_name:
                logging.error("Invalid sub-component name. Please enter a valid name.")
                return False

        if os.path.isdir(os.path.join(self._component_dir, subcomponent_name)):
            logging.error(f"Sub-component {subcomponent_name} already exists.")
            return False

        self._subcomponent_name = subcomponent_name
        self._subcomponent_dir  = os.path.join(self._component_dir, subcomponent_name)

        return True


    def request_create_component_dir(self) -> bool:
        """
        Request the user to create a new component directory.
        """

        create_component = input(f"Do you want to create it? (y/n): ").strip().lower()

        if create_component == "y":
            creation_ok = self.create_component_dir(self._component_name)

            if creation_ok:
                self.rename_component_files()
                self.replace_component_file_content()
                self.add_component_to_kernel_cmake()

            return creation_ok

        return False


    def create_subcomponent_dir(self) -> None:
        """
        Create a new sub-component directory with the given name and copy the necessary files.
        """

        # Copy template files
        shutil.copytree(os.path.join(self._CMAKE_COMPONENT_TEMPLATES_DIR, "part"), os.path.join(self._component_dir, self._subcomponent_name))

        if self._verbosity:
            logging.info(f"Created new sub-component: {self._subcomponent_name}")


    def rename_subcomponent_files(self) -> None:
        """
        Rename the sub-component files to match the new sub-component name.
        """

        for root, _, files in os.walk(self._subcomponent_dir):
            for file in files:
                new_name = file.replace("component", self._component_name.lower()).replace("COMPONENT", self._component_name.upper())
                new_name = new_name.replace("part", self._subcomponent_name.lower()).replace("PART", self._subcomponent_name.upper())

                old_path = os.path.join(root, file)
                new_path = os.path.join(root, new_name)
                os.rename(old_path, new_path)

                if self._verbosity:
                    logging.info(f"Renamed {file} to {new_name}")


    def replace_component_file_content(self) -> None:
        """
        Replace the content inside the new sub-component files with the appropriate name.
        """

        for root, _, files in os.walk(self._component_dir):
            for file in files:
                file_path = os.path.join(root, file)
                with open(file_path, "r") as f:
                    content = f.read()

                new_content = content.replace("component", self._component_name.lower()).replace("COMPONENT", self._component_name.upper())
                new_content = new_content.replace("part", self._subcomponent_name.lower()).replace("PART", self._subcomponent_name.upper())

                with open(file_path, "w") as f:
                    f.write(new_content)

                if self._verbosity:
                    logging.info(f"Updated content in {file}")


    def add_subcomponent_to_component_cmake(self) -> None:
        """
        Add the new sub-component to the parent component's CMake file.
        """

        component_cmake_file = os.path.join(self._component_dir, "CMakeLists.txt")

        try:
            with open(component_cmake_file, "r") as f:
                lines = f.readlines()

            with open(os.path.join(self._CMAKE_COMPONENT_TEMPLATES_DIR, "CMakeLists_part.txt"), "r") as f:
                template_lines = f.readlines()

            # Append existing component_cmake_file lines to template_lines
            template_lines.extend(lines)

            template_lines = [line.replace("COMPONENT", self._component_name.upper()) for line in template_lines]
            template_lines = [line.replace("component", self._component_name.lower()) for line in template_lines]
            template_lines = [line.replace("/PART", "/" + self._subcomponent_name) for line in template_lines]
            template_lines = [line.replace("/part", "/" + self._subcomponent_name) for line in template_lines]
            template_lines = [line.replace("PART", self._subcomponent_name.upper()) for line in template_lines]
            template_lines = [line.replace("part", self._subcomponent_name.lower()) for line in template_lines]

            marker_header = "# Add the path to each header directory here"
            for i, line in enumerate(template_lines):

                if marker_header in line:
                    new_line = "        ${"
                    new_line += f"{self._component_name.upper()}_{self._subcomponent_name.upper()}_HEADERS"
                    new_line += "}\n"
                    template_lines.insert(i + 1, new_line)
                    break

            with open(component_cmake_file, "w") as f:
                f.writelines(template_lines)

            if self._verbosity:
                logging.info(f"Added {self._subcomponent_name} to the component CMake file.")

        except FileNotFoundError:
            logging.error(f"Component CMake file not found at {component_cmake_file}.")


    def setup_component(self, component_name: str, subcomponent_name:str ) -> None:
        """
        Setup the new sub-component by creating the directory, renaming files, replacing content, and adding it to the kernel.
        """

        component_exists, self._component_name = self.check_for_component(component_name)
        if not component_exists:
            component_exists = self.request_create_component_dir()

        if component_exists:
            subcomponent_inexistent = self.check_for_subcomponent(subcomponent_name)

            if subcomponent_inexistent:
                self.create_subcomponent_dir()
                self.rename_subcomponent_files()
                self.replace_component_file_content()
                self.add_subcomponent_to_component_cmake()
                logging.info(f"Setup complete for sub-component: {self._subcomponent_name}")


if __name__ == "__main__":
    verbosity    = True if str(sys.argv[1]) != "0" else False
    subcomponent = SubComponent(verbosity)
    subcomponent.setup_component("", "")
