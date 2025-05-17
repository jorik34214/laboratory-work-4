#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    int n = 19;

    if (pid == -1) {
        perror("Помилка створення процесу");
        return 1;
    } else if (pid == 0) {
        printf("Child of Karaulnyi is finished (PID: %d)\n", getpid());
        exit(0);
    } else {
        sleep(3 * n);
        waitpid(pid, NULL, 0);
        printf("Parent process finished\n");
    }

    return 0;
}
