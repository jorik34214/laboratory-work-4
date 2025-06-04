#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        close(pipefd[1]);
        char fd_arg[10];
        snprintf(fd_arg, sizeof(fd_arg), "%d", pipefd[0]);
        execlp("./pipe_read", "pipe_read", fd_arg, NULL);

        perror("execlp");
        exit(1);
    } else {

        close(pipefd[0]);

        const char *msg = "The Laboratory Work of Stepanenko";
        ssize_t bytes_written = write(pipefd[1], msg, strlen(msg));
        if (bytes_written < 0) {
            perror("write");
            return 1;
        }

        printf("I'm parent process of Stepanenko with pid=%d\n", getpid());
        printf("Sent message size: %zd bytes\n", bytes_written);

        close(pipefd[1]);
        wait(NULL);
    }

    return 0;
}
