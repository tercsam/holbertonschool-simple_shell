# Holberton Simple Shell

## Overview
This is a basic shell program implemented in the C programming language. The shell provides a simple command-line interface where users can input commands for execution. The program continuously reads user inputs, parses them, and executes the corresponding commands.

## Features
- User-friendly command-line interface.
- Supports basic shell commands.
- Executes external commands by searching the directories in the PATH.

## How to Use
1. Compile the program using a C compiler (e.g., gcc).
    ```bash
    gcc -o simple_shell main.c
    ```

2. Run the compiled executable.
    ```bash
    ./simple_shell
    ```

3. The shell prompt `($)` will appear, prompting you to enter commands.

4. Enter commands and press Enter to execute them.
    - To exit the shell, type `exit`.
    - To display the current environment, type `env`.

## File Structure
- `main.c`: Contains the main logic of the shell program.
- `main.h`: Header file with function declarations and necessary includes.

## Dependencies
- The program uses standard C libraries and system calls.

## Known Issues
- Limited error handling and input validation.
- May not handle complex commands or features present in advanced shells.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments
- This shell program is a simple educational project and may not cover all edge cases or security considerations.
- It is recommended for learning purposes and not intended for production use.
