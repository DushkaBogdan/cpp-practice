#include "integer_list_double.hpp"
#include <cassert>

void IntegerListInit(IntegerList &_list)
{
	_list.m_pFirst = _list.m_pLast = nullptr;
}

void IntegerListDestroy(IntegerList *_list)
{
	IntegerList::Node *pCurrent = _list->m_pFirst;


	while (pCurrent)
	{
		IntegerList::Node *temp = pCurrent->m_pNext;
		delete pCurrent;
		pCurrent = temp;
	}

	_list->m_pFirst = _list->m_pLast = nullptr;
}

bool IntegerListIsEmpty(const IntegerList & _list)
{
	return _list.m_pFirst == nullptr;
}

void IntegerListPushBack(IntegerList &_list, int _data)
{
	IntegerList::Node *pNewNode = new IntegerList::Node;
	pNewNode->m_Data = _data;
	pNewNode->m_pNext = nullptr;

	if (IntegerListIsEmpty(_list))
	{
		_list.m_pFirst = pNewNode;
		pNewNode->m_pPrev = nullptr;
	}

	else
	{
		pNewNode->m_pPrev = _list.m_pLast;
		_list.m_pLast->m_pNext = pNewNode;
	}

	_list.m_pLast = pNewNode;
}

void IntegerListPushFront(IntegerList &_list, int _data)
{
	IntegerList::Node *pNewNode = new IntegerList::Node;
	pNewNode->m_Data = _data;

	if (IntegerListIsEmpty(_list))
	{
		_list.m_pLast = pNewNode;
		pNewNode->m_pNext = nullptr;
	}
	else
	{
		_list.m_pFirst->m_pPrev = pNewNode;
		pNewNode->m_pNext = _list.m_pFirst;
	}
	
	_list.m_pFirst = pNewNode;
	pNewNode->m_pPrev = nullptr;
}

void IntegerListInsertAfter(IntegerList &_list, IntegerList::Node *_pPrev, int _data)
{
	assert(!IntegerListIsEmpty(_list));
	assert(_pPrev != nullptr);

	if (_list.m_pLast == _pPrev)
		IntegerListPushBack(_list, _data);
	else
	{
		IntegerList::Node *pNewNode = new IntegerList::Node;
		pNewNode->m_Data = _data;
		

		pNewNode->m_pNext = _pPrev->m_pNext;
		_pPrev->m_pNext->m_pPrev = pNewNode;

		pNewNode->m_pPrev = _pPrev;
		_pPrev->m_pNext = pNewNode;
	}
}

void IntegerListInsertBefore(IntegerList &_list, IntegerList::Node *_pNext, int _data)
{
	assert(!IntegerListIsEmpty(_list));
	assert(_pNext != nullptr);

	if (_list.m_pFirst == _pNext)
		IntegerListPushFront(_list, _data);
	else
	{
		IntegerList::Node *pNew = new IntegerList::Node;
		pNew->m_Data = _data;

		pNew->m_pNext = _pNext;
		_pNext->m_pPrev->m_pNext = pNew;

		pNew->m_pPrev = _pNext->m_pPrev;
		_pNext->m_pPrev = pNew;
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
	else
	{ 
		IntegerList::Node *pDyingNode = _list.m_pLast;
		_list.m_pLast =	pDyingNode->m_pPrev;
		_list.m_pLast->m_pNext = nullptr;
		pDyingNode->m_pPrev = nullptr;
		delete pDyingNode;
	}

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
		_list.m_pFirst->m_pPrev = nullptr;

		delete pDyingNode;
	}

}

void IntegerListDeleteAfter(IntegerList &_list, IntegerList::Node *_pPrev)
{
	assert(!IntegerListIsEmpty(_list));
	assert(_pPrev != _list.m_pLast && _pPrev != nullptr);

	if (_list.m_pLast == _pPrev->m_pNext)
		IntegerListPopBack(_list);
	else
	{
		IntegerList::Node *pDyingNode = _pPrev->m_pNext;
		_pPrev->m_pNext = pDyingNode->m_pNext;
		pDyingNode->m_pNext->m_pPrev = _pPrev;

		delete pDyingNode;
	}
}

void IntegerListDeleteBefore(IntegerList &_list, IntegerList::Node *_pNext)
{
	assert(!IntegerListIsEmpty(_list));
	assert(_pNext != _list.m_pFirst && _pNext != nullptr);

	if (_list.m_pFirst->m_pNext == _pNext)
		IntegerListPopFront(_list);
	else
	{

		IntegerList::Node *pCurrent = _pNext->m_pPrev;
		pCurrent->m_pPrev->m_pNext = _pNext;
		_pNext->m_pPrev = pCurrent->m_pPrev;

		delete pCurrent;
	}

}

void IntegerListRead(IntegerList &_list, std::istream &_stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream)
		{
			IntegerListPushBack(_list, temp);
		}
		else
			break;
	}
}

void IntegerListReadTillZero(IntegerList &_list, std::istream &_stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream && temp != 0)
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
		_stream << pCurrent->m_Data << _sep;
		pCurrent = pCurrent->m_pNext;
	}
}
