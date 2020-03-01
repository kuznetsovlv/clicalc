#Makefile
srcDir = ../src
stackPath = $(srcDir)/stack.h

.PHONY: test
test: testStack.test testOperation.test testOperationBuilder.test testSimpleValueBuilder.test
	./testStack.test
	./testOperation.test
	./testOperationBuilder.test
	./testSimpleValueBuilder.test

testStack.test: testStack.o exception.o $(stackPath)
	gcc -o testStack.test exception.o testStack.o  -lcppunit -lstdc++

testOperation.test: testOperation.o exception.o $(stackPath) operation.o
	gcc -o testOperation.test exception.o operation.o testOperation.o -lcppunit -lstdc++ -lm

testOperationBuilder.test: testOperationBuilder.o exception.o $(stackPath) operation.o operationBuilder.o
	gcc -o testOperationBuilder.test exception.o operation.o operationBuilder.o testOperationBuilder.o -lcppunit -lstdc++ -lm

testSimpleValueBuilder.test: testSimpleValueBuilder.o exception.o valueBuilder.o simpleValueBuilder.o
	gcc -o testSimpleValueBuilder.test exception.o simpleValueBuilder.o valueBuilder.o testSimpleValueBuilder.o -lcppunit -lstdc++ -lm

testStack.o: test.h
testOperation.o: test.h operation.o
testOperationBuilder.o: test.h operationBuilder.o
testSimpleValueBuilder.o: test.h simpleValueBuilder.o

exception.o:
	cd $(srcDir) && make exception.o && cd -
	mv $(srcDir)/exception.o ./exception.o
operation.o:
	cd $(srcDir) && make operation.o && cd -
	mv $(srcDir)/operation.o ./operation.o
operationBuilder.o:
	cd $(srcDir) && make operationBuilder.o && cd -
	mv $(srcDir)/operationBuilder.o ./operationBuilder.o
valueBuilder.o:
	cd $(srcDir) && make valueBuilder.o && cd -
	mv $(srcDir)/valueBuilder.o ./valueBuilder.o
simpleValueBuilder.o: valueBuilder.o
	cd $(srcDir) && make simpleValueBuilder.o && cd -
	mv $(srcDir)/simpleValueBuilder.o ./simpleValueBuilder.o

.PHONY: clean
clean:
	-rm -f *.o *.so *.test *.xml 2>/dev/null
