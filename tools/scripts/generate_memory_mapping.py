from Binary import Binary
from Section import Section
from Memory_Table import Memory_Table

""" Generate a memory map from an input file and write it to an output file. """
def main(input_file: str, output_file: str) -> None:
    memory_table = Memory_Table(input_file, output_file)

    memory_table.read_input_file()

    memory_table.generate_overview_table()

    memory_table.write_memory_map()

if __name__ == "__main__":
    input_file  = "memory_mapping/binaries_sections.json"
    output_file = "memory_mapping/memory_mapping.md"

    main(input_file, output_file)
