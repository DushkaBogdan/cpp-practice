#include "IntegerVector.hpp"
#include <cassert>
#include <iostream>

IntegerVector::IntegerVector(int _size)
	:m_nAllocated(_size), m_nUsed(0)
{
	assert(m_nAllocated > 0);

	m_pData = new int[m_nAllocated];
}

IntegerVector::IntegerVector(const IntegerVector &_v)
	:m_nAllocated(_v.m_nAllocated), m_nUsed(_v.m_nUsed)
{
	m_pData = new int[m_nAllocated];
	memcpy(m_pData, _v.m_pData, sizeof(int)*m_nUsed); 
}

IntegerVector & IntegerVector::operator =(const IntegerVector &_v)
{
	if (&_v == this)
		return *this;

	delete[] m_pData;

	m_nAllocated = _v.m_nAllocated;
	m_nUsed = _v.m_nUsed;

	m_pData = new int[m_nAllocated];
	memcpy(m_pData, _v.m_pData, sizeof(int)*m_nUsed);

	return *this;
}

IntegerVector::~IntegerVector()
{
	delete[] m_pData;
	m_pData = nullptr;
}

void IntegerVector::Grow()
{
	int newSize = m_nAllocated << 1;
	int *pNewArr = new int[newSize];

	memcpy(pNewArr, m_pData, sizeof(int)*m_nUsed);

	delete[] m_pData;

	m_pData = pNewArr;
	m_nAllocated = newSize;	
}

void IntegerVector::clear()
{
	m_nUsed = 0;
}

bool IntegerVector::isEmpty() const
{
	return m_nUsed == 0;
}

void IntegerVector::pushBack(int _value)
{
	if (m_nAllocated == m_nUsed)
		Grow();
	m_pData[m_nUsed++] = _value;
}


void IntegerVector::popBack()
{
	m_nUsed--;
}
int IntegerVector::find(int _value) const
{
	for (int i = 0; i < m_nUsed; i++)
		if (m_pData[i] == _value)
			return i;

	return -1;
	
}
void IntegerVector::removeAt(int _index)
{
	for (int i = _index+1; i < m_nUsed; i++)
		m_pData[i-1] = m_pData[i];
	
	m_nUsed--;
}



IntegerVector::IntegerVector(IntegerVector &&_v)
	:m_nAllocated(_v.m_nAllocated), m_nUsed(_v.m_nUsed), m_pData(_v.m_pData)
{
	_v.m_nUsed = 0;
	_v.m_nAllocated = 10;
	_v.m_pData = nullptr;
}

IntegerVector & IntegerVector::operator =(IntegerVector &&_v)
{
	if (&_v == this)
		return *this;

	int alloc = _v.m_nAllocated;
	int nUsed = _v.m_nUsed;
	int* newpData = _v.m_pData;

	_v.m_nAllocated = m_nAllocated;
	_v.m_nUsed = m_nUsed;
	_v.m_pData = m_pData;

	m_nAllocated = alloc;
	m_nUsed = nUsed;
	m_pData = newpData;

	return *this;
}

bool IntegerVector::operator == (const IntegerVector &_v)const
{
	if (m_nUsed != _v.m_nUsed)
		return false;
	for (int i = 0; i < m_nUsed; i++)
		if (find(_v.m_pData[i]) == -1)
			return false;
	return true;
}

bool IntegerVector::operator != (const IntegerVector &_v)const
{
	return !(*this == _v);
}

void IntegerVector::printV(std::ostream &_o)
{
	for (int i = 0; i < m_nUsed; i++)
		_o << m_pData[i] << ' ';
	_o << '\n';
}