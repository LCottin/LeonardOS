# LeonardOS

## Overview

This project is a bare-metal operating system developed from scratch, aimed at running on ARM64 architecture and simulated on QEMU. The OS is designed to be lightweight and modular while providing core functionalities such as memory management, process control, and a command-line interface (CLI) for user applications.

## Development goals

### Learn and implement core OS concepts

From kernel design and memory management to process scheduling and file systems.

### Build a functional and scalable OS

The OS should be capable of running user applications and providing a foundational environment for further expansion.

### To get started with building and testing the OS

1. Set up QEMU: Configure QEMU for ARM64 to simulate the OS on an ARM Cortex-A53 core.
2. Compile the OS using CMake and generate a bootable image.
3. Load the compiled image into QEMU and run to test core functionalities.

## Coding Standard

To ensure consistency and clarity throughout this development, I aim to follow this coding standard.
See [Coding standard](coding_standard.md).

## Prerequisites

In order to compile, run and debug the project, you may need to install dependencies yourself:
 1. wget https://ftp.gnu.org/gnu/binutils/binutils-2.41.tar.gz
 2. tar -xzf binutils-2.41.tar.gz
 3. mkdir build
 4. cd build
 5. ../binutils-2.41/configure --target=aarch64-none-elf --disable-werror --enable-gdb
 6. make
 7. sudo make install

## License

This repository is under the [MIT License](https://opensource.org/licenses/MIT).

Copyright (c) 2024 LCottin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
