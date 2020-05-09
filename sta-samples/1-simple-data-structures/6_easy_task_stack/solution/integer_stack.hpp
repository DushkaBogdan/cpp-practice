#ifndef _INTEGER_STACK_HPP_
#define _INTEGER_STACK_HPP_

#include <iostream>

#include "integer_vector_for_cmplx.hpp"

struct IntegerStack;

IntegerStack *IntegerStackCreate();

void IntegerStackDestroy(IntegerStack * _pStack);

void IntegerStackClear(IntegerStack &_stack);

bool IntegerStackIsEmpty(const IntegerStack &_stack);

bool IntgerStackIsFull(const IntegerStack &_stack);

void IntegerStackPush(IntegerStack &_stack, Complex _cplx);

void IntegerStackPop(IntegerStack &_stack);

Complex IntegerStackTop(const IntegerStack &_stack);

void IntegerStackRead(IntegerStack &_stack);

void IntegerStackPrint(IntegerStack &_stack, std::ostream &_stream, char _sep = ' ');

#endif //_INTEGER_STACK_HPP_

