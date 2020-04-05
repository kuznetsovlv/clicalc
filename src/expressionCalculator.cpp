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
	if(currentState != expression || opBuilder->ready())
	{
		clear();
		currentState = operation;
		opBuilder = new OperationBuilder();
	}

	opBuilder->with(ch);
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

	if(ch != ' ' && ch != '\t')
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
		long double v = operations.pop()->complete(values);
		values.push(v);
	}

	long double* result = new(long double);
	*result = values.pop();
	return result;
}
