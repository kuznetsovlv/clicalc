#Makefile
srcDir = ../src
stackPath = $(srcDir)/stack.h

.PHONY: test
test: testStack.test
	./testStack.test

testStack.test: testStack.o exception.o $(stackPath)
	gcc -o testStack.test exception.o testStack.o  -lcppunit -lstdc++

testStack.o: test.h

exception.o: $(srcDir)/exception.h
	gcc -c $(srcDir)/exception.cpp -o exception.o

.PHONY: clean
clean:
	-rm -f *.o *.so *.test *.xml 2>/dev/null
