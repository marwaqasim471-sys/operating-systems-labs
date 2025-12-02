Example 06 – wait() System Call
Purpose

This example demonstrates how the wait() system call is used by a parent process to pause execution until its child process finishes.
It also shows how the parent can retrieve the exit status of the child process, providing a simple form of process synchronization.

System Calls / Functions Used

pid_t fork(void) from <unistd.h> – creates a new child process

pid_t wait(int *status) from <sys/wait.h> – causes the parent to wait for a child to terminate

pid_t getpid(void) from <unistd.h> – gets the PID of the current process

unsigned int sleep(unsigned int seconds) from <unistd.h> – suspends execution

void exit(int status) from <stdlib.h> – terminates a process with a status code

printf() and perror() from <stdio.h> – output and error handling

How It Works
1. Parent prints its PID
printf("Parent: Before fork - PID: %d\n", getpid());

2. Process creation
pid = fork();


Child process: fork() returns 0

Parent process: fork() returns the child PID (positive number)

Child Process Block (pid == 0)

The child process:

Prints its PID

Simulates work using:

sleep(3);


Terminates with exit code 5:

exit(5);

Parent Process Block (pid > 0)

The parent process:

Prints the child PID

Waits for the child process to finish:

child_pid = wait(&status);


When wait() returns:

child_pid contains the PID of the finished child

status contains termination details

Checks whether the child exited normally:

if (WIFEXITED(status)) {
    int exit_status = WEXITSTATUS(status);
    printf("Parent: Child exited normally with status: %d\n", exit_status);
}


Prints a final message and exits.

How to Compile and Run
1. Compile
gcc main.c -o app

2. Run
./app
