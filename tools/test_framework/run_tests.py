import yaml
import os
import subprocess
import sys

def main(list_test:str, build_dir:str, boot_bin:str) -> None:
    """
    Run test for each test in the list
    """

    # Load list of test with their path from tests.yaml
    with open(list_test, "r") as f:
        tests = yaml.safe_load(f)["tests_list"]

    # Compile each test and store the output in the build directory
    for test in tests:
        try:
            # Launch test
            test_path = os.path.join(os.path.join(build_dir, test["name"]), f"{test["name"]}.img")
            print(f"boot bin = {boot_bin}")
            print(f"Test path: {test_path}")
            output = subprocess.check_output([f"qemu-system-aarch64", f"-M", f"virt", f"-m", f"512M", f"-cpu", f"cortex-a53", f"-nographic", f"-kernel", f"{boot_bin}", f"-serial", f"mon:stdio", f"-device", f"loader,file={test_path},addr=0x0", f"-no-reboot"],
                                            #   shell=True,
                                              timeout = 10).decode()

            print(output)

        except Exception as e:
            print(f"Failed to run test {test['name']}: {e}")

    return

if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2], sys.argv[3])
