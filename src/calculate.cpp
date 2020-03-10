#include "calculate.h"
#include "expressionCalculator.h"

long double calculate(const char* str)
{
	ExpressionCalculator calculator;

	while(*(str)) calculator.with(*(str++));

	return *(calculator.build());
}
