#include <cmath>
#include "operation.h"

OperationPriority ImediateOperation::getPriority()
{
	return imediate;
}

OperationPriority PrimaryOperation::getPriority()
{
	return primary;
}

OperationPriority SecondaryOperation::getPriority()
{
	return secondary;
}

long double PowerOperation::complete(Stack<long double>& stack)
{
	long double p = stack.pop();

	return pow(stack.pop(), p);
}

long double ProductOperation::complete(Stack<long double>& stack)
{
	return stack.pop() * stack.pop();
}

long double DivideOperation::complete(Stack<long double>& stack)
{
	long double x = stack.pop();

	return stack.pop() / x;
}

long double SumOperation::complete(Stack<long double>& stack)
{
	return stack.pop() + stack.pop();
}

long double SubstrOperation::complete(Stack<long double>& stack)
{
	return -stack.pop() + stack.pop();
}
