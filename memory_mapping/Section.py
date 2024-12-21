class Section:
    """
    Represents a section of a binary file.
    """

    def __init__(self, name:str, size:str, description:str) -> None:
        self._name         = name
        self._size         = size
        self._description  = description
        self._base_address = ""


    def get_name(self) -> str:
        return self._name


    def get_size(self) -> str:
        return self._size


    def get_description(self) -> str:
        return self._description


    def get_base_address(self) -> str:
        return self._base_address


    def set_base_address(self, value:str) -> None:
        self._base_address = value


    """ Compute the end address of the section. """
    def compute_end_address(self) -> hex:
        if not self._base_address:
            raise ValueError("Base address is not set for the section.")

        try:
            base_address = int(self._base_address, 16)
            size         = int(self._size, 16)
        except ValueError:
            raise ValueError(f"Invalid base address ({self._base_address}) or size ({self._size}). Both must be valid hexadecimal values.")

        return hex(base_address + size - 1)
