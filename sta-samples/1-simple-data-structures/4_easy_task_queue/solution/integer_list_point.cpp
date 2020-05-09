#include "integer_list_point.hpp"
#include <cassert>

void PointCreate(Point3D &_p, float _x, float _y, float _z)
{
	_p.m_x = _x;
	_p.m_y = _y;
	_p.m_z = _z;
}

void IntegerListInit(IntegerList &_list)
{
	_list.m_pFirst = _list.m_pLast = nullptr;
}

void IntegerListDestroy(IntegerList &_list)
{
	IntegerList::Node *pCurrent = _list.m_pFirst;


	while (pCurrent)
	{
		IntegerList::Node *temp = pCurrent->m_pNext;
		delete pCurrent;
		pCurrent = temp;
	}

	_list.m_pFirst = _list.m_pLast = nullptr;
}

bool IntegerListIsEmpty(const IntegerList & _list)
{
	return _list.m_pFirst == nullptr;
}

void IntegerListPushBack(IntegerList &_list, Point3D &_p)
{
	IntegerList::Node *pNewNode = new IntegerList::Node;
	pNewNode->m_Data = _p;
	pNewNode->m_pNext = nullptr;

	if (IntegerListIsEmpty(_list))
		_list.m_pFirst = pNewNode;
	else
		_list.m_pLast->m_pNext = pNewNode;

	_list.m_pLast = pNewNode;
}

void IntegerListPushFront(IntegerList &_list, Point3D &_p)
{
	IntegerList::Node *pNewNode = new IntegerList::Node;
	pNewNode->m_Data = _p;

	if (IntegerListIsEmpty(_list))
	{
		_list.m_pLast = pNewNode;
		pNewNode->m_pNext = nullptr;
	}
	pNewNode->m_pNext = _list.m_pFirst;

	_list.m_pFirst = pNewNode;
}

void IntegerListInsertAfter(IntegerList &_list, IntegerList::Node *_pPrev, Point3D &_p)
{
	assert(!IntegerListIsEmpty(_list));

	if (_list.m_pLast == _pPrev)
		IntegerListPushBack(_list, _p);
	else
	{
		IntegerList::Node *pNewNode = new IntegerList::Node;
		pNewNode->m_Data = _p;

		pNewNode->m_pNext = _pPrev->m_pNext;
		_pPrev->m_pNext = pNewNode;
	}
}

void IntegerListInsertBefore(IntegerList &_list, IntegerList::Node *_pNext, Point3D &_p)
{
	assert(!IntegerListIsEmpty(_list));

	if (_list.m_pFirst == _pNext)
		IntegerListPushFront(_list, _p);
	else
	{
		IntegerList::Node *pNew = new IntegerList::Node;
		pNew->m_Data = _p;

		IntegerList::Node *pCurrent = _list.m_pFirst;

		while (pCurrent->m_pNext != _pNext)
		{
			pCurrent = pCurrent->m_pNext;
		}

		pNew->m_pNext = _pNext;
		pCurrent->m_pNext = pNew;

	}
}

void IntegerListPopBack(IntegerList &_list)
{
	assert(!IntegerListIsEmpty(_list));

	if (_list.m_pFirst == _list.m_pLast)
	{
		delete _list.m_pFirst;
		_list.m_pFirst = _list.m_pLast = nullptr;
	}
	IntegerList::Node *pCurrent = _list.m_pFirst;
	while (pCurrent->m_pNext != _list.m_pLast)
		pCurrent = pCurrent->m_pNext;

	pCurrent->m_pNext = nullptr;
	delete _list.m_pLast;
	_list.m_pLast = pCurrent;
}

void IntegerListPopFront(IntegerList &_list)
{
	assert(!IntegerListIsEmpty(_list));

	if (_list.m_pFirst == _list.m_pLast)
	{
		delete _list.m_pFirst;
		_list.m_pFirst = _list.m_pLast = nullptr;
	}
	else
	{
		IntegerList::Node *pDyingNode = _list.m_pFirst;
		_list.m_pFirst = pDyingNode->m_pNext;
		//pDyingNode->m_pNext = nullptr;
		delete pDyingNode;
	}

}

void IntegerListDeleteAfter(IntegerList &_list, IntegerList::Node *_pPrev)
{
	assert(!IntegerListIsEmpty(_list));
	assert(_pPrev != _list.m_pLast);

	if (_list.m_pLast == _pPrev->m_pNext)
		IntegerListPopBack(_list);
	else
	{
		IntegerList::Node *pDyingNode = _pPrev->m_pNext;

		_pPrev->m_pNext = pDyingNode->m_pNext;
		pDyingNode->m_pNext = nullptr;
		delete pDyingNode;
	}
}

void IntegerListDeleteBefore(IntegerList &_list, IntegerList::Node *_pNext)
{
	assert(!IntegerListIsEmpty(_list));
	assert(_pNext != _list.m_pFirst);

	if (_list.m_pFirst->m_pNext == _pNext)
		IntegerListPopFront(_list);
	else
	{

		IntegerList::Node *pPrev = _list.m_pFirst;
		IntegerList::Node *pCurrent = _list.m_pFirst->m_pNext;

		while (pCurrent && pCurrent->m_pNext != _pNext)
		{
			pPrev = pCurrent;
			pCurrent = pCurrent->m_pNext;
		}

		pPrev->m_pNext = _pNext;
		pCurrent->m_pNext = nullptr;
		delete pCurrent;
	}

}

void IntegerListRead(IntegerList &_list, std::istream &_stream)
{
	while (true)
	{
		Point3D temp;

		std::cout << "Input x: ";
		_stream >> temp.m_x;
		std::cout << std::endl << "Input y: ";
		_stream >> temp.m_y;
		std::cout << std::endl << "Input z: ";
		_stream >> temp.m_z;

		if (_stream)
		{
			IntegerListPushBack(_list, temp);
		}
		else
			break;
	}
}


void IntegerListPrint(const IntegerList &_list, std::ostream &_stream, char _sep)
{
	assert(!IntegerListIsEmpty(_list));

	IntegerList::Node *pCurrent = _list.m_pFirst;

	while (pCurrent)
	{
		_stream << "X: " << pCurrent->m_Data.m_x << " Y: " << pCurrent->m_Data.m_y << " Z: " << pCurrent->m_Data.m_z << _sep;
		std::cout << std::endl;
		pCurrent = pCurrent->m_pNext;
	}
}
