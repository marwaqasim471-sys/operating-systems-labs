# Example 03 – lseek() System Call

## Purpose
The purpose of this example is to demonstrate how to use the `lseek()` system call to change the file offset of an open file.  
It shows how to read data from the beginning of a file, move the file pointer to a specific position, and read a different portion of the same file.

## System Calls / Functions Used
- `open(const char *pathname, int flags)` from `<fcntl.h>`
- `read(int fd, void *buf, size_t count)` from `<unistd.h>`
- `write(int fd, const void *buf, size_t count)` from `<unistd.h>`
- `lseek(int fd, off_t offset, int whence)` from `<unistd.h>`
- `close(int fd)` from `<unistd.h>`
- `printf()` and `perror()` from `<stdio.h>`

## How It Works
1. A file named `test.txt` should exist in the same directory with at least 20 characters.
2. The program opens the file in read-only mode:
   ```c
   fd = open("test.txt", O_RDONLY);
First, it reads the first 10 bytes from the file into a buffer:


n = read(fd, buff, 10);
write(1, buff, n);
Then, the program moves the file pointer 10 bytes from the beginning using lseek():

lseek(fd, 10, SEEK_SET);
It reads another 10 bytes from the new position and writes them to standard output.

Finally, the file descriptor is closed using close(fd).

How to Compile and Run
Create a file named test.txt in the same directory and write some text in it (at least 20 characters).

Compile the program:



gcc main.c -o app
Run the program:


./app
