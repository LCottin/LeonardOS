import yaml
import os
import subprocess
import sys

def main(list_test:str, build_dir:str, pre_image_path:str) -> None:
    """
    Build an image for each test found in configuration file
    """

    # Load list of test with their path from tests.yaml
    with open(list_test, "r") as f:
        tests = yaml.safe_load(f)["tests_list"]

    # Compile each test and store the output in the build directory
    for test in tests:
        try:
            # Create output directory
            os.makedirs(os.path.join(build_dir, test["name"]), exist_ok=True)

            # Build the image
            bin_path = os.path.join(os.path.join(build_dir, test["name"]), f"{test["name"]}.elf")
            img_path = os.path.join(os.path.join(build_dir, test["name"]), f"{test["name"]}.img")

            if os.path.exists(img_path):
                subprocess.run([f"rm -f {img_path}"], shell=True)

            subprocess.run([f"cp {pre_image_path} {img_path}"], shell=True)
            subprocess.run([f"dd if={bin_path} of={img_path} bs=1 seek=7340032 conv=notrunc"], shell=True)

        except Exception as e:
            print(f"Failed to build image for test {test['name']}: {e}")

    return

if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2], sys.argv[3])
