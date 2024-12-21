# OS Memory Map

The following table shows the memory map of the OS.

## Memory map overview

| Binary           | Type | Section     | Base Address | Size   | End Address | Description                   |
|------------------|------|-------------|--------------|--------|-------------|-------------------------------|
| Bootloader (ROM) | bin  |             |              |        |             | Bootloader binary             |
|                  |      | Text        | 0x0          | 0x1000 | 0x1000      | Executable code               |
|                  |      | Data        | 0x1000       | 0x1000 | 0x2000      | Initialized data              |
|                  |      | BSS         | 0x2000       | 0x1000 | 0x3000      | Uninitialized data            |
| Kernel (ROM)     | elf  |             |              |        |             | Kernel binary                 |
|                  |      | Text        | 0x10000      | 0x1000 | 0x11000     | Executable code               |
|                  |      | Data        | 0x11000      | 0x1000 | 0x12000     | Initialized data              |
|                  |      | BSS         | 0x12000      | 0x1000 | 0x13000     | Uninitialized data            |
