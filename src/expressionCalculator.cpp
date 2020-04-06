#include "expressionCalculator.h"
using namespace std;

ExpressionCalculator::ExpressionCalculator():ValueBuilder(),currentState(init),parentheses(0),opBuilder(nullptr),vBuilder(nullptr){}
ExpressionCalculator::~ExpressionCalculator()
{
}

void ExpressionCalculator::withExpression(char ch)
{
	vBuilder->with(ch);
}

void ExpressionCalculator::withValueChar(char ch)
{
	if(currentState != value)
	{
		clear();
		currentState = value;
		vBuilder = new SimpleValueBuilder();
	}

	vBuilder->with(ch);
}

void ExpressionCalculator::withOperationChar(char ch)
{
	bool isValue = currentState == value;
	if(currentState != operation || opBuilder->ready())
	{
		clear();
		currentState = operation;
		opBuilder = new OperationBuilder();
	}

	opBuilder->with(ch);

	if(isValue && !opBuilder->isOperator())
		multiply();
}

void ExpressionCalculator::openParentheses()
{
	++parentheses;

	if(currentState == expression)
	{
		withExpression('(');
	}
	else
	{
		clear();
		currentState = expression;
		vBuilder = new ExpressionCalculator();
	}
}

void ExpressionCalculator::closeParentheses()
{
	if(!parentheses)
		throw UnbalancedParenthesesException("Extra close parantheses");

	--parentheses;

	if(parentheses)
		vBuilder->with(')');
	else
		clear();
}

void ExpressionCalculator::clear()
{
	switch(currentState)
	{
		case operation:
			clearOperation();
			break;
		case value:
		case expression:
			clearValue();
			break;
	}
	currentState = cleared;
}

void ExpressionCalculator::clearOperation()
{
	push(opBuilder->build());
	delete opBuilder;
}

void ExpressionCalculator::clearValue()
{
	values.push(*(vBuilder->build()));
	delete vBuilder;
}

void ExpressionCalculator::multiply()
{
	push(Operation::getOperation("*"));
}

void ExpressionCalculator::push(Operation* op)
{
	if(op->getPriority() == imediate)
		values.push(op->complete(values));
	else
	{
		if(!operations.isEmpty() && operations.top()->getPriority() <= op->getPriority())
		{
			Operation* prevOp = operations.pop();
			values.push(prevOp->complete(values));
			delete prevOp;
		}
		operations.push(op);
	}
}

ExpressionCalculator& ExpressionCalculator::with(char ch)
{
	ValueBuilder::with(ch);

	if(currentState != value || (ch != ' ' && ch != '\t'))
	{
		if(ch == '(')
			openParentheses();
		else if(ch == ')')
			closeParentheses();
		else if(currentState == expression)
			vBuilder->with(ch);
		else if((ch >= '0' && ch <= '9') || ch == '.')
			withValueChar(ch);
		else if(currentState == init && (ch == '-' || ch == '+'))
			withValueChar(ch);
		else
			withOperationChar(ch);
	}

	return *this;
}

long double* ExpressionCalculator::build()
{
	ValueBuilder::build();

	if(parentheses)
		throw UnbalancedParenthesesException("Unclosed parentheses");

	clear();

	while(!operations.isEmpty())
	{
		Operation* op = operations.pop();
		long double v = op->complete(values);
		delete op;
		values.push(v);
	}

	long double* result = new(long double);
	*result = values.pop();
	return result;
}
