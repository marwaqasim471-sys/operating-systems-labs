# Example 02 – open() System Call

## Purpose
The purpose of this example is to demonstrate how to use the `open()` system call to obtain a file descriptor for a user-created file, and then use `read()` and `write()` to read data from the file and display it on the screen.

## System Calls / Functions Used
- `open(const char *pathname, int flags)` from `<fcntl.h>`
- `read(int fd, void *buf, size_t count)` from `<unistd.h>`
- `write(int fd, const void *buf, size_t count)` from `<unistd.h>`
- `close(int fd)` from `<unistd.h>`
- `printf()` and `perror()` from `<stdio.h>`

## How It Works
1. A file named `test.txt` should be created beforehand in the same directory, containing at least 10 characters.
2. The program calls:
   ```c
   fd = open("test.txt", O_RDONLY);
Opens the file in read-only mode.

Returns a positive file descriptor on success, or -1 on failure.

The file descriptor value is printed using printf().

The program reads up to 10 bytes from the file into the buffer:


n = read(fd, buff, 10);
n indicates how many bytes were actually read.

The program writes these bytes to standard output:

Finally, the file descriptor is closed using close(fd); to release system resources.

How to Compile and Run
Create a file named test.txt in the same directory and write some text in it (more than 10 characters).

Compile the program:

bash

gcc main.c -o app
Run the program:

bash
./app
