#include <stdio.h>
#include <libpq-fe.h>

void add_programlang(PGconn *conn, int pl_id, const char *name, int year) {
    PGresult *res;

    res = PQexec(conn, "START TRANSACTION;");
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Помилка START TRANSACTION: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    PQclear(res);
    printf("Транзакція почата.\n");

    char lock_query[] = "LOCK TABLE programlang IN EXCLUSIVE MODE;";
    res = PQexec(conn, lock_query);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Помилка LOCK TABLE: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    PQclear(res);
    printf("Таблиця заблокована.\n");

    char insert_query[256];
    snprintf(insert_query, sizeof(insert_query),
             "INSERT INTO programlang (pl_id, name, year) VALUES (%d, '%s', %d);",
             pl_id, name, year);
    res = PQexec(conn, insert_query);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Помилка INSERT: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    PQclear(res);
    printf("Рядок додано.\n");

    res = PQexec(conn, "COMMIT;");
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Помилка COMMIT: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    PQclear(res);
    printf("Транзакція завершена (COMMIT).\n");
}
