#Makefile

.PHONY: test
test: testStack.test
	./testStack.test

testStack.test: ../src/exception.cpp ../src/exception.h ../src/stack.h
	gcc -o testStack.test ../src/exception.cpp testStack.cpp  -lcppunit -lstdc++

.PHONY: clean
clean:
	-rm -f *.o *.so *.test *.xml 2>/dev/null
