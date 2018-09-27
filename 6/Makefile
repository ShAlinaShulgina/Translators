CC = g++

all : main

main: main.o
	$(CC) $(CFLAGS) main.o -o main $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -rf main.o main
