#include "expressionCalculator.h"
using namespace std;

ExpressionCalculator::ExpressionCalculator():ValueBuilder(),currentState(init),parentheses(0),opBuilder(nullptr),vBuilder(nullptr){}
ExpressionCalculator::~ExpressionCalculator()
{
}

ExpressionCalculator& ExpressionCalculator::with(char ch)
{
	ValueBuilder::with(ch);
	return *this;
}

long double* ExpressionCalculator::build()
{
	ValueBuilder::build();
	return new long double[1];
}
