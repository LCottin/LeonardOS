import os
import shutil
import logging
import sys

logging.basicConfig(level=logging.INFO, format="%(levelname)s: %(message)s")

class Application:
    """
    Class to create a new application for users.
    """

    def __init__(self, verbosity: bool):
        """
        Initialize the component name and directory.
        """
        self._component_name = ""
        self._component_dir  = ""
        self._verbosity      = verbosity

        self._APPLICATION_ROOT_DIR            = os.path.join(os.getcwd(), "dev/user")
        self._CMAKE_APPLICATION_TEMPLATES_DIR = "./tools/cmake_templates/application"
        self._USER_CMAKE_FILE                 = os.path.join(self._APPLICATION_ROOT_DIR, "CMakeLists.txt")

        if self._verbosity:
            print(f"Application root directory: {self._APPLICATION_ROOT_DIR}")


    def create_application_dir(self, application_name: str) -> bool:
        """
        Create a new application directory with the given name and copy the necessary files.
        """

        # Ensure the application name is valid, otherwise ask user a new name
        if application_name == "":
            application_name = input("Enter the name of the new application: ").strip()

        if not application_name:
            logging.error("Invalid application name.")
            return False

        # Check if the application already exists
        if os.path.isdir(os.path.join(self._APPLICATION_ROOT_DIR, application_name)):
            logging.error(f"Application {application_name} already exists.")
            return False

        self._application_name = application_name
        self._application_dir  = os.path.join(self._APPLICATION_ROOT_DIR, self._application_name)

        os.mkdir(self._application_dir)

        # Copy template files
        shutil.copytree(os.path.join(self._CMAKE_APPLICATION_TEMPLATES_DIR, "include"),        os.path.join(self._application_dir, "include"))
        shutil.copytree(os.path.join(self._CMAKE_APPLICATION_TEMPLATES_DIR, "src"),        os.path.join(self._application_dir, "src"))
        shutil.copyfile(os.path.join(self._CMAKE_APPLICATION_TEMPLATES_DIR, "linker.ld"),      os.path.join(self._application_dir, "linker.ld"))
        shutil.copyfile(os.path.join(self._CMAKE_APPLICATION_TEMPLATES_DIR, "CMakeLists.txt"), os.path.join(self._application_dir, "CMakeLists.txt"))
        shutil.copyfile(os.path.join(self._CMAKE_APPLICATION_TEMPLATES_DIR, "README.md"),      os.path.join(self._application_dir, "README.md"))

        if self._verbosity:
            logging.info(f"Created new application: {self._application_name}")

        return True


    def rename_application_files(self):
        """
        Rename the application files to match the new component name.
        """

        for root, _, files in os.walk(self._application_dir):
            for file in files:
                new_name = file.replace("appli", self._application_name.lower()).replace("APPLI", self._application_name.upper())
                old_path = os.path.join(root, file)
                new_path = os.path.join(root, new_name)
                os.rename(old_path, new_path)

                if self._verbosity:
                    logging.info(f"Renamed {file} to {new_name}")


    def replace_application_file_content(self):
        """
        Replace the content inside the new application's files with the appropriate name.
        """

        for root, _, files in os.walk(self._application_dir):
            for file in files:
                file_path = os.path.join(root, file)

                with open(file_path, "r") as f:
                    content = f.read()

                new_content = content.replace("appli_name", self._application_name.lower()).replace("appli", self._application_name.lower()).replace("APPLI", self._application_name.upper())

                with open(file_path, "w") as f:
                    f.write(new_content)

                if self._verbosity:
                    logging.info(f"Updated content in {file}")


    def add_application_to_user_cmake(self):
        """
        Add the new application to the user's CMake file.
        """

        try:
            with open(self._USER_CMAKE_FILE, "r") as f:
                lines = f.readlines()

            for i, line in enumerate(lines):
                if line.strip() == "# Add the path to each application here":
                    lines.insert(i + 1, f"    \"{self._application_name}\"\n")
                    break

            with open(self._USER_CMAKE_FILE, "w") as f:
                f.writelines(lines)

            if self._verbosity:
                logging.info(f"Added {self._application_name} to the kernel CMake file.")

        except FileNotFoundError:
            logging.error(f"Kernel CMake file not found at {self._USER_CMAKE_FILE}.")


    def setup_application(self, application_name: str) -> None:
        """
        Setup the new application by creating the directory, renaming files, replacing content, and adding it to the user cmake.
        """

        if self.create_application_dir(application_name):
            self.rename_application_files()
            self.replace_application_file_content()
            self.add_application_to_user_cmake()

            logging.info(f"Setup complete for application: {self._application_name}")


if __name__ == "__main__":
    verbosity = True if str(sys.argv[1]) != "0" else False
    application = Application(verbosity)
    application.setup_application("")
