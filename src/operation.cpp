#include <cmath>
#include <cstring>
#include "operation.h"

long double power(long double a, long double b)
{
	return pow(a, b);
}

long double product(long double a, long double b)
{
	return a * b;
}

long double divide(long double a, long double b)
{
	return a / b;
}

long double add(long double a, long double b)
{
	return a + b;
}

long double subtract(long double a, long double b)
{
	return a - b;
}

Operation* Operation::pow = nullptr;
Operation* Operation::prod = nullptr;
Operation* Operation::div = nullptr;
Operation* Operation::sum = nullptr;
Operation* Operation::subtr = nullptr;
Operation* Operation::absolute = nullptr;

Operation::Operation(){};

Operation::Operation(OperationPriority priority):priority(priority){}

Operation::Operation(Operation& op){}

void Operation::operator = (Operation&){}

Operation* Operation::getPow()
{
	if(!pow)
	{
		pow = new BinOperation(primary, power);
	}

	return pow;
}

Operation* Operation::getProd()
{
	if(!prod)
	{
		prod = new BinOperation(secondary, product);
	}

	return prod;
}

Operation* Operation::getDiv()
{
	if(!div)
	{
		div = new BinOperation(secondary, divide);
	}

	return div;
}

Operation* Operation::getSum()
{
	if(!sum)
	{
		sum = new BinOperation(last, add);
	}

	return sum;
}

Operation* Operation::getSubtr()
{
	if(!subtr)
	{
		subtr = new BinOperation(last, subtract);
	}

	return subtr;
}

Operation* Operation::getAbs()
{
	if(!absolute)
	{
		absolute = new MonoOperation(primary, abs);
	}

	return absolute;
}

Operation* Operation::getOperation(string op)
{
	if(!op.compare("^"))
	{
		return getPow();
	}
	else if(!op.compare("*"))
	{
		return getProd();
	}
	else if(!op.compare("/"))
	{
		return getDiv();
	}
	else if(!op.compare("+"))
	{
		return getSum();
	}
	else if(!op.compare("-"))
	{
		return getSubtr();
	}
	else if(!op.compare("abs"))
	{
		return getAbs();
	}
	else
	{
		throw UnsuportedOperationException(op);
	}
}

OperationPriority Operation::getPriority()
{
	return priority;
}

BinOperation::BinOperation(){}

BinOperation::BinOperation(OperationPriority priority, long double (*operation)(long double, long double)):Operation(priority),operation(operation){}

BinOperation::BinOperation(BinOperation& op){}

long double BinOperation::complete(Stack<long double>& stack)
{
	long double b = stack.pop();
	long double a = stack.pop();
	return operation(a, b);
}

MonoOperation::MonoOperation(){}

MonoOperation::MonoOperation(OperationPriority priority, long double (*operation)(long double)):Operation(priority),operation(operation){}

MonoOperation::MonoOperation(MonoOperation& op){}

long double MonoOperation::complete(Stack<long double>& stack)
{
	return operation(stack.pop());
}
