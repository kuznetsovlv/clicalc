#pragma once
#if !defined(EXCEPTION)
#define EXCEPTION
#include <string>
using namespace std;

class Exception
{
public:
	virtual string getMessage() = 0;
};

class DefaultException : public Exception
{
	string message;

public:
	DefaultException(string msg);

	string getMessage();
};

class StackException : public DefaultException
{
public:
	StackException(string);
};

class UnsuportedOperationException : public DefaultException
{
public:
	UnsuportedOperationException(string);
};

class BuildException : public DefaultException
{
public:
	BuildException(string);
};

class BuildOperationException : public BuildException
{
public:
	BuildOperationException(string);
};
#endif
