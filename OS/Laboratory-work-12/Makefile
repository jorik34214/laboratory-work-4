TABLE = programlang

CC = gcc
CFLAGS = -I/usr/include/postgresql
LIBS = -lpq

OBJ1 = connect_$(TABLE).o
OBJ2 = add_$(TABLE).o
OBJ3 = get_$(TABLE).o
OBJ4 = $(TABLE).o
EXE = $(TABLE)

all: $(EXE)

$(OBJ1): connect_$(TABLE).c $(TABLE).h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ2): add_$(TABLE).c $(TABLE).h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ3): get_$(TABLE).c $(TABLE).h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ4): $(TABLE).c $(TABLE).h
	$(CC) $(CFLAGS) -c $< -o $@

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
	$(CC) $^ $(LIBS) -o $@

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(EXE)

install: $(EXE)
	mkdir -p $(HOME)/bin
	cp $(EXE) $(HOME)/bin/
