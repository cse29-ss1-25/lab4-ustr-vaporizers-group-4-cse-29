CC = gcc
CFLAGS = -g -Wall -Wno-return-type -std=gnu99 -I.
DEPS = ustr.h list.h pset1.h
OBJ = obj/ustr.o obj/list.o obj/pset1.o

%.test: obj/test_%.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $< $(OBJ)

obj/test_%.o: tests/test_%.c $(DEPS) obj
	$(CC) $(CFLAGS) -c -o $@ $<

obj/pset1.o: pset1.c pset1.h obj
	$(CC) $(CFLAGS) -c -o $@ $<

obj/ustr.o: ustr.c ustr.h obj
	$(CC) $(CFLAGS) -c -o $@ $<

obj/list.o: list.c list.h obj
	$(CC) $(CFLAGS) -c -o $@ $<

obj:
	mkdir -p obj

clean:
	rm -r obj *.test
