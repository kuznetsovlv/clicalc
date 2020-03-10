#include <iostream>
#include "exception.h"
#include "calculate.h"
using namespace std;

int main(int argc, char **args)
{
	try
	{
		while(--argc)
		{
			cout << calculate(*(++args)) << endl;
		}
	}
	catch(exception e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}
