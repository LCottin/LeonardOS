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
 2. sudo tar -xzf binutils-2.41.tar.gz
 3. mkdir build
 4. cd build
 5. sudo ../binutils-2.41/configure --target=aarch64-none-elf --disable-werror --enable-gdb
 6. sudo make
 7. sudo make install

## License

This repository is under the [MIT License](https://opensource.org/licenses/MIT).
See [license](LICENSE).
