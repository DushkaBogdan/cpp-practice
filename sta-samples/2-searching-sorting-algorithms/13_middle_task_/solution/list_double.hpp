#ifndef _INTEGER_LIST_DOUBLE_HPP_
#define _INTEGER_LIST_DOUBLE_HPP_

#include <iostream>


struct IntegerList
{
	struct Node
	{
		char *m_date;
		double m_value;
		Node * m_pNext;
	};

	Node * m_pFirst, *m_pLast;
};


void IntegerListInit(IntegerList & _list);

void IntegerListDestroy(IntegerList & _list);

bool IntegerListIsEmpty(const IntegerList & _list);

int IntegerListSize(const IntegerList & _list);

void IntegerListClear(IntegerList & _list);

void IntegerListPushBack(IntegerList & _list, double _data,const char *_date);

void IntegerListPushFront(IntegerList & _list, double _data,const char *_date);

void IntegerListInsertAfter(IntegerList & _list, IntegerList::Node * _pPrevNode, double _data,const char *_date);

void IntegerListPrint(const IntegerList & _list, std::ostream & _o, char _sep = ' ');



#endif //  _INTEGER_LIST_DOUBLE_HPP_