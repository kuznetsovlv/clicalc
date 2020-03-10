#Makefile
objects = main.o exception.o operation.o operationBuilder.o valueBuilder.o simpleValueBuilder.o expressionCalculator.o calculate.o

.PHONY: all
all: clicalc

clicalc: $(objects)
	gcc -o clicalc $(objects) -lstdc++ -lm

main.o: exception.h calculate.h
exception.o: exception.h
operation.o: operation.h
operationBuilder.o: builder.h operationBuilder.h operation.h exception.h
valueBuilder.o: builder.h valueBuilder.h exception.h
simpleValueBuilder.o: builder.h valueBuilder.h simpleValueBuilder.h exception.h
expressionCalculator.o: builder.h valueBuilder.h expressionCalculator.h exception.h stack.h
calculate.o: calculate.h expressionCalculator.h

.PHONY: clean
clean:
	-rm -f clicalc *.o *.so 2>/dev/null
