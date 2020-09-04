CC = gcc
CFLAGS = -Wall

rot: rot.o
	$(CC) $(CFLAGS) -o rot rot.o

rot.o: rot.c
	$(CC) $(CFLAGS) -c rot.c

clean:
	rm rot *.o
