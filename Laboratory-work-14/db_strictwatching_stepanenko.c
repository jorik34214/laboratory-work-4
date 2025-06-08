#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct programlang {
    int id;
    char name[20];
    int year;
} lang = {1, "C", 1969};

volatile int turn = 0;

void delay() {
    usleep(100000);
}

void* T1(void* arg) {
    for (int i = 0; i < 3; ++i) {
        while (turn != 0);

        printf("T1: Read year = %d\n", lang.year);
        lang.year += 10;
        printf("T1: Write year = %d\n", lang.year);

        turn = 1;

        delay();
    }
    return NULL;
}

void* T2(void* arg) {
    for (int i = 0; i < 3; ++i) {
        while (turn != 1);

        printf("T2: Read year = %d\n", lang.year);
        lang.year -= 5;
        printf("T2: Write year = %d\n", lang.year);

        turn = 0;

        delay();
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, T1, NULL);
    pthread_create(&t2, NULL, T2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final year = %d\n", lang.year);

    return 0;
}
