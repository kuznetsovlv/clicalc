#pragma once
#if !defined(OPERATION_BUILDER)
#define OPERATION_BUILDER
#include "builder.h"
#include "operation.h"

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

	bool isOperator();
};
#endif
