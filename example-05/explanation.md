Example 05 – fork() System Call
Purpose

This example demonstrates how the fork() system call is used to create a new process in Linux.
After calling fork(), two processes exist:

Parent process

Child process

Each process executes the same program but takes a different path depending on the return value of fork().

System Calls / Functions Used

fork() from <unistd.h> — creates a new child process

getpid() from <unistd.h> — gets the process ID

getppid() from <unistd.h> — gets the parent process ID

printf() and perror() from <stdio.h> — printing and error handling

How It Works

The program prints the PID of the current process before creating a child.

pid = fork();

If return value < 0: the fork failed.

If return value == 0: code is running in the child.

If return value > 0: code is running in the parent, and the return value is the child PID.

Both processes print different information:

Child prints:

Its own PID

Its parent PID

Parent prints:

Its own PID

The child's PID

Corrected & Clean Version of the Code
How to Compile & Run
gcc main.c -o app
./app
