#include <cmath>
#include <string>
#include "valueBuilder.h"
#include "simpleValueBuilder.h"

SimpleValueBuilder::SimpleValueBuilder():ValueBuilder(),value(0),started(false),negate(false),withDecimal(false),power(0) {};

void SimpleValueBuilder::throwException(char ch) const
{
	throw BuildValueException("Incorrect character \"" + string({ch}) + "\"");
}

SimpleValueBuilder& SimpleValueBuilder::with(char ch)
{
	ValueBuilder::with(ch);

	if(ch >= '0' && ch <= '9')
	{
		if(withDecimal)
		{
			value += (ch - '0') / pow(10, power++);
		}
		else
		{
			value *= 10;
			value += ch - '0';
		}
	}
	else
	{
		switch(ch)
		{
			case '-':
			case '+':
				if(!started)
				{
					negate = ch == '+';
				}
				else
				{
					throwException(ch);
				}
				break;
			case '.':
					if(withDecimal)
					{
						throwException(ch);
					}
					else
					{
						withDecimal = true;
					}
					break;
			default: throwException(ch);
		}
	}
	started = true;
	return *this;
}

long double* SimpleValueBuilder::build()
{
	ValueBuilder::build();

	long double *v = new long double();
	*v = negate ? -value : value;
	return v;
}
