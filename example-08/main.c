// example-08: Zombie process program in Linux
// Demonstrates a child process becoming a zombie
// because the parent does not call wait() immediately.

#include <stdio.h>      // printf(), perror()
#include <unistd.h>     // fork(), getpid(), getppid(), sleep()
#include <sys/types.h>  // pid_t
#include <stdlib.h>     // exit()

int main(void) {
    pid_t pid;

    printf("Main process started.\n");
    printf("Parent (before fork) PID = %d\n\n", getpid());

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // fork() failed
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // ---- Child process ----
        printf("[Child] I am the child process.\n");
        printf("[Child] PID  = %d\n", getpid());
        printf("[Child] My parent PID (PPID) = %d\n", getppid());
        printf("[Child] Child is exiting now...\n\n");
        // Child exits quickly; becomes a zombie until parent calls wait() or exits
        exit(0);
    } else {
        // ---- Parent process ----
        printf("[Parent] I am the parent process.\n");
        printf("[Parent] PID  = %d\n", getpid());
        printf("[Parent] Child PID (fork return value) = %d\n", pid);
        printf("[Parent] I will sleep for 20 seconds and NOT call wait().\n");
        printf("[Parent] During this time, the child will appear as a zombie.\n\n");

        // Parent sleeps while child has already terminated
        sleep(20);

        printf("[Parent] Woke up from sleep. Now parent will exit.\n");
    }

    return 0;
}
