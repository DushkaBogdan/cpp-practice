#ifndef _INTEGER_QUEUE_LIST_VECTOR_HPP_

#include <iostream>
#include "integer_vector.hpp"

struct IntegerQueue;

IntegerQueue *IntegerQueueCreate();

void IntegerQueueDestroy(IntegerQueue *_pQueue);

void IntegerQueueClear(IntegerQueue &_queue);

bool IntegerQueueIsEmpty(const IntegerQueue &_queue);

bool IntegerQueueIsFull(IntegerQueue &_queue);

void IntegerQueuePush(IntegerQueue &_queue, IntegerVector &_v);

void IntegerQueuePop(IntegerQueue &_queue);

int IntegerQueueSize(const IntegerQueue &_queue);

IntegerVector IntegerQueueFrontData(const IntegerQueue &_queue);

void IntegerQueuePrint(IntegerQueue &_queue, std::ostream &_stream);

#define _INTEGER_QUEUE_LIST_VECTOR_HPP_
#endif //_INTEGER_QUEUE_LIST_VECTOR_HPP_


