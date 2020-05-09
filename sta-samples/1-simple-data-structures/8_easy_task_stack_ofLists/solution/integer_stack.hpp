#ifndef _INTEGER_STACK_HPP_
#define _INTEGER_STACK_HPP_

#include <iostream>
#include "integer_list.hpp"

struct IntegerStack;

IntegerStack *IntegerStackCreate(int _size);

void IntegerStackDestroy(IntegerStack *_pStack);

void IntegerStackClear(IntegerStack &_stack);

bool IntegerStackIsEmpty(const IntegerStack &_stack);

bool IntegerStackIsFull(const IntegerStack &_stack);

void IntegerStackPush(IntegerStack &_stack, IntegerList &_list);

void IntegerStackPop(IntegerStack &_stack);

IntegerList IntegerStackTop(const IntegerStack &_stack);

void IntegerStackPrint(const IntegerStack &_stack, std::ostream &_stream, char _sep = ' ');

#endif // _INTEGER_STACK_HPP_


