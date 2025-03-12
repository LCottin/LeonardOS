import os
import shutil
import logging
import sys

logging.basicConfig(level=logging.INFO, format="%(levelname)s: %(message)s")

class Executable:
    """
    Class to create a executable.
    """

    def __init__(self, verbosity: bool):
        """
        Initialize the binary name and directory.
        """
        self._binary_name = ""
        self._binary_dir  = ""
        self._verbosity   = verbosity

        self._BINARY_ROOT_DIR            = os.path.join(os.getcwd(), "dev/kernel")
        self._CMAKE_BINARY_TEMPLATES_DIR = "./tools/cmake_templates/binary"
        self._KERNEL_CMAKE_FILE          = os.path.join(self._BINARY_ROOT_DIR, "CMakeLists.txt")

        if self._verbosity:
            print(f"Binary root directory: {self._BINARY_ROOT_DIR}")


    def create_binary_dir(self, binary_name: str) -> bool:
        """
        Create a new binary directory with the given name and copy the necessary files.
        """

        # Ensure the binary name is valid, otherwise ask user a new name
        if binary_name == "":
            binary_name = input("Enter the name of the new binary: ").strip()

        if not binary_name:
            logging.error("Invalid binary name.")
            return False

        # Check if the binary already exists
        if os.path.isdir(os.path.join(self._BINARY_ROOT_DIR, binary_name)):
            logging.error(f"Binary {binary_name} already exists.")
            return False

        self._binary_name = binary_name
        self._binary_dir  = os.path.join(self._BINARY_ROOT_DIR, self._binary_name)

        os.mkdir(self._binary_dir)

        # Copy template files
        shutil.copyfile(os.path.join(self._CMAKE_BINARY_TEMPLATES_DIR, "linker.ld"),      os.path.join(self._binary_dir, "linker.ld"))
        shutil.copyfile(os.path.join(self._CMAKE_BINARY_TEMPLATES_DIR, "CMakeLists.txt"), os.path.join(self._binary_dir, "CMakeLists.txt"))
        shutil.copyfile(os.path.join(self._CMAKE_BINARY_TEMPLATES_DIR, "README.md"),      os.path.join(self._binary_dir, "README.md"))

        if self._verbosity:
            logging.info(f"Created new binary: {self._binary_name}")

        return True


    def replace_binary_file_content(self):
        """
        Replace the content inside the new binary's files with the appropriate name.
        """

        for root, _, files in os.walk(self._binary_dir):
            for file in files:
                file_path = os.path.join(root, file)

                with open(file_path, "r") as f:
                    content = f.read()

                new_content = content.replace("bin_name", self._binary_name.lower())

                with open(file_path, "w") as f:
                    f.write(new_content)

                if self._verbosity:
                    logging.info(f"Updated content in {file}")


    def add_binary_to_kernel_cmake(self):
        """
        Add the new binary to the kernel's CMake file.
        """

        try:
            with open(self._KERNEL_CMAKE_FILE, "r") as f:
                lines = f.readlines()

            for i, line in enumerate(lines):
                if line.strip() == "# Add the path to each component here":
                    lines.insert(i + 1, f"    \"{self._binary_name}\"\n")
                    break

            with open(self._KERNEL_CMAKE_FILE, "w") as f:
                f.writelines(lines)

            if self._verbosity:
                logging.info(f"Added {self._binary_name} to the kernel CMake file.")

        except FileNotFoundError:
            logging.error(f"Kernel CMake file not found at {self._KERNEL_CMAKE_FILE}.")


    def setup_binary(self, binary_name: str) -> None:
        """
        Setup the new binary by creating the directory, renaming files, replacing content, and adding it to the kernel.
        """

        if self.create_binary_dir(binary_name):
            self.replace_binary_file_content()
            self.add_binary_to_kernel_cmake()

            logging.info(f"Setup complete for binary: {self._binary_name}")


if __name__ == "__main__":
    verbosity  = True# if str(sys.argv[1]) != "0" else False
    executable = Executable(verbosity)
    executable.setup_binary("")
