#include <iostream>
#include <string>
#include "exception.h"
#include "calculate.h"
using namespace std;

int main(int argc, char **args)
{
	try
	{
		while(--argc)
		{
			long double res = calculate(*(++args));
			cout << *args << " = " << res << endl;
		}
	}
	catch(exception& e)
	{
		cerr << "Error in " << *args << ": " << e.what() << endl;
	}
	return 0;
}
