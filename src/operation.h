#pragma once
#if !defined(OPERATION)
#define OPERATION
#include "stack.h"
#include "exception.h"
#include <string>
enum OperationPriority {imediate, primary, secondary};

class Operation
{
	Operation();

	Operation(OperationPriority, long double (*)(long double, long double));

	Operation(Operation&);

	void operator = (Operation&);

	OperationPriority priority;

	long double (*operation)(long double, long double);

	static Operation *pow;
	static Operation *prod;
	static Operation *div;
	static Operation *sum;
	static Operation *subtr;

	static Operation* getPow();
	static Operation* getProd();
	static Operation* getDiv();
	static Operation* getSum();
	static Operation* getSubtr();

public:
	static Operation* getOperation(string);
	OperationPriority getPriority();
	long double complete(Stack<long double>&);
};
#endif
