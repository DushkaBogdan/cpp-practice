#ifndef _INTEGER_LIST_HPP_
#define _INTEGER_LIST_HPP_

#include <iostream>

struct Point3D
{
	float m_x, m_y, m_z;
};

void PointCreate(Point3D &_p, float _x, float _y, float _z);

/*===========================================================================================================*/

struct IntegerList
{
	struct Node
	{
		Point3D m_Data;
		Node *m_pNext;
	};
	Node *m_pFirst, *m_pLast;
};

void IntegerListInit(IntegerList &_list);

void IntegerListDestroy(IntegerList &_list);

bool IntegerListIsEmpty(const IntegerList & _list);

void IntegerListPushBack(IntegerList &_list, Point3D &_p);

void IntegerListPushFront(IntegerList &_list, Point3D &_p);

void IntegerListInsertAfter(IntegerList &_list, IntegerList::Node *_pPrev, Point3D &_p);

void IntegerListInsertBefore(IntegerList &_list, IntegerList::Node *_pPrev, Point3D &_p);

void IntegerListPopBack(IntegerList &_list);

void IntegerListPopFront(IntegerList &_list);

void IntegerListDeleteAfter(IntegerList &_list, IntegerList::Node *_pPrev);

void IntegerListDeleteBefore(IntegerList &_list, IntegerList::Node *_pNext);

void IntegerListRead(IntegerList &_list, std::istream &_stream);

void IntegerListPrint(const IntegerList &_list, std::ostream &_stream, char _sep = ' ');


#endif //_INTEGER_LIST_HPP_


