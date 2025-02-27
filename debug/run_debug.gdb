# Connect to target
target remote localhost:1234

# Set a readable prompt and disable pagination
set prompt (gdb) >

# Enable pretty-printing for structures and improve output formatting
set print pretty on

# Load breakpoints from an external script
source debug/breakpoints.gdb

# Enable source code view
focus cmd
