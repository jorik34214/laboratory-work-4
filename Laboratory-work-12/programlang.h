#ifndef PROGRAMLANG_H
#define PROGRAMLANG_H

#include <libpq-fe.h>

void connect_programlang(PGconn **conn);
void add_programlang(PGconn *conn, int id, const char *name, int year);
void get_programlang(PGconn *conn);

#endif
