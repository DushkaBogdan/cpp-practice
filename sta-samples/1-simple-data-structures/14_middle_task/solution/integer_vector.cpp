#include "integer_vector.hpp"
#include <cassert>

#include <iostream>



void IntegerVectorInit(IntegerVector &_vector, int _Allocated)
{
	_vector.m_pData = new int[_Allocated];
	_vector.m_nUsed = 0;
	_vector.m_nAllocated = _Allocated;
}

void IntegerVectorDestroy(IntegerVector & _vector)
{
	delete[] _vector.m_pData;
}

void InegerVectorClear(IntegerVector & _vector)
{
	delete[] _vector.m_pData;
	_vector.m_nUsed = 0;
}

bool IntegerVectorIsEmpty(const IntegerVector & _vector)
{
	return _vector.m_nUsed == 0;
}

void IntegerVectorGrow(IntegerVector &_vector)
{
	int newSize = _vector.m_nAllocated * 2;
	int *newArray = new int[newSize];

	memcpy(newArray, _vector.m_pData, sizeof(int)*_vector.m_nAllocated);

	delete[] _vector.m_pData;
	_vector.m_pData = newArray;
	_vector.m_nAllocated = newSize;
}

void IntegerVectorPushBack(IntegerVector & _vector, int _data)
{
	if (_vector.m_nUsed == _vector.m_nAllocated)
		IntegerVectorGrow(_vector);
	_vector.m_pData[_vector.m_nUsed++] = _data;
}

void IntegerVectorPushFront(IntegerVector & _vector, int _data)
{
	if (_vector.m_nUsed == _vector.m_nAllocated)
		IntegerVectorGrow(_vector);
	for (int i = _vector.m_nUsed + 1; i > 0; i--)
		_vector.m_pData[i] = _vector.m_pData[i - 1];
	_vector.m_pData[0] = _data;

	_vector.m_nUsed++;
}

void IntegerVectorPopBack(IntegerVector & _vector)
{
	assert(!IntegerVectorIsEmpty(_vector));

	--_vector.m_nUsed;
}

void IntegerVectorPopFront(IntegerVector & _vector)
{
	assert(!IntegerVectorIsEmpty(_vector));

	for (int i = 0; i < _vector.m_nUsed-1; i++)
		_vector.m_pData[i] = _vector.m_pData[i + 1];

	--_vector.m_nUsed;
}

void IntegerVectorInsertAt(IntegerVector & _vector, int _position, int _data)
{
	assert(!IntegerVectorIsEmpty(_vector));
	assert(_position >= 0 && _position <=_vector.m_nUsed);
	

	if (_vector.m_nUsed == _vector.m_nAllocated)
		IntegerVectorGrow(_vector);

	for (int i = _vector.m_nUsed + 1; i > _position; i--)
		_vector.m_pData[i] = _vector.m_pData[i - 1];

	_vector.m_pData[_position] = _data;
	++_vector.m_nUsed;
}

void IntegerVectorDeleteAt(IntegerVector & _vector, int _position)
{
	assert(!IntegerVectorIsEmpty(_vector));
	assert(_position >= 0 && _position <_vector.m_nUsed);

	for (int i = _position+1; i < _vector.m_nUsed; i++)
		_vector.m_pData[i-1] = _vector.m_pData[i];

	--_vector.m_nUsed;
}

void IntegerVectorRead(IntegerVector & _vector, std::istream &_stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream)
			IntegerVectorPushBack(_vector, temp);
		else
			break;
	}
	
}

void IntegerVectorReadTillZero(IntegerVector & _vector, std::istream &_stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream && temp !=0)
			IntegerVectorPushBack(_vector, temp);
		else
			break;
	}
}

void IntegerVectorPrint(IntegerVector & _vector, std::ostream & _stream, char _sep)
{
	assert(!IntegerVectorIsEmpty(_vector));

	for (int i = 0; i < _vector.m_nUsed; i++)
		_stream << _vector.m_pData[i] << _sep;
}