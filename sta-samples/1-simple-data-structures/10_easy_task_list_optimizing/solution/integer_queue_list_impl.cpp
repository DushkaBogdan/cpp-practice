#include "integer_queue.hpp"
#include "integer_list.cpp"

IntegerQueue *IntegerQueueCreate()
{
	IntegerQueue *p_Queue = new IntegerQueue;

	IntegerListInit(p_Queue->m_pList);

	return p_Queue;
}

void IntegerQueueDestroy(IntegerQueue *_q)
{
	IntegerListDestroy(_q->m_pList);

	delete _q;
}

void IntegerQueueClear(IntegerQueue &_q)
{
	IntegerListDestroy(_q.m_pList);
}

bool IntegerQueueIsEmpty(const IntegerQueue &_q)
{
	return IntegerListIsEmpty(_q.m_pList);
}

int IntegerQueueSize(const IntegerQueue &_q)
{
	int counter = 0;
	IntegerList::Node *pCurrent = _q.m_pList.m_pFirst;
	while (pCurrent)
	{
		++counter;
		pCurrent = pCurrent->m_pNext;
	}
	return counter;
}

bool IntegerQueueIsFull(const IntegerQueue &_q)
{
	return false;
}

void IntegerQueuePush(IntegerQueue &_q, int _p)
{
	IntegerListPushBack(_q.m_pList, _p);
}

void IntegerQueuePop(IntegerQueue &_q)
{
	IntegerListPopFront(_q.m_pList);
}

int IntegerQueueTop(const IntegerQueue &_q)
{
	return _q.m_pList.m_pFirst->m_value;
}

void IntegerQueueReadTillZero(IntegerQueue &_q, std::istream &_stream)
{
	IntegerListReadTillZero(_q.m_pList, _stream);
}

void IntegerQueuePrint(const IntegerQueue &_q, std::ostream &_stream)
{
	assert(!IntegerQueueIsEmpty(_q));
	IntegerListPrint(_q.m_pList, _stream);
}