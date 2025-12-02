Example 08 – Zombie Process Program
Purpose

This example demonstrates how a zombie process is created in Linux.
A zombie process is a child process that has finished execution but still has an entry in the process table because its parent has not yet called wait().

System Calls / Functions Used

fork() – creates a new child process.

getpid() – returns the process ID of the calling process.

getppid() – returns the parent process ID.

sleep() – pauses execution for a certain time.

printf() / perror() – for printing messages and errors.

How It Works

The parent process prints its PID before creating a child:

printf("Parent (before fork) PID = %d\n", getpid());


The program calls fork():

In the child process, fork() returns 0.

In the parent process, fork() returns the PID of the child.

Child process (pid == 0):

Prints its PID and its parent’s PID:

printf("[Child] PID = %d\n", getpid());
printf("[Child] My parent PID (PPID) = %d\n", getppid());


Exits immediately using exit(0);.

At this point, the child process is terminated, but its entry remains in the process table because the parent hasn’t called wait().

Parent process (pid > 0):

Prints its own PID and the child’s PID.

Does not call wait().

Sleeps for 20 seconds using sleep(20); to keep itself alive.

During this time, the child appears in the process table as a zombie process (state Z or defunct).

After sleep, the parent prints a final message and exits.

When the parent terminates, the zombie entry is automatically removed from the process table.

Observing the Zombie Process

Compile and run:

gcc main.c -o app
./app &


While the parent is sleeping, open another terminal and run:

ps -l


You will see the child process marked as Z (zombie) or <defunct>.

Key Points

Zombie processes do not consume CPU but occupy entries in the process table.

They exist only until the parent calls wait() or terminates.

Proper process management should always wait() for children to avoid zombies.
