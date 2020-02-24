#Makefile
objects = main.o exception.o operation.o operationBuilder.o

.PHONY: all
all: clicalc

clicalc: $(objects)
	gcc -o clicalc $(objects) -lstdc++ -lm

main.o: exception.h stack.h operationBuilder.h
exception.o: exception.h
operation.o: operation.h
operationBuilder.o: builder.h operationBuilder.h operation.h

.PHONY: clean
clean:
	-rm -f clicalc *.o *.so 2>/dev/null
