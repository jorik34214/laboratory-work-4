#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int turn = 0;

struct programlang {
    int id;
    char name[20];
    int year;
};

struct programlang lang = {1, "C", 1969};

void* T1() {
    for (int i = 0; i < 3; i++) {
        while (turn != 0) {
            sleep(1);
        }

        printf("T1: Critical Region\n");
        printf("T1: Read [year] = %d\n", lang.year);
        lang.year += 1;
        printf("T1: Write [year] = %d\n", lang.year);

        turn = 1;

        printf("T1: Non-Critical Region\n");
        sleep(1);
    }

    return NULL;
}

void* T2() {
    sleep(1);

    for (int i = 0; i < 3; i++) {
        while (turn != 1) {
            sleep(1);
        }

        printf("T2: Critical Region\n");
        printf("T2: Read [year] = %d\n", lang.year);
        lang.year += 2;
        printf("T2: Write [year] = %d\n", lang.year);
        turn = 0;
        printf("T2: Non-Critical Region\n");
        sleep(1);
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
