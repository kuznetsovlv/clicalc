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

Operation::Operation(){};

Operation::Operation(OperationPriority priority, long double(*operation)(long double, long double)):priority(priority),operation(operation){};

Operation::Operation(Operation& op){};

void Operation::operator = (Operation&){};

Operation* Operation::getPow()
{
	if(!pow)
	{
		pow = new Operation(imediate, power);
	}

	return pow;
}

Operation* Operation::getProd()
{
	if(!prod)
	{
		prod = new Operation(primary, product);
	}

	return prod;
}

Operation* Operation::getDiv()
{
	if(!div)
	{
		div = new Operation(primary, divide);
	}

	return div;
}

Operation* Operation::getSum()
{
	if(!sum)
	{
		sum = new Operation(secondary, add);
	}

	return sum;
}

Operation* Operation::getSubtr()
{
	if(!subtr)
	{
		subtr = new Operation(secondary, subtract);
	}

	return subtr;
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
	else
	{
		throw UnsuportedOperationException(op);
	}
}

OperationPriority Operation::getPriority()
{
	return priority;
}

long double Operation::complete(Stack<long double>& stack)
{
	long double b = stack.pop();
	long double a = stack.pop();
	return operation(a, b);
}
