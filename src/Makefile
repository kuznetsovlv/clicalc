#Makefile
objects = main.o exception.o operation.o

.PHONY: all
all: clicalc

clicalc: $(objects)
	gcc -o clicalc $(objects) -lstdc++ -lm

main.o: exception.h stack.h operation.h
exception.o: exception.h
operation.o: operation.h

.PHONY: clean
clean:
	-rm -f *.o *.so 2>/dev/null
