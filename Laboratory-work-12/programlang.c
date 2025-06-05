#include "programlang.h"

int main() {
    PGconn *conn;
    connect_programlang(&conn);
    add_programlang(conn, 2, "C", 1969);
    get_programlang(conn);

    PQfinish(conn);
    return 0;
}
