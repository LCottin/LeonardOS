# OS Memory Map

The following table shows the memory mapping of the OS.

## Memory mapping overview

| Binary           | Type | Section     | Base Address | Size     | End Address | Description                     |
|------------------|------|-------------|--------------|----------|-------------|---------------------------------|
| Bootloader (ROM) | bin  |             |              |          |             | Bootloader binary               |
|                  |      | Text        | 0x0          | 0x1000   | 0xfff       |   Executable code               |
|                  |      | Data        | 0x1000       | 0x1000   | 0x1fff      |   Initialized data              |
|                  |      | BSS         | 0x2000       | 0x1000   | 0x2fff      |   Uninitialized data            |
|------------------|------|-------------|--------------|----------|-------------|---------------------------------|
| Kernel (ROM)     | elf  |             |              |          |             | Kernel binary                   |
|                  |      | Text        | 0x10000      | 0x1000   | 0x10fff     |   Executable code               |
|                  |      | Data        | 0x11000      | 0x1000   | 0x11fff     |   Initialized data              |
|                  |      | BSS         | 0x12000      | 0x1000   | 0x12fff     |   Uninitialized data            |
|------------------|------|-------------|--------------|----------|-------------|---------------------------------|
