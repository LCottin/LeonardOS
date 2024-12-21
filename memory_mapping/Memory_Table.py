from Binary import Binary
from Section import Section
import json

class Memory_Table:
    """
    Represents a memory table with multiple binaries.
    """

    def __init__(self, input_file, output_file):
        self.binaries    = []
        self.markdown    = ""
        self.input_file  = input_file
        self.output_file = output_file

        self.markdown += "# OS Memory Map\n\n"
        self.markdown += "The following table shows the memory map of the OS.\n\n"


    """ Read the input file and create the binaries. """
    def read_input_file(self) -> None:
        with open(self.input_file, "r") as f:
            memory_map = json.load(f)

        for binary in memory_map.values():
            self.binaries.append(Binary(binary["name"],
                                        binary["type"],
                                        binary["description"],
                                        binary["base_address"],
                                        binary["sections"]))


    """ Generate the memory map and write it to the output file. """
    def write_memory_map(self) -> None:
        with open(self.output_file, "w") as f:
            f.write(self.markdown)


    """ Generate an overview table of the sections in the binaries. """
    def generate_overview_table(self) -> str:
        self.markdown += "## Memory map overview\n\n"
        self.markdown += f"| Binary           | Type | Section     | Base Address | Size   | End Address | Description                   |\n"
        self.markdown += f"|------------------|------|-------------|--------------|--------|-------------|-------------------------------|\n"

        for binary in self.binaries:
            self.markdown += (f"| {binary.name:<16} | {binary.type:<3}  |             |              |        |             | {binary.description:<29} |\n")
            binary.compute_base_addresses()
            binary.check_for_overlaps()

            for section in binary.sections:
                end_address  = section.compute_end_address()
                self.markdown       += (f"|                  |      | {section.name:<11} | {section.base_address:<12} | {section.size:<6} | {end_address:<11} | {section.description:<29} |\n")

        return self.markdown
