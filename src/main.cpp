#include <iostream>
#include "exception.h"
#include "stack.h"
#include "operation.h"
using namespace std;

int main(int argc, char **args)
{
	Stack<long double> s;

	PowerOperation pw;
	ProductOperation pd;
	DivideOperation d;
	SumOperation sm;
	SubstrOperation sb;

	cout << pw.getPriority() << endl << pd.getPriority() << endl << d.getPriority() << endl << sm.getPriority() << endl << sb.getPriority() << endl;

	for(int i = 0; i < 10; ++i)
		s.push(static_cast<long double>(i));

	cout << pw.complete(s) << endl;
	cout << pd.complete(s) << endl;
	cout << d.complete(s) << endl;
	cout << sm.complete(s) << endl;
	cout << sb.complete(s) << endl;
	return 0;
}
