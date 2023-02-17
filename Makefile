CC=g++
CFLAGS=-c -Wall
LDFLAGS=

help:
	@echo "--------------------------------"
	@echo "Available targets:"
	@echo "--------------------------------"
	@echo "make help 	- this help"
	@echo "make all	- build all"
	@echo "make stack 	- build stack"
	@echo "make queue 	- build queue"
	@echo "make clean 	- clean up"
	@echo "--------------------------------"

all: stack queue

stack: stack.cpp stack.o
	$(CC) $(LDFLAGS) stack.cpp -o stack

queue: queue.cpp queue.o
	$(CC) $(LDFLAGS) queue.cpp -o queue

clean:
	rm -f stack.o stack queue.o queue