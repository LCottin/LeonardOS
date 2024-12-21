class Section:
    """
    Represents a section of a binary file.
    """

    def __init__(self, name, size, description, base_address=None) -> None:
        self.name         = name
        self.size         = size
        self.description  = description
        self.base_address = base_address


    """ Compute the end address of the section. """
    def compute_end_address(self) -> hex:
        if not self.base_address:
            raise ValueError("Base address is not set for the section.")

        return hex(int(self.base_address, 16) + int(self.size, 16))
