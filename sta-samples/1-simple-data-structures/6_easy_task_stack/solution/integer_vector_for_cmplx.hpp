#ifndef _INTEGER_VECTOR_FOR_CMPLX_HPP_
#define _INTEGER_VECTOR_FOR_CMPLX_HPP_

#include <iostream>

struct Complex
{
	float m_real, m_imaginary;
};

struct IntegerVector
{
	Complex *m_pCplx;
	int m_nUsed;
	int m_nAllocated;
};


void IntegerVectorInit(IntegerVector & _vector, int _allocatedSize = 10);

void IntegerVectorDestroy(IntegerVector & _vector);

void IntegerVectorClear(IntegerVector & _vector);

bool IntegerVectorIsEmpty(const IntegerVector & _vector);

void IntegerVectorPushBack(IntegerVector & _vector, Complex _cplx);

void IntegerVectorPopBack(IntegerVector & _vector);

void IntegerVectorInsertAt(IntegerVector & _vector, int _position, Complex _cplx);

void IntegerVectorDeleteAt(IntegerVector & _vector, int _position);

void IntegerVectorRead(IntegerVector & _vector, std::istream & _stream);

void IntegerVectorPrint(const IntegerVector & _vector, std::ostream & _stream, char _sep = ' ');


#endif //  _INTEGER_VECTOR_FOR_CMPLX_HPP_
