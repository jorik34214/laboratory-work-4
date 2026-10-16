#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    if (sig == SIGUSR2) {
        printf("Process of Stepanenko got signal\n");
    }
}

int main() {
    signal(SIGUSR2, handle_signal);

    printf("Waiting for SIGUSR2... (PID: %d)\n", getpid());

    while (1) {
        pause();
    }

    return 0;
}
