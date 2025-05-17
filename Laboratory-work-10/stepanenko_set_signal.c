#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);

    if (kill(pid, SIGUSR2) == 0) {
        printf("Signal SIGUSR2 sent to process %d\n", pid);
    } else {
        perror("Failed to send signal");
        return 1;
    }

    return 0;
}
