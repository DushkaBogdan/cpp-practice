#ifndef _INTEGER_STACK_HPP_
#define _INTEGER_STACK_HPP_

#include "integer_vector.hpp"
#include <iostream>

struct IntegerStack
{
	IntegerVector m_pVector;
};

IntegerStack *IntegerStackCreate();

void IntegerStackDestroy(IntegerStack *_pStack);

void IntegerStackClear(IntegerStack &_pStack);

bool IntegerStackIsEmpty(const IntegerStack &_pStack);

bool IntegerStackIsFull(const IntegerStack &_pStack);

void IntegerStackPush(IntegerStack &_pStack, int _data);

void IntegerStackPop(IntegerStack &_pStack);

int IntegerStackTop(const IntegerStack &_pStack);

void IntegerStackRead(IntegerStack &_pStack, std::istream &_stream);

void IntegerStackReadTillZero(IntegerStack &_pStack, std::istream &_stream);

void IntegerStackPrint(const IntegerStack &_pStack, std::ostream &_stream, char _sep = ' ');

#endif //_INTEGER_STACK_HPP_