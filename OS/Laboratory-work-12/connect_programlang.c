#include <stdio.h>
#include <libpq-fe.h>

void connect_programlang() {
    const char *conninfo = "host=localhost port=5432 dbname=ai241-stepanenko_db user=ai241-stepanenko password=1234";

    PGconn *conn = PQconnectdb(conninfo);

    if (PQstatus(conn) == CONNECTION_OK) {
        printf("З'єднання з базою даних встановлено успішно.\n");
    } else {
        fprintf(stderr, "Помилка з'єднання: %s\n", PQerrorMessage(conn));
    }

    PQfinish(conn);
}
