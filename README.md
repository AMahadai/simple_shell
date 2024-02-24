# Simple Shell Project

## Description
This project is a simple UNIX command interpreter based on the shell. It's a collaborative project implemented in C, designed to mimic basic functionalities of the traditional UNIX shell. It handles command execution, environmental variables, and built-in commands with a focus on the fundamentals of system programming.

## Installation
To use this shell, clone this repository to your local machine using the following command:

```
git clone [https://github.com/AMahadai/simple_shell]
```

## Compilation
Compile the program using:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage
To start the shell in interactive mode, simply run:

```
./hsh
```

In non-interactive mode, echo your command and pipe it into the shell like this:

```
echo "/bin/ls" | ./hsh
```

## Features
- Displays a prompt and waits for the user to type a command.
- Executes commands typed into the prompt.
- Handles command line arguments.
- Searches for executables in the user's PATH.
- Includes built-in commands: `exit` and `env`.
- Handles errors and prints relevant messages.
- Manages environmental variables.

## Built-in Commands
- `exit` - Exits the shell.
- `env` - Prints the current environment.

## Example
Running the shell in interactive mode and executing commands:

```
$ ./hsh
$> /bin/ls
hsh main.c shell.c
$> exit
$
```

## Authors
- SIDOW ADAN SIDOW
- Abshir Hassan

## Acknowledgments
- The ALX Software Engineering Programme
- Julien Barbier and the Holberton School staff
- All peers who have offered support and insights.
