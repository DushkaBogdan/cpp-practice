#ifndef _INTEGER_QUEUE_HPP_
#define _INTEGER_QUEUE_HPP_

struct IntegerQueue;

IntegerQueue *IntegerQueueCreate(int _size);

void IntegerQueueDestroy(IntegerQueue *_q);

void IntegerQueueClear(IntegerQueue &_q);

bool IntegerQueueIsEmpty(const IntegerQueue &_q);

bool IntegerQueueIsFull(const IntegerQueue &_q);

int IntegerQueueSize(const IntegerQueue &_q);

void IntegerQueuePush(IntegerQueue &_q, double *_arr, int _size);

void IntegerQueuePop(IntegerQueue &_q);

double *IntegerQueueTop(const IntegerQueue &_q);

void IntegerQueuePrint(const IntegerQueue &_q);

#endif //_INTEGER_QUEUE_HPP_





