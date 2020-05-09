#include "integer_vector.hpp"

#include <cassert>

#include <iostream>

void IntegerVectorInit(IntegerVector &_v, int _Allocated)
{
	_v.m_pData = new int[_Allocated];
	_v.m_nAllocated = _Allocated;
	_v.m_nUsed = 0;
}

void IntegerVectorDestroy(IntegerVector &_v)
{
	delete[] _v.m_pData;
}

bool IntegerVectorIsEmpty(const IntegerVector &_v)
{
	return _v.m_nUsed == 0;
}

void IntegerVectorGrow(IntegerVector &_v)
{
	int newSize = _v.m_nAllocated * 2;
	int *newArr = new int[newSize];

	memcpy(newArr, _v.m_pData, sizeof(int)*_v.m_nUsed);

	delete _v.m_pData;
	_v.m_pData = newArr;
	_v.m_nAllocated = newSize;
}

void IntegerVectorPushBack(IntegerVector &_v, int _data)
{
	if (_v.m_nAllocated == _v.m_nUsed)
		IntegerVectorGrow(_v);
	_v.m_pData[_v.m_nUsed++] = _data;
}

void IntegerVectorPushFront(IntegerVector &_v, int _data)
{
	if (_v.m_nAllocated == _v.m_nUsed)
		IntegerVectorGrow(_v);
	for (int i = _v.m_nUsed; i > 0; i--)
	{
		_v.m_pData[i] = _v.m_pData[i - 1];
	}
	_v.m_pData[0] = _data;
	++_v.m_nUsed;

}

void IntegerVectorInsertAt(IntegerVector &_v, int _position, int _data)
{
	assert(_position >= 0 && _position < _v.m_nUsed);

	if (_v.m_nAllocated == _v.m_nUsed)
		IntegerVectorGrow(_v);
	
	for (int i = _v.m_nUsed; i > _position; i--)
	{
		_v.m_pData[i] = _v.m_pData[i - 1];
	}
	_v.m_pData[_position] = _data;
	++_v.m_nUsed;
}

void IntegerVectorPopBack(IntegerVector &_v)
{
	assert(!IntegerVectorIsEmpty(_v));

	--_v.m_nUsed;
}

void IntegerVectorPopFront(IntegerVector &_v)
{
	assert(!IntegerVectorIsEmpty(_v));

	for (int i = 1; i < _v.m_nUsed; i++)
	{
		_v.m_pData[i - 1] = _v.m_pData[i];
	}
	--_v.m_nUsed;
}

void IntegerVectorDeleteAt(IntegerVector &_v, int _position)
{
	assert(!IntegerVectorIsEmpty(_v));
	assert(_position >= 0 && _position < _v.m_nUsed);

	for (int i = _position+1; i < _v.m_nUsed; i++)
	{
		_v.m_pData[i - 1] = _v.m_pData[i];
	}
	--_v.m_nUsed;
}

void IntegerVectorPrint(IntegerVector &_v, std::ostream &_stream, char _sep)
{
	if (IntegerVectorIsEmpty(_v))
		_stream << "Vector is Empty!";
	else
		for (int i = 0; i < _v.m_nUsed; i++)
			_stream << _v.m_pData[i] << _sep;
}