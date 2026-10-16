#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("Process Group ID: %d\n", getpgrp());
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());
    printf("User ID: %d\n", getuid());
    printf("Group User ID: %d\n", getgid());

    return 0;
}
