# Example 01 – read() and write() System Calls

## Purpose
The purpose of this example is to demonstrate how to use the `read()` and `write()` system calls in a basic C program.  
It shows how data can be read from the keyboard and written to the screen using file descriptors.

## System Calls / Functions Used
- `read(int fd, void *buf, size_t count)` from `<unistd.h>`
- `write(int fd, const void *buf, size_t count)` from `<unistd.h>`

## How It Works
1. The program declares a character buffer of size 20 bytes.
2. It reads up to 10 bytes from standard input (keyboard) using:
   ```c
   read(0, buffer, 10);
File descriptor 0 refers to standard input.

The typed characters are stored in buffer.

It then writes the same 10 bytes to standard output using:
write(1, buffer, 10);
File descriptor 1 refers to standard output (screen).
The program returns 0 to indicate successful execution.
Note: For simplicity, error checking is omitted in this example. In production code, you should always check the return values of read() and write().
How to Compile and Run
bash
gcc main.c -o app
./app
