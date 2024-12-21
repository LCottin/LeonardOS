# OS Memory Map

The following table shows the memory mapping of the OS.

## Memory mapping overview

| Binary           | Type | Section     | Base Address | Size     | End Address | Description                          |
|------------------|------|-------------|--------------|----------|-------------|--------------------------------------|
| Bootloader (ROM) | bin  |             |              |          |             | Bootloader binary                    |
|                  |      | Text        | 0x0          | 0x20000  | 0x1ffff     |   Executable code                    |
|                  |      | RO data     | 0x20000      | 0x10000  | 0x2ffff     |   Read only data                     |
|                  |      | Data        | 0x30000      | 0x10000  | 0x3ffff     |   Initialized data                   |
|------------------|------|-------------|--------------|----------|-------------|--------------------------------------|
| Kernel (ROM)     | elf  |             |              |          |             | Kernel elf                           |
|                  |      | Text        | 0x50000      | 0xC0000  | 0x10ffff    |   Executable code                    |
|                  |      | RO data     | 0x110000     | 0x10000  | 0x11ffff    |   Read only data                     |
|                  |      | Data        | 0x120000     | 0x20000  | 0x13ffff    |   Initialized data                   |
|------------------|------|-------------|--------------|----------|-------------|--------------------------------------|
| UART Registers   | io   |             |              |          |             | UART device for serial I/O           |
|                  |      | Registers   | 0x9000000    | 0x10000  | 0x900ffff   |   UART registers to print messages   |
|------------------|------|-------------|--------------|----------|-------------|--------------------------------------|
| Bootloader (RAM) | load |             |              |          |             | Bootloader loaded in ram             |
|                  |      | Data        | 0x40000000   | 0x8000   | 0x40007fff  |   Initialized data                   |
|                  |      | BSS         | 0x40008000   | 0x10000  | 0x40017fff  |   Uninitialized data                 |
|                  |      | Stack       | 0x40018000   | 0x10000  | 0x40027fff  |   Stack                              |
|------------------|------|-------------|--------------|----------|-------------|--------------------------------------|
| Kernel (RAM)     | load |             |              |          |             | Kernel loaded in ram                 |
|                  |      | Text        | 0x45000000   | 0x10000  | 0x4500ffff  |   Executable code                    |
|                  |      | RO data     | 0x45010000   | 0x40000  | 0x4504ffff  |   Read only data                     |
|                  |      | Data        | 0x45050000   | 0x40000  | 0x4508ffff  |   Initialized data                   |
|                  |      | BSS         | 0x45090000   | 0x40000  | 0x450cffff  |   Uninitialized data                 |
|                  |      | Stack       | 0x450d0000   | 0x10000  | 0x450dffff  |   Stack                              |
|                  |      | Heap        | 0x450e0000   | 0x10000  | 0x450effff  |   Heap                               |
|------------------|------|-------------|--------------|----------|-------------|--------------------------------------|
