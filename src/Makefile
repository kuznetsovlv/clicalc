#Makefile
objects = main.o exception.o

.PHONY: all
all: clicalc

clicalc: $(objects)
	gcc -o clicalc $(objects) -lstdc++

main.o: exception.h stack.h
exception.o: exception.h

.PHONY: clean
clean:
	-rm -f *.o *.so 2>/dev/null
