#pragma once
#if !defined(BUILDER)
#define BUILDER
#include "exception.h"

template<class T>
class Builder
{
protected:
	bool builded;

	Builder();
public:
	virtual Builder<T>& with(char) = 0;
	virtual T build() = 0;
};

template<class T>
Builder<T>::Builder():builded(false) {};

template<class T>
Builder<T>& Builder<T>::with(char ch)
{
	if(builded) throw BuildException("Using finished builder");
	return *this;
}

template<class T>
T Builder<T>::build()
{
	if(builded) throw BuildException("Using finished builder");
	builded = true;
	return NULL;
}
#endif
#include "builder.h"
