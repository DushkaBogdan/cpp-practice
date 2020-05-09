#ifndef _STRING_VECTOR_HPP_
#define _STRING_VECTOR_HPP_

#include <iostream>

struct StringVector
{
	char **m_pString;
	int m_nAllocated;
	int m_nUsed;
};

void StringVectorInit(StringVector &_v, int _nAllocated = 10);

void StringVectorDestroy(StringVector &_v);

void StringVectorClear(StringVector &_v);

bool StringVectorIsEmpty(const StringVector &_v);

void StringVectorPushBack(StringVector &_v, const char *_str);

void StringVectorPushFront(StringVector &_v, const char *_str);

void StringVectorInsertAt(StringVector &_v, int _position, const char *_str);

void StringVectorPopBack(StringVector &_v);

void StringVectorPopFront(StringVector &_v);

void StringVectorDeleteAt(StringVector &_v, int _position);

void StringVectorRead(StringVector &_v, std::istream &_stream);

void StringVectorPrint(const StringVector &_v, std::ostream &_stream, char _sep = '\n');

#endif //_STRING_VECTOR_HPP_

