#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct programlang {
    int id;
    char name[20];
    int year;
} lang = {1, "C", 1969};

sem_t* stepanenko;

void* T1() {
    for (int i = 0; i < 3; i++) {
        sem_wait(stepanenko);

        printf("T1: Read year = %d\n", lang.year);
        lang.year += 1;
        printf("T1: Write year = %d\n\n", lang.year);

        sem_post(stepanenko);
        sleep(1);
    }
    return NULL;
}

void* T2() {
    for (int i = 0; i < 3; i++) {
        sem_wait(stepanenko);

        printf("T2: Read year = %d\n", lang.year);
        lang.year -= 2;
        printf("T2: Write year = %d\n\n", lang.year);

        sem_post(stepanenko);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    stepanenko = sem_open("/stepanenko", O_CREAT, 0770, 1);
    if (stepanenko == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    pthread_create(&t1, NULL, T1, NULL);
    pthread_create(&t2, NULL, T2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final year = %d\n", lang.year);

    sem_close(stepanenko);
    sem_unlink("/stepanenko");
    return 0;
}
