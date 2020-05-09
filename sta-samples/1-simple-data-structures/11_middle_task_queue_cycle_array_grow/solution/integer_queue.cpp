#include "integer_queue.hpp"
#include <cassert>

struct IntegerQueue
{
	int *m_pData;
	int m_Size;
	int FrontIndex;
	int BackIndex;
};

IntegerQueue *IntegerQueueCreate(int _Allocated)
{
	IntegerQueue *pQueue = new IntegerQueue;

	pQueue->m_pData = new int[_Allocated+1];
	pQueue->m_Size = _Allocated+1;
	pQueue->FrontIndex = 0;
	pQueue->BackIndex = 0;

	return pQueue;
}

void IntegerQueueDestroy(IntegerQueue *_pQueue)
{
	delete[]_pQueue->m_pData;
	delete _pQueue;
}

void IntegerQueueClear(IntegerQueue &_queue)
{
	_queue.BackIndex = _queue.FrontIndex = 0;
}

bool IntegerQueueIsEmpty(const IntegerQueue &_q)
{
	return (IntegerQueueSize(_q) == 0);
}

bool IntegerQueueIsFull(const IntegerQueue &_q)
{
	return false;
}

int GetNextIndex(const IntegerQueue &_q, int _index)
{
	int Index = _index + 1;
	if (Index == _q.m_Size)
		Index = 0;
	return Index;
}

int IntegerQueueSize(const IntegerQueue &_q)
{
	return (_q.BackIndex >= _q.FrontIndex) ?
		 (_q.BackIndex - _q.FrontIndex):
	(_q.m_Size + _q.BackIndex - _q.FrontIndex);
}

void IntegerQueueGrow(IntegerQueue &_q)
{
	int nSize = _q.m_Size * 2;
	int *nArr = new int[nSize];

	memcpy(nArr, _q.m_pData, sizeof(int)*(_q.m_Size));
	delete[] _q.m_pData;
	_q.m_pData = nArr;
	_q.m_Size = nSize;
}
void GrowAndPushBack(IntegerQueue &_q)
{
	int Statbackposition = _q.m_Size;
	int backposition = _q.m_Size - 1;

	IntegerQueueGrow(_q);

	for (int i = _q.m_Size; i > (_q.m_Size - (Statbackposition - _q.FrontIndex)); i--)
	{
		_q.m_pData[i - 1] = _q.m_pData[backposition--];
	}
	_q.FrontIndex = (_q.m_Size - (Statbackposition - _q.FrontIndex));
}

void IntegerQueuePush(IntegerQueue &_q, int _data)
{
	if (IntegerQueueSize(_q) == (_q.m_Size-1))
	{
		if (_q.FrontIndex > _q.BackIndex)
			GrowAndPushBack(_q);
		else
			IntegerQueueGrow(_q);
	}
		_q.m_pData[_q.BackIndex] = _data;
		_q.BackIndex = GetNextIndex(_q, _q.BackIndex);
}

void IntegerQueuePop(IntegerQueue &_q)
{
	assert(!IntegerQueueIsEmpty(_q));
	_q.FrontIndex = GetNextIndex(_q, _q.FrontIndex);
}

int IntegerQueueFront(const IntegerQueue &_q)
{
	assert(!IntegerQueueIsEmpty(_q));
	return _q.m_pData[_q.FrontIndex];
}

void IntegerQueuePrint(const IntegerQueue &_q, std::ostream &_stream, char _sep)
{
	assert(!IntegerQueueIsEmpty(_q));

	if (_q.BackIndex > _q.FrontIndex)
		for (int i = _q.FrontIndex; i < _q.BackIndex; i++)
		{
			
			_stream << _q.m_pData[i] << _sep;
		}
	else
	{
		for (int i = _q.FrontIndex; i <_q.m_Size; i++)
			_stream << _q.m_pData[i] << _sep;
		for (int i = 0; i < _q.BackIndex; i++)
			_stream << _q.m_pData[i] << _sep;
		
	}
}