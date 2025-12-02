Example 07 – Orphan Process Program
Purpose

This example demonstrates how an orphan process is created in Linux.
An orphan process is a child process whose parent has terminated. When this happens, the child is adopted by the init (or systemd) process, and its parent process ID (PPID) changes.

System Calls / Functions Used

fork() – creates a child process.

getpid() – returns the PID of the calling process.

getppid() – returns the PPID of the calling process.

sleep() – pauses the process for a specified number of seconds.

printf() and perror() – output and error functions.

How It Works

The program prints the PID and PPID of the original process.

The program calls fork():

In the child process, fork() returns 0.

In the parent process, fork() returns the child’s PID.

Child process (pid == 0):

Prints its PID and PPID.

Calls sleep(10) to keep the child running after the parent exits.

After the sleep, the child prints its PID and PPID again.

At this point, PPID will usually have changed, indicating that the child has become an orphan adopted by init/systemd.

Parent process (pid > 0):

Prints its PID and the PID of the child.

Does not call wait().

Exits immediately, leaving the child process running.

How to Compile and Run
gcc main.c -o app
./app
