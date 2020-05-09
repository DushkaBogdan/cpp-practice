#include <cassert>
#include "list_double.hpp"

char *StringCopy(const char *_str)
{
	int length = strlen(_str) + 1;
	char *charBuff = new char[length];
	strcpy_s(charBuff, length, _str);
	return charBuff;
}

void IntegerListInit(IntegerList & _list)
{
	_list.m_pFirst = _list.m_pLast = nullptr;
}

void IntegerListClear(IntegerList & _list)
{
	IntegerList::Node * pCurrent = _list.m_pFirst;
	while (pCurrent)
	{
		IntegerList::Node * pTemp = pCurrent->m_pNext;
		delete pCurrent->m_date;
		delete pCurrent;
		pCurrent = pTemp;
	}

	_list.m_pFirst = _list.m_pLast = nullptr;
}


void IntegerListDestroy(IntegerList & _list)
{
	IntegerListClear(_list);
}





bool IntegerListIsEmpty(const IntegerList & _list)
{
	return _list.m_pFirst == nullptr;
}


int IntegerListSize(const IntegerList & _list)
{
	int nElements = 0;
	const IntegerList::Node * pNode = _list.m_pFirst;
	while (pNode)
	{
		++nElements;
		pNode = pNode->m_pNext;
	}

	return nElements;
}


void IntegerListPushBack(IntegerList & _list, double _data, const char *_date)
{
	IntegerList::Node * pNewNode = new IntegerList::Node;
	pNewNode->m_value = _data;
	pNewNode->m_date = StringCopy(_date);
	pNewNode->m_pNext = nullptr;

	if (!_list.m_pFirst)
	{
		assert(!_list.m_pLast);
		_list.m_pFirst = pNewNode;
	}
	else
		_list.m_pLast->m_pNext = pNewNode;

	_list.m_pLast = pNewNode;
}


void IntegerListPushFront(IntegerList & _list, double _data, const char *_date)
{
	IntegerList::Node * pNewNode = new IntegerList::Node;
	pNewNode->m_value = _data;
	pNewNode->m_date = StringCopy(_date);
	pNewNode->m_pNext = _list.m_pFirst;

	_list.m_pFirst = pNewNode;

	if (!_list.m_pLast)
		_list.m_pLast = pNewNode;
}


void IntegerListInsertAfter(IntegerList & _list, IntegerList::Node * _pPrevNode, double _data, const char *_date)
{
	assert(!IntegerListIsEmpty(_list));

	if (_pPrevNode == _list.m_pLast)
		IntegerListPushBack(_list, _data, _date);

	else
	{
		IntegerList::Node * pNewNode = new IntegerList::Node;
		pNewNode->m_value = _data;
		pNewNode->m_date = StringCopy(_date);

		pNewNode->m_pNext = _pPrevNode->m_pNext;

		_pPrevNode->m_pNext = pNewNode;
	}
}


void IntegerListPrint(const IntegerList & _list, std::ostream & _stream, char _sep)
{
	const IntegerList::Node * pCurrent = _list.m_pFirst;
	if (pCurrent == nullptr)
	{
		_stream << "Map Is Empty!";
		return;
	}
	while (pCurrent)
	{
		_stream << pCurrent->m_value << _sep << pCurrent->m_date <<  "\n";
		pCurrent = pCurrent->m_pNext;
	}
}