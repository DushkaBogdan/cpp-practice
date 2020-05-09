#include "integer_vector_for_cmplx.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void IntegerVectorInit(IntegerVector & _vector, int _allocatedSize)
{
	_vector.m_pCplx = new Complex[_allocatedSize];
	_vector.m_nAllocated = _allocatedSize;
	_vector.m_nUsed = 0;
}


void IntegerVectorDestroy(IntegerVector & _vector)
{
	delete[] _vector.m_pCplx;
}


void IntegerVectorClear(IntegerVector & _vector)
{
	_vector.m_nUsed = 0;
}


bool IntegerVectorIsEmpty(const IntegerVector & _vector)
{
	return _vector.m_nUsed == 0;
}


void IntegerVectorGrow(IntegerVector & _vector)
{
	int nAllocatedNew = _vector.m_nAllocated * 2;
	Complex * pNewData = new Complex[nAllocatedNew];

	memcpy(pNewData, _vector.m_pCplx, sizeof(Complex) * _vector.m_nAllocated);

	delete[] _vector.m_pCplx;
	_vector.m_pCplx = pNewData;

	_vector.m_nAllocated = nAllocatedNew;
}


void IntegerVectorPushBack(IntegerVector & _vector, Complex _data)
{
	if (_vector.m_nUsed == _vector.m_nAllocated)
		IntegerVectorGrow(_vector);

	_vector.m_pCplx[_vector.m_nUsed++] = _data;
}



void IntegerVectorPopBack(IntegerVector & _vector)
{
	assert(!IntegerVectorIsEmpty(_vector));

	--_vector.m_nUsed;
}


void IntegerVectorRead(IntegerVector & _vector, std::istream & _stream)
{
	while (true)
	{
		std::cout << "Input pair for complex: ";
		Complex temp;
		_stream >> temp.m_imaginary >> temp.m_real;
		if (_stream)
			IntegerVectorPushBack(_vector, temp);
		else
			break;
	}
}


void IntegerVectorPrint(const IntegerVector & _vector, std::ostream & _stream, char _sep)
{
	for (int i = 0; i < _vector.m_nUsed; i++)
	{
		_stream << "Your m_pCplx m_imaginary of " << i << " = " << _vector.m_pCplx[i].m_imaginary <<_sep;
		_stream << "Your m_pCplx m_real of " << i << " = " << _vector.m_pCplx[i].m_real << std::endl;
	}
	_stream << std::endl;
}


void IntegerVectorInsertAt(IntegerVector & _vector, int _position, Complex _data)
{
	assert(_position >= 0 && _position < _vector.m_nUsed);

	int newUsed = _vector.m_nUsed + 1;
	if (newUsed > _vector.m_nAllocated)
		IntegerVectorGrow(_vector);

	for (int i = _vector.m_nUsed; i > _position; i--)
		_vector.m_pCplx[i] = _vector.m_pCplx[i - 1];

	_vector.m_pCplx[_position] = _data;

	_vector.m_nUsed = newUsed;
}


void IntegerVectorDeleteAt(IntegerVector & _vector, int _position)
{
	assert(_position >= 0 && _position < _vector.m_nUsed);

	for (int i = _position + 1; i < _vector.m_nUsed; i++)
		_vector.m_pCplx[i - 1] = _vector.m_pCplx[i];

	--_vector.m_nUsed;
}
