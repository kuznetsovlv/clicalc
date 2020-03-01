#pragma once
#if !defined(OPERATION_BUILDER)
#define OPERATION_BUILDER
#include <string>
#include "builder.h"
#include "operation.h"
#include "exception.h"

class OperationBuilder : public Builder<Operation>
{
	char *opName;
	int last;
	bool builded;
	void copy(OperationBuilder&);

public:
	OperationBuilder();
	OperationBuilder(OperationBuilder&);

	~OperationBuilder();

	OperationBuilder& operator = (OperationBuilder&);

	OperationBuilder& with(char);
	Operation* build();
};
#endif
