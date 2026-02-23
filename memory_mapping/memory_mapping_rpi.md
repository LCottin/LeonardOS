# OS Memory Map

The following table shows the memory mapping of the OS.

## Memory mapping overview

|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| Binary                   | Type            | Section     | Base Address | Size       | End Address | Description                          |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| Bootloader (entry point) | elf             |             |              |            |             | OS entry point                       |
|                          |                 | Code        | 0x00080000   | 0x00080000 | 0x000fffff  |   Executable code and read only data |
|                          |                 | Data        | 0x00100000   | 0x00080000 | 0x0017ffff  |   Initialized and uninitialized data |
|                          |                 | Stack       | 0x00180000   | 0x00010000 | 0x0018ffff  |   Stack                              |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| Kernel (ROM)             | elf             |             |              |            |             | Kernel elf                           |
|                          |                 | Header      | 0x00090000   | 0x00001000 | 0x00090fff  |   ELF header                         |
|                          |                 | Metadata    | 0x00091000   | 0x00010000 | 0x000a0fff  |   Store binary symbols               |
|                          |                 | Code        | 0x000a1000   | 0x00080000 | 0x00120fff  |   Executable code and read only data |
|                          |                 | Data        | 0x00121000   | 0x00080000 | 0x001a0fff  |   Initialized and uninitialized data |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| APP_1 (ROM)              | elf             |             |              |            |             | App elf                              |
|                          |                 | Header      | 0x00300000   | 0x00001000 | 0x00300fff  |   ELF header                         |
|                          |                 | Metadata    | 0x00301000   | 0x00001000 | 0x00301fff  |   Store binary symbols               |
|                          |                 | Code        | 0x00302000   | 0x00008000 | 0x00309fff  |   Executable code and read only data |
|                          |                 | Data        | 0x0030a000   | 0x00008000 | 0x00311fff  |   Initialized and uninitialized data |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| APP_2 (ROM)              | elf             |             |              |            |             | App elf                              |
|                          |                 | Header      | 0x00320000   | 0x00001000 | 0x00320fff  |   ELF header                         |
|                          |                 | Metadata    | 0x00321000   | 0x00001000 | 0x00321fff  |   Store binary symbols               |
|                          |                 | Code        | 0x00322000   | 0x00008000 | 0x00329fff  |   Executable code and read only data |
|                          |                 | Data        | 0x0032a000   | 0x00008000 | 0x00331fff  |   Initialized and uninitialized data |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| BMT                      | global variable |             |              |            |             | Binary Metadata Table                |
|                          |                 | BMT         | 0x00500000   | 0x00010000 | 0x0050ffff  |   Binary Metadata Table Address      |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| IVT                      | global variable |             |              |            |             | Interrupt Vector Table               |
|                          |                 | IVT         | 0x00600000   | 0x00010000 | 0x0060ffff  |   Interrupt Vector Table Address     |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| SCH                      | global variable |             |              |            |             | Scheduler Table                      |
|                          |                 | SCH         | 0x00700000   | 0x00010000 | 0x0070ffff  |   Scheduler Table Address            |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| Kernel (RAM)             | loaded          |             |              |            |             | Kernel loaded in ram                 |
|                          |                 | Code        | 0x01000000   | 0x00080000 | 0x0107ffff  |   Executable code and read only data |
|                          |                 | Data        | 0x01080000   | 0x00080000 | 0x010fffff  |   Initialized and uninitialized data |
|                          |                 | Stack       | 0x01100000   | 0x00010000 | 0x0110ffff  |   Stack                              |
|                          |                 | Guard       | 0x01110000   | 0x00010000 | 0x0111ffff  |   Protection against stack overflow  |
|                          |                 | Heap        | 0x01120000   | 0x00010000 | 0x0112ffff  |   Heap                               |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| APP_1 (RAM)              | loaded          |             |              |            |             | App loaded in ram                    |
|                          |                 | Code        | 0x01200000   | 0x00008000 | 0x01207fff  |   Executable code and read only data |
|                          |                 | Data        | 0x01208000   | 0x00008000 | 0x0120ffff  |   Initialized and uninitialized data |
|                          |                 | Stack       | 0x01210000   | 0x00001000 | 0x01210fff  |   Stack                              |
|                          |                 | Guard       | 0x01211000   | 0x00001000 | 0x01211fff  |   Protection against stack overflow  |
|                          |                 | Heap        | 0x01212000   | 0x00001000 | 0x01212fff  |   Heap                               |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| APP_2 (RAM)              | loaded          |             |              |            |             | App loaded in ram                    |
|                          |                 | Code        | 0x01300000   | 0x00008000 | 0x01307fff  |   Executable code and read only data |
|                          |                 | Data        | 0x01308000   | 0x00008000 | 0x0130ffff  |   Initialized and uninitialized data |
|                          |                 | Stack       | 0x01310000   | 0x00001000 | 0x01310fff  |   Stack                              |
|                          |                 | Guard       | 0x01311000   | 0x00001000 | 0x01311fff  |   Protection against stack overflow  |
|                          |                 | Heap        | 0x01312000   | 0x00001000 | 0x01312fff  |   Heap                               |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
| UART                     | io              |             |              |            |             | UART device for serial I/O           |
|                          |                 | Registers   | 0x3f201000   | 0x00010000 | 0x3f210fff  |   UART registers to print messages   |
|--------------------------|-----------------|-------------|--------------|------------|-------------|--------------------------------------|
