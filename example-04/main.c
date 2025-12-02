// example-04: using dup() to duplicate a file descriptor
// and showing that both descriptors share the same file offset

#include <unistd.h>     // read(), write(), close(), dup()
#include <stdio.h>      // printf(), perror()
#include <fcntl.h>      // open() and flags

int main(void) {
    int old_fd, new_fd;
    char buff[20];
    int n;

    // Open the file in read/write mode
    old_fd = open("test.txt", O_RDWR);
    if (old_fd == -1) {
        perror("open");
        return 1;
    }

    printf("Old file descriptor: %d\n", old_fd);

    // Read the first 10 characters
    n = read(old_fd, buff, 10);
    if (n == -1) {
        perror("read");
        close(old_fd);
        return 1;
    }

    write(1, "First 10 characters: ", 22);
    write(1, buff, n);
    write(1, "\n", 1);

    // Duplicate the old file descriptor
    new_fd = dup(old_fd);
    if (new_fd == -1) {
        perror("dup");
        close(old_fd);
        return 1;
    }

    printf("New file descriptor: %d\n", new_fd);

    // Read the next 10 characters using the duplicated descriptor
    n = read(new_fd, buff, 10);
    if (n == -1) {
        perror("read");
        close(old_fd);
        close(new_fd);
        return 1;
    }

    write(1, "Next 10 characters : ", 22);
    write(1, buff, n);
    write(1, "\n", 1);

    close(old_fd);
    close(new_fd);

    return 0;
}
