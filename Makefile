CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=stack/ll_stack.cpp stack/array_stack.cpp \
	queue/arr_queue.cpp queue/ll_queue.cpp queue/circular_queue.cpp \
	queue/deque.cpp queue/priority_queue.cpp \
	expression/infix_to_postfix.cpp expression/infix_to_prefix.cpp \
	tree/binary_tree.cpp tree/binary_search_tree.cpp \
	sorting/insertion.cpp sorting/selection.cpp sorting/bubble.cpp \
	sorting/radix.cpp sorting/shell.cpp \
	search/search.cpp \
	recursion/toh.cpp recursion/fibonacci.cpp \
	list/list_queue.cpp list/arr_static_list.cpp list/arr_dynamic_list.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLES=$(SOURCES:.cpp=)

all: $(SOURCES) $(EXECUTABLES)

$(EXECUTABLES): $(OBJECTS)
	$(CC) $(LDFLAGS) $@.o -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o **/*.o $(EXECUTABLES)
