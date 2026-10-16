#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {

        perror("fork error");
        return 1;
    } else if (pid == 0) {

        printf("I am Zombie-process of Stepanenko\n");
        exit(0);
    } else {

        sleep(30);
    }

    return 0;
}
