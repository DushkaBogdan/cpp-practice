#include "integer_stack.hpp"
#include <cassert>

struct IntegerStack
{
	IntegerList *m_pData;
	IntegerList *m_pTop;
	int m_size;
};

IntegerStack *IntegerStackCreate(int _size)
{
	IntegerStack *pStack = new IntegerStack;
	pStack->m_pData = new IntegerList[_size];
	pStack->m_pTop = pStack->m_pData;
	pStack->m_size = _size;

	return pStack;
}

int IntegerStackGetSize(const IntegerStack &_stack)
{
	return (_stack.m_pTop - _stack.m_pData);
}

void IntegerStackDestroy(IntegerStack *_pStack)
{
	for (int i = 0; i < IntegerStackGetSize(*_pStack); i++)
		IntegerListDestroy(_pStack->m_pData[i]);

	delete[]_pStack->m_pData;
	delete _pStack;
}

void IntegerStackClear(IntegerStack &_stack)
{
	_stack.m_pTop = _stack.m_pData;
}

bool IntegerStackIsEmpty(const IntegerStack &_stack)
{
	return _stack.m_pData == _stack.m_pTop;
}

bool IntegerStackIsFull(const IntegerStack &_stack)
{
	return (_stack.m_pTop - _stack.m_pData) == _stack.m_size;
}

void IntegerStackPush(IntegerStack &_stack, IntegerList &_list)
{
	assert(!IntegerStackIsFull(_stack));
	*_stack.m_pTop = _list;
	++_stack.m_pTop;
}

void IntegerStackPop(IntegerStack &_stack)
{
	assert(!IntegerStackIsEmpty(_stack));
	IntegerListDestroy(*(_stack.m_pTop-1));
	--_stack.m_pTop;
}

IntegerList IntegerStackTop(const IntegerStack &_stack)
{
	return *(_stack.m_pTop - 1);
}

void IntegerStackPrint(const IntegerStack &_stack, std::ostream &_stream, char _sep)
{
	assert(!IntegerStackIsEmpty(_stack));

	for (int i = 0; i < IntegerStackGetSize(_stack); i++) //(_stack.m_pTop - _stack.m_pData)
	{
		IntegerListPrint(_stack.m_pData[i], _stream);
		_stream << std::endl;
	}
}

