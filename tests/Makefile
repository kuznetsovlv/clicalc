#Makefile
srcDir = ../src
stackPath = $(srcDir)/stack.h

.PHONY: test
test: testStack.test testOperation.test testOperationBuilder.test
	./testStack.test
	./testOperation.test
	./testOperationBuilder.test

testStack.test: testStack.o exception.o $(stackPath)
	gcc -o testStack.test exception.o testStack.o  -lcppunit -lstdc++

testOperation.test: testOperation.o exception.o $(stackPath) operation.o
	gcc -o testOperation.test exception.o operation.o testOperation.o -lcppunit -lstdc++ -lm

testOperationBuilder.test: testOperationBuilder.o exception.o $(stackPath) operation.o operationBuilder.o
	gcc -o testOperationBuilder.test exception.o operation.o operationBuilder.o testOperationBuilder.o -lcppunit -lstdc++ -lm

testStack.o: test.h
testOperation.o: test.h operation.o
testOperationBuilder.o: test.h operationBuilder.o

exception.o: $(srcDir)/exception.h $(srcDir)/exception.cpp
	gcc -c $(srcDir)/exception.cpp -o exception.o
operation.o: $(srcDir)/operation.h $(srcDir)/operation.cpp
	gcc -c $(srcDir)/operation.cpp -o operation.o
operationBuilder.o: $(srcDir)/operationBuilder.h $(srcDir)/operationBuilder.cpp
	gcc -c $(srcDir)/operationBuilder.cpp -o operationBuilder.o

.PHONY: clean
clean:
	-rm -f *.o *.so *.test *.xml 2>/dev/null
