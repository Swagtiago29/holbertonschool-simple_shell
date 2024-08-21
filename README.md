# Simple Shell

## Description

This is a simple shell that prints a welcome message and allows the user to input commands. It tokenizes the input and executes the command using the `fork` and `execve` system calls.

## Functions

### `print_user`

Prints a welcome message to the user, including their username if provided as a command-line argument.  
Returns the number of command-line arguments passed by the user.

### `tokenize`

Tokenizes the input string using the provided delimiter.  
Returns an array of strings tokenized from the input.

### `main`

Runs an infinite loop that prints a prompt and waits for user input.  
Handles errors and exits the program if necessary.

### `syn`

Creates a chld process and executes the command using `fork` and `execve`.

## Flowchart
![WhatsApp Image 2024-08-20 at 23 05 40](https://github.com/user-attachments/assets/f37a08e4-226d-4033-910a-06b7e0ab899e)

## Example
To use this shell, simply compile with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh` run the program with `./hsh` . You will be prompted to enter a command after being greeted.
```./hsh
Welcome, thank you for using my shell! <3
$ /bin/ls
AUTHORS README.md hsh main.h shelly.c
$ /bin/ls -la
total 48
drwxr-xr-x 3 root root  4096 Aug 21 13:07 .
drwxr-xr-x 1 root root  4096 Aug 21 12:52 ..
drwxr-xr-x 8 root root  4096 Aug 21 13:00 .git
-rw-r--r-- 1 root root   137 Aug 21 12:59 AUTHORS
-rw-r--r-- 1 root root    83 Aug 21 12:52 README.md
-rwxr-xr-x 1 root root 16664 Aug 21 12:52 hsh
-rw-r--r-- 1 root root   209 Aug 21 12:52 main.h
-rw-r--r-- 1 root root  2246 Aug 21 12:52 shelly.c
$ 
