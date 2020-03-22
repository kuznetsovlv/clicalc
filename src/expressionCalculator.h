#pragma once
#if !defined(EXPRESSION_CALCULATOR)
#define EXPRESSION_CALCULATOR
#include "valueBuilder.h"
#include "operationBuilder.h"
#include "operation.h"
#include "stack.h"

class ExpressionCalculator : public ValueBuilder
{
	enum state {init, operation, value, expression, cleared};

	state currentState;
	unsigned parentheses;
	Stack<long double> values;
	Stack<Operation*> operations;
	OperationBuilder* opBuilder;
	ValueBuilder* vBuilder;

	void withExpression(char);
	void openParentheses();
	void clear();
	void clearOperation();
	void clearValue();
	void multiply();

public:
	ExpressionCalculator();
	ExpressionCalculator(ExpressionCalculator&) = delete;
	~ExpressionCalculator();

	ExpressionCalculator& operator = (ExpressionCalculator&) = delete;

	ExpressionCalculator& with(char);
	long double* build();
};
#endif
