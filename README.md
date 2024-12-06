# Pipex - Unix Pipe Simulation

**Pipex** is a system programming project that simulates Unix pipe mechanisms, helping developers understand process creation, file descriptors, and command execution.

## 🚀 Project Overview

Pipex recreates the behavior of shell command piping, allowing you to connect the output of one command as input to another, mimicking the `|` operator in Unix-like systems.

## 🛠️ Features

### Command Execution
- Execute two shell commands with their parameters.
- Redirect input and output between commands using pipes.
- Handle file input and output seamlessly.

### Example Usage
```bash
# List files and count lines
./pipex infile "ls -l" "wc -l" outfile
# Equivalent to: < infile ls -l | wc -l > outfile

# Filter and count words
./pipex infile "grep a1" "wc -w" outfile
# Equivalent to: < infile grep a1 | wc -w > outfile
```

### Bonus Features
- Support for multiple pipe commands
- Handling `here_doc` with input redirection

## 🔧 How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/pleiadeslol/42_pipex.git
   cd 42_pipex
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the program:
   ```bash
   ./42_pipex file1 cmd1 cmd2 file2
   ```

### Bonus Execution
```bash
# Multiple commands
./42_pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

# Here document
./42_pipex here_doc LIMITER cmd cmd1 file
```

## 📋 Requirements

### Mandatory Constraints
- Written in C
- Follows the Norm (coding standards)
- No memory leaks
- Robust error handling
- Compiled with `-Wall -Wextra -Werror`

### Allowed External Functions
- File operations: `open`, `close`, `read`, `write`
- Memory management: `malloc`, `free`
- Process control: `fork`, `pipe`, `execve`
- Error handling: `perror`, `strerror`
- Other: `dup`, `dup2`, `access`, `unlink`, `wait`, `waitpid`

## 🧪 Testing
- Create test cases with various command combinations
- Verify input and output file handling
- Test error scenarios and edge cases
- Validate memory management

## Make Commands
- `make`: Compile the project
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Recompile the project

---

Enjoy exploring system programming! 🖥️
