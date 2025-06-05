#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 100
#define QUEUE_KEY (1000 + 100 * 1 + 22)

struct msg_buffer {
    long msg_type;
    char msg_text[MSG_SIZE];
};

int main() {
    int msgid = msgget(QUEUE_KEY, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    struct msg_buffer message;
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Отримано повідомлення: %s\n", message.msg_text);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
