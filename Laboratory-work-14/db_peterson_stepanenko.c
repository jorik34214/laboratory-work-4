#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

struct programlang {
    int id;
    char name[20];
    int year;
} lang = {1, "C", 1969};

volatile int turn;
volatile bool flag[2];

void delay() {
    usleep(100000);
}

void* T1(void* arg) {
    for (int i = 0; i < 3; ++i) {
        flag[0] = true;
        turn = 1;
        while (flag[1] && turn == 1);

        printf("T1: Read year = %d\n", lang.year);
        lang.year += 1;
        printf("T1: Write year = %d\n", lang.year);

        flag[0] = false;

        delay();
    }
    return NULL;
}

void* T2(void* arg) {
    for (int i = 0; i < 3; ++i) {
        flag[1] = true;
        turn = 0;
        while (flag[0] && turn == 0);

        printf("T2: Read year = %d\n", lang.year);
        lang.year -= 1;
        printf("T2: Write year = %d\n", lang.year);

        flag[1] = false;

        delay();
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    flag[0] = false;
    flag[1] = false;

    pthread_create(&t1, NULL, T1, NULL);
    pthread_create(&t2, NULL, T2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final year = %d\n", lang.year);

    return 0;
}
