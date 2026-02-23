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
    QEMU = {'input': "memory_mapping/binaries_sections_qemu.json", 'output': "memory_mapping/memory_mapping_qemu.md"}
    RPI  = {'input': "memory_mapping/binaries_sections_rpi.json",  'output': "memory_mapping/memory_mapping_rpi.md"}

    # Generate memory mapping for both QEMU and Raspberry Pi configurations
    configs = [QEMU, RPI]
    for config in configs:
        main(config['input'], config['output'])
