#pragma once
#if !defined(VALUE_BUILDER)
#define VALUE_BUILDER
#include <string>
#include "builder.h"
#include "exception.h"

class ValueBuilder : public Builder<long double>
{
public:
	ValueBuilder();

	virtual ValueBuilder& with(char) = 0;
	virtual long double* build() = 0;
};
#endif
