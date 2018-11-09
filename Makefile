#Enter Make main

CC=clang
LIBS=-lrt -lpthread
CFLAGS=-g
SOURCE1=main.c

EXEC1=main 

test1: $(SOURCE1)
	$(CC) -o $(EXEC1) $(CFLAGS) $(SOURCE1) $(LIBS)

clean:
	rm $(EXEC1) $(EXEC2)
