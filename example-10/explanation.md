Example 10 – Creating Threads in Linux using pthread_create
Purpose

This example demonstrates how to create and manage multiple threads in a C program on Linux using the POSIX threads (pthreads) library.
It shows how to start threads with pthread_create() and wait for them to finish using pthread_join().

System Calls / Functions Used

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg) from <pthread.h> – creates a new thread.

int pthread_join(pthread_t thread, void **retval) from <pthread.h> – waits for a thread to terminate.

void pthread_exit(void *retval) from <pthread.h> – terminates the calling thread.

pid_t getpid(void) from <unistd.h> – returns the process ID of the calling process.

unsigned int sleep(unsigned int seconds) from <unistd.h> – suspends execution of the calling thread.

printf() and perror() from <stdio.h>.

exit(int status) from <stdlib.h>.

How It Works

Thread Function Definition
Each thread executes a function of type:

void* thread_function(void* arg) {
    int thread_id = *(int*)arg; // thread identifier
    for (int i = 0; i < 3; i++) {
        printf("Thread %d is running iteration %d\n", thread_id, i+1);
        sleep(1); // simulate work
    }
    pthread_exit(NULL);
}


Creating Threads in main()

Declare an array to store thread identifiers:

pthread_t threads[3];
int thread_ids[3] = {1, 2, 3};


Create 3 threads using a loop:

for (int i = 0; i < 3; i++) {
    int ret = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
    if (ret != 0) {
        perror("pthread_create");
        exit(1);
    }
}


Waiting for Threads to Finish

Ensure the main thread does not exit before all threads complete:

for (int i = 0; i < 3; i++) {
    pthread_join(threads[i], NULL);
}


Program Output

Threads run concurrently, and their messages may interleave.

Main thread waits for all worker threads to complete before exiting.

How to Compile and Run
gcc main.c -o app -pthread
./app


Steps:

Navigate to the directory: cd example-10

Compile the program with pthread support: gcc main.c -o app -pthread

Run the program: ./app

Observe:

Three threads running in parallel, each printing its progress.

Main thread waits for all threads to finish before exiting.
