#pragma once
#if !defined(OPERATION)
#define OPERATION
#include "stack.h"
#include "exception.h"
enum OperationPriority {imediate, primary, secondary};

class Operation
{
public:
	virtual OperationPriority getPriority() = 0;
	virtual long double complete(Stack<long double>&) = 0;
};

class ImediateOperation : public Operation
{
public:
	OperationPriority getPriority();
};

class PrimaryOperation : public Operation
{
public:
	OperationPriority getPriority();
};

class SecondaryOperation : public Operation
{
public:
	OperationPriority getPriority();
};

class PowerOperation : public ImediateOperation
{
public:
	long double complete(Stack<long double>&);
};

class ProductOperation : public PrimaryOperation
{
public:
	long double complete(Stack<long double>&);
};

class DivideOperation : public PrimaryOperation
{
public:
	long double complete(Stack<long double>&);
};

class SumOperation : public SecondaryOperation
{
public:
	long double complete(Stack<long double>&);
};

class SubstrOperation : public SecondaryOperation
{
public:
	long double complete(Stack<long double>&);
};
#endif
