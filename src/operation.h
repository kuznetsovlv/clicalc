#pragma once
#if !defined(OPERATION)
#define OPERATION
#include "stack.h"
#include "exception.h"
#include <string>
enum OperationPriority {imediate, primary, secondary, last};

class Operation
{
	Operation(Operation&) = delete;

	Operation& operator = (Operation&) = delete;

	OperationPriority priority;

protected:
	Operation();

	Operation(OperationPriority);

	static Operation *pow;
	static Operation *prod;
	static Operation *div;
	static Operation *sum;
	static Operation *subtr;
	static Operation *absolute;

	static Operation* getPow();
	static Operation* getProd();
	static Operation* getDiv();
	static Operation* getSum();
	static Operation* getSubtr();
	static Operation* getAbs();

public:
	static Operation* getOperation(std::string);
	OperationPriority getPriority();
	virtual long double complete(Stack<long double>&) = 0;
};

class BinOperation : public Operation
{
	BinOperation();
	BinOperation(OperationPriority, long double (*)(long double, long double));
	BinOperation(BinOperation&);

	long double (*operation)(long double, long double);

public:
friend class Operation;

	long double complete(Stack<long double>&);
};

class MonoOperation : public Operation
{
	MonoOperation();
	MonoOperation(OperationPriority, long double (*)(long double));
	MonoOperation(MonoOperation&);

	long double (*operation)(long double);

public:
friend class Operation;

	long double complete(Stack<long double>&);
};
#endif
