# Notes on how to use the LLDB

# Process
1. vim ____
2. Compile with debugging symbols
- Normal Compilation: gcc <file_name>
- Compilation with LLDB: gcc -g <file_name>
- Running the Programme with LLDB: lldb ./a.out
- Enter: target create ./a.out
- Enter: b mainc
- Enter: run
- Enter: gui

# Features
- In GUI
- - Diamonds mean that they can be expanded with right arrow when in the variables tab
- - "n" key means next line in execution
- - "s" key means step in
- - "F5" to access the registers tab

- Other Commands
- - "bt" for backtrace
- - "q" for quit
