#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork error");
        return 1;
    }

    if (pid == 0) {
        printf("the child of Stepanenko executes: head\n");
        sleep(1);

        char *args[] = {"head", "--lines=3", "/etc/group", NULL};
        execv("/usr/bin/head", args);

        perror("execv error");
        return 1;
    } else {
        wait(NULL);
    }

    return 0;
}
