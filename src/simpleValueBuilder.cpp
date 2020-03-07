#include <cmath>
#include "valueBuilder.h"
#include "simpleValueBuilder.h"
using namespace std;

SimpleValueBuilder::SimpleValueBuilder():ValueBuilder(),str(""),withDecimal(false),exp(0),started(false),b(nullptr){};

SimpleValueBuilder& SimpleValueBuilder::with(char ch)
{
	ValueBuilder::with(ch);
	if(ch != ' ' && ch != '\t')
	{
		if(b)
		{
			b->with(ch);
			return *this;
		}
		switch (ch)
		{
			case '.':
				if(withDecimal)
				{
					throw BuildValueException("Dublicated separator.");
				}
				withDecimal = true;
				break;
			case '-':
			case '+':
				if(started)
				{
					throw BuildValueException(string("Symbol ") + ch + " is not available except of begining.");
				}
				break;
			case 'e':
			case 'E':
				b = new SimpleValueBuilder();
				return *this;
			default:
				if(ch < '0' || ch > '9')
				{
					throw BuildValueException(string("Unsuported symbol: \"") + ch + "\".");
				}
				else if(withDecimal)
				{
					++exp;
				}
		}
		str += ch;
		started = true;
	}

	return *this;
}

long double* SimpleValueBuilder::build()
{
	ValueBuilder::build();

	long double *v = new(long double);
	try
	{
		long double tmp = pow(10, exp);
		*v = trunc(tmp * stold(str)) / tmp;
		if(b)
		{
			*v *= pow(10, *(b->build()));
		}
	}
	catch(exception& e)
	{
		throw BuildValueException(e);
	}
	return v;
}
