#include "operationBuilder.h"
using namespace std;

const int LENGTH = 4;

void OperationBuilder::copy(OperationBuilder& opB)
{
	last = opB.last;
	builded = opB.builded;
	opName = new char[LENGTH];

	for(unsigned i = 0; i < LENGTH; ++i) *(opName +i) = *(opB.opName + i);
}

OperationBuilder::OperationBuilder():Builder(),last(-1)
{
	opName = new char[LENGTH];

	for(unsigned i = 0; i <	LENGTH; ++i) *(opName + i) = 0;
}

OperationBuilder::OperationBuilder(OperationBuilder& opB)
{
	copy(opB);
}

OperationBuilder::~OperationBuilder()
{
	delete opName;
}

OperationBuilder& OperationBuilder::operator = (OperationBuilder& opB)
{
	copy(opB);
	return *this;
}

OperationBuilder& OperationBuilder::with(char ch)
{
	Builder<Operation>::with(ch);
	++last;
	if(last >= LENGTH) throw BuildOperationException("Too long operation name \"" + string(opName) + ch + "\".");

	*(opName + last) = ch;

	return *this;
}

Operation* OperationBuilder::build()
{
	if(last < 0) throw BuildOperationException("Builder not initialised");
	Builder<Operation>::build();
	return Operation::getOperation(opName);
}
