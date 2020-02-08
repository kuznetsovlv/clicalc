#include <iostream>
#include "exception.h"
#include "stack.h"
using namespace std;

int main(int argc, char **args)
{
	Stack<int> s;

	for(int i = 0; i < 10; ++i)
		s.push(i * i);

	while(!s.isEmpty())
		cout << s.pop() << endl;

	cout << s.pop() << endl;
	return 0;
}
