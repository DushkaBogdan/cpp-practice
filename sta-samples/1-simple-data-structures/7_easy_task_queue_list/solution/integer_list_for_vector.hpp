#ifndef _INTEGER_LIST_FOR_VECTOR_HPP_
#define _INTEGER_LIST_FOR_VECTOR_HPP_


#include "integer_vector.hpp"
#include <iostream>

struct IntegerList
{
	struct Node
	{
		IntegerVector _vector;
		Node * m_pNext;
	};
	Node *m_pFirst, *m_pLast;
};

void IntegerListInit(IntegerList &_list);

void IntegerListDestroy(IntegerList &_list);

bool IntegerListIsEmpty(const IntegerList &_list);

void IntegerListPushBack(IntegerList &_list, IntegerVector &_v);

void IntegerListPushFront(IntegerList &_list, IntegerVector &_v);

void IntegerListInsertAfter(IntegerList &_list, IntegerList::Node *_pPrev, IntegerVector &_v);

void IntegerListInsertBefore(IntegerList &_list, IntegerList::Node *_pNext, IntegerVector &_v);

void IntegerListPopBack(IntegerList &_list);

void IntegerListPopFront(IntegerList &_list);

void IntegerListDeleteAfter(IntegerList &_list, IntegerList::Node *_pPrev);

void IntegerListDeleteBefore(IntegerList &_list, IntegerList::Node *_pNext);

void IntegerListPrint(IntegerList &_list, std::ostream &_stream, char _sep = ' ');

#endif //_INTEGER_LIST_FOR_VECTOR_HPP_



