#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pipe_fd>\n", argv[0]);
        return 1;
    }

    int pipe_fd = atoi(argv[1]);
    char buffer[256];
    ssize_t bytes_read = read(pipe_fd, buffer, sizeof(buffer) - 1);

    if (bytes_read < 0) {
        perror("read");
        return 1;
    }

    buffer[bytes_read] = '\0';

    printf("I'm child process of Stepanenko with pid=%d\n", getpid());
    printf("Received message size: %zd bytes\n", bytes_read);
    printf("Message: %s\n", buffer);

    close(pipe_fd);
    return 0;
}
