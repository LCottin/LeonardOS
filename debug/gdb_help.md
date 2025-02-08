# GDB Cheat Sheet & Basic Configuration

A quick reference guide for using GDB (GNU Debugger) with common commands, basic configuration tips, and instructions on launching GDB with scripts.

---

## Contents
- [GDB Cheat Sheet \& Basic Configuration](#gdb-cheat-sheet--basic-configuration)
  - [Contents](#contents)
  - [1. Starting and Exiting GDB](#1-starting-and-exiting-gdb)
  - [2. Running the Program and Loading Files](#2-running-the-program-and-loading-files)
  - [3. Breakpoints and Stepping Through Code](#3-breakpoints-and-stepping-through-code)
  - [4. Examining Code and Variables](#4-examining-code-and-variables)
  - [5. Printing Structures](#5-printing-structures)
  - [6. Managing Program State \& Debugging Assembly](#6-managing-program-state--debugging-assembly)
  - [7. Watchpoints and Logging](#7-watchpoints-and-logging)
  - [8. Miscellaneous Commands](#8-miscellaneous-commands)

## 1. Starting and Exiting GDB

```bash
# Start GDB with a program:
gdb <program>

# Start GDB with a core file:
gdb <program> <core-file>

# Start GDB with program arguments:
gdb --args <program> <arg1> <arg2> ...

# Run a startup script:
gdb -x <script-file>

# Disable auto-loading .gdbinit:
gdb -nx

# Exit GDB:
quit
```

## 2. Running the Program and Loading Files

```bash
# Run the program with optional arguments:
run [args]          # Example: run input.txt

# Restart the program:
start

# Load a program file (manually):
file <program>      # Example: file my_program

# Load symbols from another file:
symbol-file <file>  # Example: symbol-file my_symbols

# Load a core file:
core <core-file>    # Example: core corefile.dump
```

## 3. Breakpoints and Stepping Through Code

```bash
# Set a breakpoint:
break <location>    # Examples: break main, break file.c:10, break *0x123456

# Delete a breakpoint:
delete <breakpoint-number>

# List all breakpoints:
info breakpoints

# Enable/Disable a breakpoint:
enable <breakpoint-number>
disable <breakpoint-number>

# Step into functions (line by line):
step

# Step over functions:
next

# Continue until the next breakpoint:
continue

# Step out of the current function:
finish
```

## 4. Examining Code and Variables

```bash
# List source code:
list [location]     # Examples: list, list 10, list main

# Show the current line:
frame

# Print the value of a variable:
print <variable>    # Example: print x

# Display a variable on every step:
display <variable>

# Stop displaying a variable:
undisplay <display-number>

# Examine memory:
x/<format> <address>  # Examples: x/4xw 0x123456, x/s <address>
```

## 5. Printing Structures

```bash
# Print the entire structure:
print <struct_variable>
# Example:
# struct Point { int x; int y; };
# struct Point p = {3, 4};
# Output: $1 = {x = 3, y = 4}

# Access specific fields:
print <struct_variable>.<field>    # Example: print p.x

# Dereference pointers to structures:
print *<struct_pointer>             # Example: print *ptr

# Inspect a structure in memory:
x/<format> <address>                # Example: x/4xw &p

# Pretty-print large structures:
set print pretty on
print <struct_variable>
```

## 6. Managing Program State & Debugging Assembly

```bash
# Show the current stack:
backtrace

# Move to a specific stack frame:
frame <frame-number>

# Set a variable's value:
set <variable> = <value>   # Example: set x = 42

# Disassemble a function:
disassemble <function>

# Step one instruction:
stepi

# Next instruction (skip function calls):
nexti
```

## 7. Watchpoints and Logging

```bash
# Set a watchpoint (monitor variable):
watch <variable>

# Set a read-only watchpoint:
rwatch <variable>

# Set an access watchpoint:
awatch <variable>

# Delete a watchpoint:
delete <watchpoint-number>

# Redirect GDB output to a file:
set logging on

# Turn off logging:
set logging off
```

## 8. Miscellaneous Commands

```bash
# Check registers:
info registers

# Check threads:
info threads

# Switch to a thread:
thread <thread-number>

# Attach to a running process:
attach <pid>

# Detach from a process:
detach
```
