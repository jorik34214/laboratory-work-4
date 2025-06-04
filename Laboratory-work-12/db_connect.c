#include <stdio.h>
#include <libpq-fe.h>

int main() {
    const char *conninfo = "host=localhost port=5432 dbname=ai241-stepanenko_db user=ai241-stepanenko password=1234";
    PGconn *conn = PQconnectdb(conninfo);

    if (PQstatus(conn) == CONNECTION_OK) {
        printf("З'єднання з базою даних '%s' встановлено успішно.\n", "stepanenko_db");
    } else {
        fprintf(stderr, "Помилка з'єднання з базою даних '%s': %s\n", "stepanenko_db", PQerrorMessage(conn));
    }

    PQfinish(conn);
    return 0;
}
