#ifndef _LIST_HPP_

#define _LIST_HPP_
#endif // _LIST_HPP_

#include <iostream>
struct List
{
	struct Node
	{
		int m_data;
		Node *m_pNext, *m_pPrev;
	};
	Node *m_pFirst, *m_pLast;
};

void ListInit(List & _l);
void ListDestr(List & _l);
void ListClear(List & _l);
bool ListIsEmpty(const List & _l);
void ListPushBack(List & _l, int _data);
void ListPushFront(List & _l, int _data);
void InsertAfter(List & _l, List::Node *_pPrev, int _data);
void InsertBefore(List & _l, List::Node *_pNext, int _data);
void PopBack(List & _l);
void PopFront(List & _l);
void DeleteAfter(List & _l, List::Node *pPrev);
void DeleteBefore(List & _l, List::Node *pNext);
void ListRead(List & _l, std::istream &_stream);
void ListReadTillZero(List & _l, std::istream &_stream);
void ListPrint(const List & _l, std::ostream &_stream, char _sep = ' ');



