#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_NAME "stepanenko"

int main() {
    if (mkfifo(FIFO_NAME, 0660) == -1) {
        perror("mkfifo");
    } else {
        printf("Іменований канал '%s' створено\n", FIFO_NAME);
    }

    int fd_write = open(FIFO_NAME, O_WRONLY);
    if (fd_write == -1) {
        perror("open write");
        unlink(FIFO_NAME);
        exit(EXIT_FAILURE);
    }

    char message[] = "The Laboratory Work of Stepanenko\n";
    write(fd_write, message, strlen(message));

    printf("Повідомлення записано: %s", message);
    close(fd_write);

    int fd_read = open(FIFO_NAME, O_RDONLY);
    if (fd_read == -1) {
        perror("open read");
        unlink(FIFO_NAME);
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    ssize_t num_read = read(fd_read, buffer, sizeof(buffer) - 1);
    if (num_read > 0) {
        buffer[num_read] = '\0';
        printf("Прочитано з каналу: %s\n", buffer);
    } else {
        printf("Немає даних для читання\n");
    }
    close(fd_read);

    if (unlink(FIFO_NAME) == -1) {
        perror("unlink");
        exit(EXIT_FAILURE);
    }
    printf("Іменований канал '%s' видалено\n", FIFO_NAME);

    return 0;
}
