#if !defined(STACK)
#define STACK
template<class T>
class Stack
{
	T value;
	bool empty;
	Stack<T> *next;

	void copy(Stack<T>&);

public:
	Stack();
	Stack(Stack<T>&);
	~Stack();

	void push(T);
	T pop();
	bool isEmpty();

	Stack<T>& operator = (Stack<T>&);
};

template<class T>
Stack<T>::Stack():empty(true),next(nullptr){};
template<class T>
Stack<T>::Stack(Stack<T>& stack)
{
	copty(stack);
}

template<class T>
Stack<T>::~Stack()
{
	if(next)
	{
		delete next;
	}
}

template<class T>
void Stack<T>::copy(Stack<T>& stack)
{
	empty = stack.isEmpty();
	next = nullptr;

	if(!empty)
	{
		value = stack.value;

		if(stack.next)
		{
			next = new Stack<T>(stack.next);
		}
	}
}

template<class T>
void Stack<T>::push(T v)
{
	if(!empty)
	{
		if(!next)
		{
			next = new Stack();

			if(!next)
			{
				throw StackException("Can not insert value into stack.");
			}
		}

		next->push(value);
	}
	else
	{
		empty = false;
	}

	value = v;
}
template<class T>
T Stack<T>::pop()
{
	if(empty)
	{
		throw StackException("Extracting value from empty stack.");
	}

	T v = value;

	if(next)
	{
		value = next->pop();
		if(next->isEmpty())
		{
			delete next;
			next = nullptr;
		}
	}
	else
	{
		empty = true;
	}

	return v;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return empty;
}

template<class T>
Stack<T>& Stack<T>::operator = (Stack<T>& stack)
{
	copy(stack);
	return this;
}
#endif
