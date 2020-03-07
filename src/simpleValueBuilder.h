#pragma once
#if !defined(SIMPLE_VALUE_BUILDER)
#define SIMPLE_VALUE_BUILDER
#include <string>
#include "valueBuilder.h"

class SimpleValueBuilder : public ValueBuilder
{
	std::string str;
	bool withDecimal;
	unsigned exp;
	bool started;
	SimpleValueBuilder *b;

public:
	SimpleValueBuilder();

	SimpleValueBuilder& with(char);
	long double* build();
};
#endif
