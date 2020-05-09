#ifndef _INTEGER_VECTOR_HPP_
#define _INTEGER_VECTOR_HPP_

#include <iostream>

struct IntegerVector
{
	int *m_pData;
	int m_nAllocated;
	int m_nUsed;
};

void IntegerVectorInit(IntegerVector &_v, int _Allocated = 10);

void IntegerVectorDestroy(IntegerVector &_v);

void IntegerVectorClear(IntegerVector &_v);

bool IntegerVectorIsEmpty(const IntegerVector &_v);

void IntegerVectorPushBack(IntegerVector &_v, int _data);

void IntegerVectorPushFront(IntegerVector &_v, int _data);

void IntegerVectorInsertAt(IntegerVector &_v, int _position, int _data);

void IntegerVectorPopBack(IntegerVector &_v);

void IntegerVectorPopFront(IntegerVector &_v);

void IntegerVectorDeleteAt(IntegerVector &_v, int _position);

void IntegerVectorRead(IntegerVector &_v, std::istream &_stream);

void IntegerVectorReadTillZero(IntegerVector &_v, std::istream &_stream);

void IntegerVectorPrint(IntegerVector &_v, std::ostream &_stream, char _sep = ' ');

#endif //_INTEGER_VECTOR_HPP_




