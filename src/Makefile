CC = gcc
CFLAGS = -I../include -Wall -g -std=c99

EXENAME = main
.PHONY : clean TAGS all

all: main
	mv main ../
main: shell.o log.o

shell.o: shell.c ../include/shell.h

log.o: log.c ../include/log.h

clean:
	rm -rf *.o shell main
