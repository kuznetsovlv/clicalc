#pragma once
#if !defined(SIMPLE_VALUE_BUILDER)
#define SIMPLE_VALUE_BUILDER
#include "valueBuilder.h"

class SimpleValueBuilder : public ValueBuilder
{
	long double value;
	bool started;
	bool negate;
	bool withDecimal;
	unsigned power;

	void throwException(char) const;

public:
	SimpleValueBuilder();

	SimpleValueBuilder& with(char);
	long double* build();
};
#endif
