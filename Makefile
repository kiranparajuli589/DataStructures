CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=stacks/ll_stack.cpp stacks/array_stack.cpp \
	queues/arr_queue.cpp queues/ll_queue.cpp queues/circular_queue.cpp queues/deque.cpp queues/priority_queue.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLES=$(SOURCES:.cpp=)

all: $(SOURCES) $(EXECUTABLES)

$(EXECUTABLES): $(OBJECTS)
	$(CC) $(LDFLAGS) $@.o -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o **/*.o $(EXECUTABLES)
