#ifndef _INTEGER_QUEUE_HPP_
#define _INTEGER_QUEUE_HPP_
#include <iostream>

struct IntegerQueue;

IntegerQueue *IntegerQueueCreate(int _Allocated);

void IntegerQueueDestroy(IntegerQueue *_pQueue);

void IntegerQueueClear(IntegerQueue &_queue);

bool IntegerQueueIsEmpty(const IntegerQueue &_q);

bool IntegerQueueIsFull(const IntegerQueue &_q);

int IntegerQueueSize(const IntegerQueue &_q);

void IntegerQueuePush(IntegerQueue &_q, int _data);

void IntegerQueuePop(IntegerQueue &_q);

int IntegerQueueFront(const IntegerQueue &_q);

void IntegerQueuePrint(const IntegerQueue &_q, std::ostream &_stream, char _sep = ' ');

#endif //_INTEGER_QUEUE_HPP_

