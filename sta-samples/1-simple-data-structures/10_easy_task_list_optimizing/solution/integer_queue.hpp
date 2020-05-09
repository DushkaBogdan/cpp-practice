#ifndef _INTEGER_QUEUE_HPP_
#define _INTEGER_QUEUE_HPP_

#include "integer_list.hpp"

struct IntegerQueue
{
	IntegerList m_pList;
};

IntegerQueue *IntegerQueueCreate();

void IntegerQueueDestroy(IntegerQueue *_q);

void IntegerQueueClear(IntegerQueue &_q);

bool IntegerQueueIsEmpty(const IntegerQueue &_q);

int IntegerQueueSize(const IntegerQueue &_q);

bool IntegerQueueIsFull(const IntegerQueue &_q);

void IntegerQueuePush(IntegerQueue &_q, int _data);

void IntegerQueuePop(IntegerQueue &_q);

int IntegerQueueTop(const IntegerQueue &_q);

void IntegerQueueReadTillZero(IntegerQueue &_q, std::istream &_stream);

void IntegerQueuePrint(const IntegerQueue &_q, std::ostream &_stream);

#endif //_INTEGER_QUEUE_HPP_