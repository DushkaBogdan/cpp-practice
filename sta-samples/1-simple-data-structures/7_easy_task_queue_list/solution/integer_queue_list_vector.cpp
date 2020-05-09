#include "integer_queue_list_vector.hpp"
#include "integer_list_for_vector.hpp"
#include <cassert>

struct IntegerQueue
{
	IntegerList m_list;
};

IntegerQueue *IntegerQueueCreate()
{
	IntegerQueue *m_pQueue = new IntegerQueue;
	IntegerListInit(m_pQueue->m_list);

	return m_pQueue;
}

void IntegerQueueDestroy(IntegerQueue *_pQueue)
{
	IntegerListDestroy(_pQueue->m_list);

	delete _pQueue;
}

void IntegerQueueClear(IntegerQueue &_queue)
{
	IntegerListDestroy(_queue.m_list);
}

bool IntegerQueueIsEmpty(const IntegerQueue &_queue)
{
	return IntegerListIsEmpty(_queue.m_list);
}

bool IntegerQueueIsFull(IntegerQueue &_queue)
{
	return false;
}

void IntegerQueuePush(IntegerQueue &_queue, IntegerVector &_v)
{
	IntegerListPushBack(_queue.m_list, _v);
}

void IntegerQueuePop(IntegerQueue &_queue)
{
	assert(!IntegerQueueIsEmpty(_queue));
	IntegerListPopFront(_queue.m_list);
}

int IntegerQueueSize(const IntegerQueue &_queue)
{
	int size = 0;
	if (IntegerQueueIsEmpty(_queue))
		return size;
	else
	{
		IntegerList::Node *pCurrent = _queue.m_list.m_pFirst;
		while (pCurrent)
		{
			++size;
			pCurrent = pCurrent->m_pNext;
		}
		return size;
	}
}

IntegerVector IntegerQueueFrontData(const IntegerQueue &_queue)
{
	assert(!IntegerQueueIsEmpty(_queue));
	return _queue.m_list.m_pFirst->_vector;
}

void IntegerQueuePrint(IntegerQueue &_queue, std::ostream &_stream)
{
	IntegerListPrint(_queue.m_list, _stream);
}