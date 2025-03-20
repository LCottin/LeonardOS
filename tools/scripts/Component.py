import os
import shutil
import logging
import sys

logging.basicConfig(level=logging.INFO, format="%(levelname)s: %(message)s")

class Component:
    """
    Class to create a new component for the kernel.
    """

    def __init__(self, verbosity: bool):
        """
        Initialize the component name and directory.
        """
        self._component_name = ""
        self._component_dir  = ""
        self._verbosity      = verbosity

        self._COMPONENT_ROOT_DIR            = os.path.join(os.getcwd(), "dev/kernel")
        self._CMAKE_COMPONENT_TEMPLATES_DIR = "./tools/cmake_templates/component"
        self._KERNEL_CMAKE_FILE             = os.path.join(self._COMPONENT_ROOT_DIR, "CMakeLists.txt")

        if self._verbosity:
            print(f"Component root directory: {self._COMPONENT_ROOT_DIR}")


    def create_component_dir(self, component_name: str) -> bool:
        """
        Create a new component directory with the given name and copy the necessary files.
        """

        # Ensure the component name is valid, otherwise ask user a new name
        if component_name == "":
            component_name = input("Enter the name of the new component: ").strip()

        if not component_name:
            logging.error("Invalid component name.")
            return False

        # Check if the component already exists
        if os.path.isdir(os.path.join(self._COMPONENT_ROOT_DIR, component_name)):
            logging.error(f"Component {component_name} already exists.")
            return False

        self._component_name = component_name
        self._component_dir  = os.path.join(self._COMPONENT_ROOT_DIR, self._component_name)

        os.mkdir(self._component_dir)

        # Copy template files
        shutil.copytree(os.path.join(self._CMAKE_COMPONENT_TEMPLATES_DIR, "include"),        os.path.join(self._component_dir, "include"))
        shutil.copyfile(os.path.join(self._CMAKE_COMPONENT_TEMPLATES_DIR, "CMakeLists.txt"), os.path.join(self._component_dir, "CMakeLists.txt"))
        shutil.copyfile(os.path.join(self._CMAKE_COMPONENT_TEMPLATES_DIR, "README.md"),      os.path.join(self._component_dir, "README.md"))

        if self._verbosity:
            logging.info(f"Created new component: {self._component_name}")

        return True


    def rename_component_files(self):
        """
        Rename the component files to match the new component name.
        """

        for root, _, files in os.walk(self._component_dir):
            for file in files:
                new_name = file.replace("component", self._component_name.lower()).replace("COMPONENT", self._component_name.upper())
                old_path = os.path.join(root, file)
                new_path = os.path.join(root, new_name)
                os.rename(old_path, new_path)

                if self._verbosity:
                    logging.info(f"Renamed {file} to {new_name}")


    def replace_component_file_content(self):
        """
        Replace the content inside the new component's files with the appropriate name.
        """

        for root, _, files in os.walk(self._component_dir):
            for file in files:
                file_path = os.path.join(root, file)

                with open(file_path, "r") as f:
                    content = f.read()

                new_content = content.replace("component", self._component_name.lower()).replace("COMPONENT", self._component_name.upper())

                with open(file_path, "w") as f:
                    f.write(new_content)

                if self._verbosity:
                    logging.info(f"Updated content in {file}")


    def add_component_to_kernel_cmake(self):
        """
        Add the new component to the kernel's CMake file.
        """

        try:
            with open(self._KERNEL_CMAKE_FILE, "r") as f:
                lines = f.readlines()

            for i, line in enumerate(lines):
                if line.strip() == "# Add the path to each component here":
                    lines.insert(i + 1, f"    \"{self._component_name}\"\n")
                    break

            with open(self._KERNEL_CMAKE_FILE, "w") as f:
                f.writelines(lines)

            if self._verbosity:
                logging.info(f"Added {self._component_name} to the kernel CMake file.")

        except FileNotFoundError:
            logging.error(f"Kernel CMake file not found at {self._KERNEL_CMAKE_FILE}.")


    def setup_component(self, component_name: str) -> None:
        """
        Setup the new component by creating the directory, renaming files, replacing content, and adding it to the kernel cmake.
        """

        if self.create_component_dir(component_name):
            self.rename_component_files()
            self.replace_component_file_content()
            self.add_component_to_kernel_cmake()

            logging.info(f"Setup complete for component: {self._component_name}")


if __name__ == "__main__":
    verbosity = True if str(sys.argv[1]) != "0" else False
    component = Component(verbosity)
    component.setup_component("")
