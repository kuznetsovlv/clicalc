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
	Operation *op = opBuilder->build();
	delete opBuilder;

	if(op->getPriority() == imediate)
		values.push(op->complete(values));
	else if(!operations.isEmpty() && operations.top()->getPriority() <= op->getPriority())
		values.push(operations.pop()->complete(values));
	else
		operations.push(op);
}

void ExpressionCalculator::clearValue()
{
	values.push(*(vBuilder->build()));
	delete vBuilder;
}

ExpressionCalculator& ExpressionCalculator::with(char ch)
{
	ValueBuilder::with(ch);

	if(ch == '(')
		openParentheses();
	return *this;
}

long double* ExpressionCalculator::build()
{
	ValueBuilder::build();
	return new long double[1];
}
