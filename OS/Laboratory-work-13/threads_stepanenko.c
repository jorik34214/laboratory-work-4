#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TIMES 27

void* function1(void* arg) {
    for (int i = 0; i < TIMES; i++) {
        printf("Function 1: Hello from Stepanenko (iteration %d)\n", i + 1);
        usleep(100000);
    }
    pthread_exit(NULL);
}

void* function2(void* arg) {
    for (int i = 0; i < TIMES; i++) {
        printf("Function 2: Hello from Stepanenko (iteration %d)\n", i + 1);
        usleep(100000);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, function1, NULL) != 0) {
        perror("Failed to create thread 1");
        exit(1);
    }

    if (pthread_create(&thread2, NULL, function2, NULL) != 0) {
        perror("Failed to create thread 2");
        exit(1);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread finished.\n");
    return 0;
}
