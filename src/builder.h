#pragma once
#if !defined(BUILDER)
#define BUILDER
#include "exception.h"

template<class T>
class WithChar
{
	virtual T& with(char) = 0;
};

template<class T>
class Builder : public WithChar<Builder<T>>
{
protected:
	bool built;

	Builder();
public:
	virtual Builder<T>& with(char) = 0;
	virtual T* build() = 0;
};

template<class T>
Builder<T>::Builder():built(false) {};

template<class T>
Builder<T>& Builder<T>::with(char ch)
{
	if(built) throw BuildException("Using finished builder");
	return *this;
}

template<class T>
T* Builder<T>::build()
{
	if(built) throw BuildException("Using finished builder");
	built = true;
	return NULL;
}
#endif
#include "builder.h"
