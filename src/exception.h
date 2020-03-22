#pragma once
#if !defined(EXCEPTION)
#define EXCEPTION
#include <string>
#include <exception>

class Exception : public std::exception
{
	std::string message;

public:
	Exception(std::string);
	Exception(std::exception&);

	std::string getMessage();
	std::string what();
};

class StackException : public Exception
{
public:
	StackException(std::string);
	StackException(std::exception&);
};

class UnsuportedOperationException : public Exception
{
public:
	UnsuportedOperationException(std::string);
	UnsuportedOperationException(std::exception&);
};

class BuildException : public Exception
{
public:
	BuildException(std::string);
	BuildException(std::exception&);
};

class BuildOperationException : public BuildException
{
public:
	BuildOperationException(std::string);
	BuildOperationException(std::exception&);
};

class BuildValueException : public BuildException
{
public:
	BuildValueException(std::string);
	BuildValueException(std::exception&);
};

class ExpressionException : public BuildException
{
public:
	ExpressionException(std::string);
	ExpressionException(std::exception&);
};

class UnbalancedParenthesesException : public ExpressionException
{
public:
	UnbalancedParenthesesException(std::string);
	UnbalancedParenthesesException(std::exception&);
};
#endif
