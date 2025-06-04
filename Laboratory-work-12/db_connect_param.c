#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Використання: %s <host> <port> <dbname> <user> <password>\n", argv[0]);
        return 1;
    }

    const char *host = argv[1];
    const char *port = argv[2];
    const char *dbname = argv[3];
    const char *user = argv[4];
    const char *password = argv[5];

    char conninfo[512];
    snprintf(conninfo, sizeof(conninfo),
             "host=%s port=%s dbname=%s user=%s password=%s",
             host, port, dbname, user, password);

    PGconn *conn = PQconnectdb(conninfo);

    if (PQstatus(conn) == CONNECTION_OK) {
        printf("З'єднання з базою даних '%s' встановлено успішно.\n", dbname);
    } else {
        fprintf(stderr, "Помилка з'єднання з базою даних '%s': %s\n", dbname, PQerrorMessage(conn));
    }

    PQfinish(conn);
    return 0;
}
