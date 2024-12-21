from Binary import Binary
from Section import Section
import json

class Memory_Table:
    """
    Represents a memory table with multiple binaries.
    """

    def __init__(self, input_file, output_file):
        self._binaries    = []
        self._markdown    = ""
        self._input_file  = input_file
        self._output_file = output_file

        self._markdown += "# OS Memory Map\n\n"
        self._markdown += "The following table shows the memory mapping of the OS.\n\n"


    """ Read the input file and create the binaries. """
    def read_input_file(self) -> None:
        with open(self._input_file, "r") as f:
            memory_map = json.load(f)

        for binary in memory_map.values():
            self._binaries.append(Binary(binary["name"],
                                         binary["type"],
                                         binary["description"],
                                         binary["base_address"],
                                         binary["sections"]))

        self._binaries = sorted(self._binaries, key=lambda b: int(b.get_base_address(), 16))


    """ Generate the memory map and write it to the output file. """
    def write_memory_map(self) -> None:
        with open(self._output_file, "w") as f:
            f.write(self._markdown)


    """ Generate an overview table of the sections in the binaries. """
    def generate_overview_table(self) -> str:
        self._markdown += "## Memory mapping overview\n\n"
        self._markdown += f"| Binary           | Type | Section     | Base Address | Size     | End Address | Description                          |\n"
        self._markdown += f"|------------------|------|-------------|--------------|----------|-------------|--------------------------------------|\n"

        for binary in self._binaries:
            self._markdown += (f"| {binary.get_name():<16} | {binary.get_type():<4} |             |              |          |             | {binary.get_description():<36} |\n")
            binary.compute_base_addresses()
            binary.check_for_overlaps()

            for section in binary.get_sections():
                end_address     = section.compute_end_address()
                self._markdown += (f"|                  |      | {section.get_name():<11} | {section.get_base_address():<12} | {section.get_size():<8} | {end_address:<11} |   {section.get_description():<34} |\n")

            self._markdown += f"|------------------|------|-------------|--------------|----------|-------------|--------------------------------------|\n"
