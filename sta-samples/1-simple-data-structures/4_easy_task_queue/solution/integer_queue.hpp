#ifndef _INTEGER_QUEUE_HPP_
#define _INTEGER_QUEUE_HPP_

#include "integer_list_point.hpp"

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

void IntegerQueuePush(IntegerQueue &_q, Point3D _p);

void IntegerQueuePop(IntegerQueue &_q);

Point3D IntegerQueueTop(const IntegerQueue &_q);

void IntegerQueuePrint(const IntegerQueue &_q);

#endif //_INTEGER_QUEUE_HPP_





