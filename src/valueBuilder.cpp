#include "valueBuilder.h"

ValueBuilder::ValueBuilder():Builder() {};

ValueBuilder& ValueBuilder::with(char ch)
{
	Builder<long double>::with(ch);
	return *this;
}

long double* ValueBuilder::build()
{
	Builder<long double>::build();
	return NULL;
}
