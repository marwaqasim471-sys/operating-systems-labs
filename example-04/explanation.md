Example 04 – dup() System Call
Purpose

This example demonstrates how the dup() system call is used in Linux to create a second file descriptor that refers to the same open file.
Both descriptors share the same file offset, meaning that reading from one affects the position of the other.

System Calls / Functions Used

open(const char *pathname, int flags) — from <fcntl.h>

dup(int oldfd) — from <unistd.h>

read(int fd, void *buf, size_t count) — from <unistd.h>

write(int fd, const void *buf, size_t count) — from <unistd.h>

close(int fd) — from <unistd.h>

printf() and perror() — from <stdio.h>

How It Works

A file named test.txt is prepared in the same directory, containing text such as:




The program opens this file in read–write mode:

old_fd = open("test.txt", O_RDWR);


After this call, old_fd represents the opened file.

The program reads the first 10 characters from the file:

n = read(old_fd, buff, 10);


This moves the file offset forward by 10 bytes.
Output example:

1234567890


The file descriptor is duplicated:

new_fd = dup(old_fd);


Now:

old_fd and new_fd both refer to the same underlying file

They share the same file offset

A second read occurs, this time using the duplicated descriptor:

n = read(new_fd, buff, 10);


Since the offset was already moved by the first read, this read begins from the 11th character.
Example output:
marwa
Finally, both descriptors are closed:

close(old_fd);
close(new_fd);

How to Compile and Run
Steps

Create a file named test.txt in the same directory and write at least 20 characters in it.

Compile the program:

gcc main.c -o app


Run the program:

./app
