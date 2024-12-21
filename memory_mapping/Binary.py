import os
from Section import Section

class Binary:
    """
    Represents a binary file with multiple sections.
    """

    def __init__(self, name: str, type: str = "elf", description: str = "", base_address: str = "0x00000000", sections: list = None) -> None:
        self.name         = name
        self.type         = type
        self.description  = description
        self.base_address = base_address
        self.sections     = [Section(**section) for section in (sections or [])]


    """ Compute the base addresses of the sections. """
    def compute_base_addresses(self) -> None:
        current_address = int(self.base_address, 16)

        for section in self.sections:
            if not section.base_address:
                section.base_address = hex(current_address)
            current_address = int(section.compute_end_address(), 16)


    """ Check for overlaps between sections. """
    def check_for_overlaps(self) -> None:
        sorted_sections = sorted(self.sections, key=lambda s: int(s.base_address, 16))

        for idx in range(len(sorted_sections) - 1):
            current_end = int(sorted_sections[idx].compute_end_address(), 16)
            next_base = int(sorted_sections[idx + 1].base_address, 16)
            if current_end > next_base:
                raise ValueError(f"Sections overlap: {sorted_sections[idx].name} and {sorted_sections[idx + 1].name}")
