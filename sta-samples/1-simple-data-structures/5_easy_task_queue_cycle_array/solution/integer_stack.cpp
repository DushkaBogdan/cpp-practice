#include "integer_stack.hpp"
#include "integer_vector.cpp"

IntegerStack *IntegerStackCreate()
{
	IntegerStack *p_Stack = new IntegerStack;
	IntegerVectorInit(p_Stack->m_pVector);

	return p_Stack;
}

void IntegerStackDestroy(IntegerStack *_pStack)
{
	IntegerVectorDestroy(_pStack->m_pVector);
	delete _pStack;
}

void IntegerStackClear(IntegerStack &_pStack)
{
	InegerVectorClear(_pStack.m_pVector);
}

bool IntegerStackIsEmpty(const IntegerStack &_pStack)
{
	return IntegerVectorIsEmpty(_pStack.m_pVector);
}

bool IntegerStackIsFull(const IntegerStack &_pStack)
{
	return false;
}

void IntegerStackPush(IntegerStack &_pStack, int _data)
{
	IntegerVectorPushBack(_pStack.m_pVector, _data);
}

void IntegerStackPop(IntegerStack &_pStack)
{
	IntegerVectorPopBack(_pStack.m_pVector);
}

int IntegerStackTop(const IntegerStack &_pStack)
{
	return _pStack.m_pVector.m_pData[_pStack.m_pVector.m_nUsed-1];
}

void IntegerStackRead(IntegerStack &_pStack, std::istream &_stream)
{
	IntegerVectorRead(_pStack.m_pVector, _stream);
}

void IntegerStackReadTillZero(IntegerStack &_pStack, std::istream &_stream)
{
	IntegerVectorReadTillZero(_pStack.m_pVector, _stream);
}

void IntegerStackPrint(const IntegerStack &_pStack, std::ostream &_stream, char _sep)
{
	IntegerVectorPrint(_pStack.m_pVector, _stream);
}