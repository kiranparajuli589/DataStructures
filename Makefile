CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=stacks/ll_stack.cpp stacks/array_stack.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLES=$(SOURCES:.cpp=)

all: $(SOURCES) $(EXECUTABLES)

$(EXECUTABLES): $(OBJECTS)
	$(CC) $(LDFLAGS) $@.o -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o stacks/*.o $(EXECUTABLES)
