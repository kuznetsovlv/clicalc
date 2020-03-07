#include "exception.h"
using namespace std;

Exception::Exception(string msg):message(msg){}
Exception::Exception(exception& exception):message(exception.what()){}
string Exception::getMessage()
{
	return message;
}
string Exception::what()
{
	return message;
}

StackException::StackException(string msg):Exception(msg) {}
StackException::StackException(exception& exception):Exception(exception){}

UnsuportedOperationException::UnsuportedOperationException(string operation):Exception("Unsuported operation " + operation) {}
UnsuportedOperationException::UnsuportedOperationException(exception& exception):Exception("Unsuported operation: " + string(exception.what())){}

BuildException::BuildException(string msg):Exception(msg) {}
BuildException::BuildException(exception& exception):Exception(exception) {}

BuildOperationException::BuildOperationException(string msg):BuildException(msg) {}
BuildOperationException::BuildOperationException(exception& exception):BuildException(exception) {}

BuildValueException::BuildValueException(string msg):BuildException(msg) {}
BuildValueException::BuildValueException(exception& exception):BuildException(exception) {}
