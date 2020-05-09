#include "integer_queue.hpp"
#include <cassert>
#include <iostream>

struct IntegerQueue
{
	double **m_pArrayofQueue;
	int *m_pArraySizes;
	int m_QueueSize;
	int m_FrontIndex;
	int m_BackIndex;
};

IntegerQueue *IntegerQueueCreate(int _size)
{
	assert(_size > 0);

	IntegerQueue *m_pQueue = new IntegerQueue;

	m_pQueue->m_QueueSize = _size + 1;
	m_pQueue->m_pArrayofQueue = new double*[_size+1];
	m_pQueue->m_pArraySizes = new int[_size+1];

	m_pQueue->m_FrontIndex = m_pQueue->m_BackIndex = 0;

	return m_pQueue;
}

void IntegerQueueDestroy(IntegerQueue *_q)
{
	delete[] _q->m_pArrayofQueue;
	delete _q;
}

void IntegerQueueClear(IntegerQueue &_q)
{
	_q.m_BackIndex = _q.m_FrontIndex = 0;
}

bool IntegerQueueIsEmpty(const IntegerQueue &_q)
{
	return IntegerQueueSize(_q) == 0;
}

int IntegerQueueSize(const IntegerQueue &_q)
{
	return (_q.m_BackIndex >= _q.m_FrontIndex) ?
		(_q.m_BackIndex - _q.m_FrontIndex) :
		(_q.m_QueueSize + _q.m_BackIndex - _q.m_FrontIndex);
}

bool IntegerQueueIsFull(const IntegerQueue &_q)
{
	return IntegerQueueSize(_q) == (_q.m_QueueSize - 1);
}

int getNextIndex(const IntegerQueue &_q, const int _index)
{
	int index = _index + 1;
	if (index == _q.m_QueueSize)
		index = 0;
	return index;
}

void IntegerQueuePush(IntegerQueue &_q, double *_arr, int _size)
{
	assert(!IntegerQueueIsFull(_q));

	_q.m_pArrayofQueue[_q.m_BackIndex] = _arr;
	_q.m_pArraySizes[_q.m_BackIndex] = _size;
	_q.m_BackIndex = getNextIndex(_q, _q.m_BackIndex);
}

void IntegerQueuePop(IntegerQueue &_q)
{
	assert(!IntegerQueueIsEmpty(_q));

	_q.m_FrontIndex = getNextIndex(_q, _q.m_FrontIndex);
}

double *IntegerQueueTop(const IntegerQueue &_q)
{
	assert(!IntegerQueueIsEmpty(_q));

	return _q.m_pArrayofQueue[_q.m_FrontIndex];
}

void IntegerQueuePrint(const IntegerQueue &_q)
{
	assert(!IntegerQueueIsEmpty(_q));

	for (int i = 0; i < IntegerQueueSize(_q); i++)
	{
		for (int j = 0; j < _q.m_pArraySizes[i]; j++)
			std::cout << _q.m_pArrayofQueue[i][j] << std::endl;
	}
}





