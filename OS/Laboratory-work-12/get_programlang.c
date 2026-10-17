#include <stdio.h>
#include <libpq-fe.h>
#include "programlang.h"

void get_programlang(PGconn *conn) {
    PGresult *res;

    res = PQexec(conn, "START TRANSACTION");
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Не вдалося почати транзакцію: %s", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    printf("Транзакцію розпочато.\n");
    PQclear(res);

    res = PQexec(conn, "LOCK TABLE programlang IN ACCESS SHARE MODE");
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Не вдалося заблокувати таблицю: %s", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    printf("Таблицю заблоковано для читання.\n");
    PQclear(res);

    res = PQexec(conn, "SELECT * FROM programlang");
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "Помилка виконання SELECT: %s", PQerrorMessage(conn));
        PQclear(res);
        return;
    }

    printf("Результати вибірки:\n");
    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++) {
        printf("ID: %s, Name: %s, Year: %s\n",
               PQgetvalue(res, i, 0),
               PQgetvalue(res, i, 1),
               PQgetvalue(res, i, 2));
    }
    PQclear(res);

    res = PQexec(conn, "COMMIT");
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Не вдалося виконати COMMIT: %s", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    printf("Транзакцію завершено (COMMIT).\n");
    PQclear(res);
}
