#include <iostream>
#include "exception.h"
#include "stack.h"
#include "operation.h"
using namespace std;

int main(int argc, char **args)
{
	Stack<long double> s;

	Operation *op;

	for(int i = 0; i < 10; ++i)
		s.push(static_cast<long double>(i));

	op = Operation::getOperation("^");
	cout << op->getPriority() << " " << op->complete(s) << endl;

	op = Operation::getOperation("*");
	cout << op->getPriority() << " " << op->complete(s) << endl;

	op = Operation::getOperation("/");
	cout << op->getPriority() << " " << op->complete(s) << endl;

	op = Operation::getOperation("+");
	cout << op->getPriority() << " " << op->complete(s) << endl;

	op = Operation::getOperation("-");
	cout << op->getPriority() << " " << op->complete(s) << endl;

	s.push(-12.49);
	op = Operation::getOperation("abs");
	cout << op->getPriority() << " " << op->complete(s) << endl;

	return 0;
}
