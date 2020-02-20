#Makefile
srcDir = ../src
stackPath = $(srcDir)/stack.h

.PHONY: test
test: testStack.test testOperation.test
	./testStack.test
	./testOperation.test

testStack.test: testStack.o exception.o $(stackPath)
	gcc -o testStack.test exception.o testStack.o  -lcppunit -lstdc++

testOperation.test: testOperation.o exception.o $(stackPath) operation.o
	gcc -o testOperation.test exception.o operation.o testOperation.o -lcppunit -lstdc++ -lm

testStack.o: test.h
testOperation.o: test.h

exception.o: $(srcDir)/exception.h
	gcc -c $(srcDir)/exception.cpp -o exception.o
operation.o: $(srcDir)/operation.h
	gcc -c $(srcDir)/operation.cpp -o operation.o

.PHONY: clean
clean:
	-rm -f *.o *.so *.test *.xml 2>/dev/null
