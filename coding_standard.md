# Coding standard

## General guidelines

- Naming Conventions: The naming of files, variables, functions, and constants should be consistent and meaningful to ensure clarity and avoid ambiguity.
- Minimalism: Strive for simplicity and avoid unnecessary complexity in function and variable definitions. Keep structures and code optimized for memory and performance.

## File naming conventions

### Source files

Use lowercase letters with words separated by underscores (_), e.g., memory_manager.c, main_loop.c.

### Header files

Similarly, header files should use lowercase letters with underscores, e.g., memory_manager.h, utils.h.

### File extensions

Source files should end in .c and header files in .h.

Avoid Special Characters: Avoid using special characters (other than underscores) in file names to ensure portability.

## Naming conventions for code elements

### Functions

Function names should be clear, descriptive, and indicate the function's purpose.

### Variables

- Unit Representation: Variables representing specific units (e.g., time, size) should include the unit in their names, e.g., time_ms, size_kb.
- Local Variables: Local variables should be named using lowercase letters with words separated by underscores, e.g., total_count.
- Pointers: The **\*** symbol should be placed next to the variable name, e.g., int *ptr.
- Global Variables: Prefix global variables with **g_** to differentiate them, e.g., g_total_count.

### Constants and Macros

- Constants and Enums: Declare global constants and enumeration labels in uppercase with words separated by underscores, e.g., MAX_BUFFER_SIZE.
- Macros: Use uppercase with underscores and ensure parentheses around arguments, e.g., #define SQUARE(x) ((x) * (x)).

### Use of provided types

Standard and Custom Types: Always use the provided types (such as those defined in system headers or the project's type definitions). For example:
Use size_t for sizes, lengths, and memory addresses.
Use custom types like int32_t, uint32_t, etc., as defined in the project's types.h or similar files.
Avoid mixing primitive types like int, long, or unsigned unless absolutely necessary. Always prefer the provided types for portability and consistency.

Type Safety: Prefer using enum and typedef for type safety and clarity instead of raw integer values or #define.
Typedef Naming: When creating new types with typedef, the type name should end with the **_t** suffix, e.g., typedef uint32_t size_t_t;.

## Code formatting conventions

- Braces: Opening and closing braces should be placed on their own line.
- Else Statements: else conditions should start on a new line for better readability.
- Switch Statements: Always use braces for case blocks, include all possible cases, and provide a default case.
- Goto, Continue, and Break: Minimize the use of goto, continue, and break statements for cleaner control flow.

## Best practices

- Prefer Enumerations to Defines: Use enum to represent constant values rather than #define, as this improves type safety and clarity.
- Avoid Code Duplication: Always strive for code reusability and abstraction to reduce repetition.

## Error handling

### Error checking

Always check the return values of functions that can fail (e.g., memory allocation, file handling, system calls). Handle errors appropriately, either by returning a specific error code or printing a message to the console.

### Error codes

When using error codes, define them as constants with meaningful names, e.g., ERROR_FILE_NOT_FOUND, and ensure they are easily distinguishable from regular values.

## Comments and documentation

### Code comments

Use comments to explain why certain decisions are made in the code, especially for complex or non-obvious logic. Avoid obvious comments like // increment i by 1 when it’s self-explanatory.

### Function documentation

Every function should have a comment above it describing:

- The function’s purpose.
- Parameters (with types and descriptions).
- Return value (if any).
- Any side effects (e.g., modifies global variables).
- Inline Comments: Use inline comments sparingly and only when the logic is not immediately clear.

## Memory management

### Memory allocation and de-allocation

Ensure that memory allocated dynamically is always freed. If there are any complex memory management scenarios (e.g., custom allocators), document them thoroughly.
Avoid Memory Leaks: Use static analysis tools (e.g., valgrind) to check for memory leaks or dangling pointers during development.
