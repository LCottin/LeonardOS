import os
from Section import Section

class Binary:
    """
    Represents a binary file with multiple sections.
    """

    def __init__(self, name: str, bin_type: str, description: str, base_address: str, sections: list = None) -> None:
        self._name         = name
        self._type         = bin_type
        self._description  = description
        self._base_address = base_address
        self._sections     = [Section(**section) for section in (sections or [])]


    def get_name(self) -> str:
        return self._name


    def get_type(self) -> str:
        return self._type


    def get_description(self) -> str:
        return self._description


    def get_base_address(self) -> str:
        return self._base_address


    def get_sections(self) -> list:
        return self._sections


    """ Compute the base addresses of the sections. """
    def compute_base_addresses(self) -> None:
        current_address = int(self._base_address, 16)

        for section in self._sections:
            if section.get_base_address() == "":
                section.set_base_address(str(hex(current_address)))
            current_address = int(section.compute_end_address(), 16) + 1


    """ Check for overlaps between sections. """
    def check_for_overlaps(self) -> None:
        sorted_sections = sorted(self._sections, key=lambda s: int(s.get_base_address(), 16))
        sorted_sections = self._sections

        for idx in range(len(sorted_sections) - 1):
            current_end = int(sorted_sections[idx].compute_end_address(), 16)
            next_base   = int(sorted_sections[idx + 1].get_base_address(), 16)

            if current_end > next_base:
                raise ValueError(f"Sections overlap: {sorted_sections[idx].get_name()} and {sorted_sections[idx + 1].get_name()}")
