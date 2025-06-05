#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void sig_handler(int sig) {
    printf("Signal handler for signal = %d\n", sig);
    wait(0);
}

int main(void) {
    int n = 19;
    pid_t pid;

    signal(SIGCHLD, &sig_handler);

    pid = fork();

    if (pid < 0) {
        perror("Помилка створення процесу");
        return 1;
    }
    else if (pid == 0) {

        printf("Child of Stepanenko is finished (PID: %d)\n", getpid());
        _exit(0);
    }
    else {

        printf("Parent process started...\n");
        sleep(3 * n);
        printf("Parent process finished\n");
    }

    return EXIT_SUCCESS;
}
