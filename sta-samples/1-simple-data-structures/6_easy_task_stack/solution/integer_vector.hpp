#ifndef _INTEGER_VECTOR_HPP_
#define _INTEGER_VECTOR_HPP_

#include <iostream>

struct IntegerVector
{
	int *m_pData;
	int m_nAllocated;
	int m_nUsed;
};;

void IntegerVectorInit(IntegerVector &_vector, int _Allocated = 10);

void IntegerVectorDestroy(IntegerVector & _vector);

void InegerVectorClear(IntegerVector & _vector);

bool IntegerVectorIsEmpty(const IntegerVector & _vector);

void IntegerVectorPushBack(IntegerVector & _vector, int _data);

void IntegerVectorPushFront(IntegerVector & _vector, int _data);

void IntegerVectorPopBack(IntegerVector & _vector);

void IntegerVectorPopFront(IntegerVector & _vector);

void IntegerVectorInsertAt(IntegerVector & _vector, int _position, int _data);

void IntegerVectorDeleteAt(IntegerVector & _vector, int _position);

void IntegerVectorRead(IntegerVector & _vector, std::istream & _stream);

void IntegerVectorReadTillZero(IntegerVector & _vector, std::istream & _stream);

void IntegerVectorPrint(IntegerVector & _vector, std::ostream & _stream, char _sep = ' ');

#endif //_INTEGER_VECTOR_HPP_


