#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    int n = 19;

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {

        for (int i = 0; i < 2 * n + 1; i++) {
            printf("Parent of Stepanenko: PPID = %d\n", getppid());
            sleep(1);
        }
    } else {

  sleep(n + 1);
        printf("Parent process (PID: %d) exiting...\n", getpid());
        exit(0);
    }

    return 0;
}
