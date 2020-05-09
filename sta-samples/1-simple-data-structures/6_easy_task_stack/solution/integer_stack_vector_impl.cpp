#include "integer_stack.hpp"
#include "integer_vector_for_cmplx.hpp"
#include <cassert>

struct IntegerStack
{
	IntegerVector m_Vector;
};

IntegerStack *IntegerStackCreate()
{
	IntegerStack *m_pStack = new IntegerStack;

	IntegerVectorInit(m_pStack->m_Vector);

	return m_pStack;

}

void IntegerStackDestroy(IntegerStack * _pStack)
{
	IntegerVectorDestroy(_pStack->m_Vector);
	delete _pStack;
}

void IntegerStackClear(IntegerStack &_stack)
{
	_stack.m_Vector.m_nUsed = 0;
}

bool IntegerStackIsEmpty(const IntegerStack &_stack)
{
	return IntegerVectorIsEmpty(_stack.m_Vector);
}

bool IntgerStackIsFull(const IntegerStack &_stack)
{
	return false;
}

void IntegerStackPush(IntegerStack &_stack, Complex _cplx)
{
	IntegerVectorPushBack(_stack.m_Vector, _cplx);
}

void IntegerStackPop(IntegerStack &_stack)
{
	IntegerVectorPopBack(_stack.m_Vector);
}

Complex IntegerStackTop(const IntegerStack &_stack)
{
	assert(!IntegerStackIsEmpty(_stack));

	return _stack.m_Vector.m_pCplx[_stack.m_Vector.m_nUsed-1];
}

void IntegerStackRead(IntegerStack &_stack)
{
	IntegerVectorRead(_stack.m_Vector, std::cin);
}

void IntegerStackPrint(IntegerStack &_stack, std::ostream &_stream, char _sep)
{
	IntegerVectorPrint(_stack.m_Vector, _stream);
}