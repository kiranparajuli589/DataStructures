CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=stack/ll_stack.cpp stack/array_stack.cpp \
	queue/arr_queue.cpp queue/ll_queue.cpp queue/circular_queue.cpp queue/deque.cpp queue/priority_queue.cpp \
	expression/infix_to_postfix.cpp expression/infix_to_prefix.cpp \
	tree/binary_tree.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLES=$(SOURCES:.cpp=)

all: $(SOURCES) $(EXECUTABLES)

$(EXECUTABLES): $(OBJECTS)
	$(CC) $(LDFLAGS) $@.o -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o **/*.o $(EXECUTABLES)
