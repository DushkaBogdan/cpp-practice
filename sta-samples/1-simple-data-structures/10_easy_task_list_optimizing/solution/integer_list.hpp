#ifndef _INTEGER_LIST_HPP_
#define _INTEGER_LIST_HPP_

#include <string>

struct IntegerList
{
	struct Node
	{
		std::string m_Data;
		Node *m_pNext;
	};
	Node *m_pFirst, *m_pLast;
};

void IntegerListInit(IntegerList &_list);

void IntegerListDestroy(IntegerList *_list);

bool IntegerListIsEmpty(const IntegerList & _list);

void IntegerListPushBack(IntegerList &_list, std::string _str);

void IntegerListPushFront(IntegerList &_list, std::string _str);

void IntegerListInsertAfter(IntegerList &_list, IntegerList::Node *_pPrev, std::string _str);

void IntegerListInsertBefore(IntegerList &_list, IntegerList::Node *_pPrev, std::string _str);

void IntegerListPopBack(IntegerList &_list);

void IntegerListPopFront(IntegerList &_list);

void IntegerListDeleteAfter(IntegerList &_list, IntegerList::Node *_pPrev);

void IntegerListDeleteBefore(IntegerList &_list, IntegerList::Node *_pNext);

void IntegerListRead(IntegerList &_list, std::istream &_stream);

void IntegerListReadTillZero(IntegerList &_list, std::istream &_stream);

void IntegerListPrint(const IntegerList &_list, std::ostream &_stream, char _sep = ' ');


#endif //_INTEGER_LIST_HPP_


