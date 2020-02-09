#include "exception.h"

DefaultException::DefaultException(string msg):message(msg){};
string DefaultException::getMessage()
{
	return message;
}

StackException::StackException(string msg) : DefaultException(msg) {}

UnsuportedOperationException::UnsuportedOperationException(string operation) : DefaultException("Unsuported operation " + operation) {}
