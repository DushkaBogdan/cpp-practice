#include "list.hpp"
#include <cassert>

void ListInit(List & _l)
{
	_l.m_pFirst = _l.m_pLast = nullptr;
}
void ListDestr(List & _l)
{
	List::Node *pCurrent = _l.m_pFirst;
	
	while (pCurrent)
	{
		List::Node *temp = pCurrent->m_pNext;
		delete pCurrent;
		pCurrent = temp;
	}
	_l.m_pFirst = _l.m_pLast = nullptr;
}
bool ListIsEmpty(const List & _l)
{
	return _l.m_pFirst == nullptr;
}
void ListPushBack(List & _l, int _data)
{
	List::Node * pNewNode = new List::Node;
	pNewNode->m_data = _data;
	pNewNode->m_pNext = nullptr;

	if (ListIsEmpty(_l))
	{
		_l.m_pFirst = pNewNode;
		pNewNode->m_pPrev = nullptr;
	}
	else
	{
		pNewNode->m_pPrev = _l.m_pLast;
		_l.m_pLast->m_pNext = pNewNode;
	}
	_l.m_pLast = pNewNode;
	
}
void ListPushFront(List & _l, int _data)
{
	List::Node * pNewNode = new List::Node;
	pNewNode->m_data = _data;

	if (ListIsEmpty(_l))
	{
		_l.m_pLast = pNewNode;
		pNewNode->m_pNext = nullptr;
	}
	else
		pNewNode->m_pNext = _l.m_pFirst;

	_l.m_pFirst = pNewNode;
}
void InsertAfter(List & _l, List::Node *_pPrev, int _data)
{
	assert(!ListIsEmpty(_l));

	if (_pPrev == _l.m_pLast)
		ListPushBack(_l, _data);
	else
	{
		List::Node *pNewNode = new List::Node;
		pNewNode->m_data = _data;
		pNewNode->m_pNext = _pPrev->m_pNext;
		_pPrev->m_pNext = pNewNode;
	}
	
}
void InsertBefore(List & _l, List::Node *_pNext, int _data)
{
	assert(!ListIsEmpty(_l));

	if (_pNext == _l.m_pFirst)
		ListPushFront(_l, _data);
	else
	{
		List::Node *pNew = new List::Node;
		pNew->m_data = _data;

		List::Node *pCurrent = _l.m_pFirst;

		while (pCurrent && pCurrent->m_pNext != _pNext)
			pCurrent = pCurrent->m_pNext;

		pNew->m_pNext = _pNext;
		pCurrent->m_pNext = pNew;
	}
}
void PopBack(List & _l)
{
	assert(!ListIsEmpty(_l));

	List::Node *pLast = _l.m_pLast;

	if (_l.m_pFirst == _l.m_pLast)
		_l.m_pFirst = _l.m_pLast = nullptr;
	else
	{
		List::Node *pCurrent = _l.m_pFirst;
		while (pCurrent->m_pNext != _l.m_pLast)
			pCurrent = pCurrent->m_pNext;

		_l.m_pLast = pCurrent;
		pCurrent->m_pNext = nullptr;
		
	}

	delete pLast;
}
void PopFront(List & _l)
{
	assert(!ListIsEmpty(_l));

	List::Node *pDyingNode = _l.m_pFirst;

	if (_l.m_pFirst == _l.m_pLast)
		_l.m_pFirst = _l.m_pLast = nullptr;
	else
	{
		_l.m_pFirst = _l.m_pFirst->m_pNext;
	}
	delete pDyingNode;
}
void DeleteAfter(List & _l, List::Node *_pPrev)
{
	assert(!ListIsEmpty(_l));
	assert(_pPrev != _l.m_pLast);

	if (_pPrev->m_pNext == _l.m_pLast)
		PopBack(_l);
	else
	{
		List::Node *pDyingNode = _pPrev->m_pNext;
		_pPrev->m_pNext = pDyingNode->m_pNext;

		delete pDyingNode;
	}
}
void DeleteBefore(List & _l, List::Node *_pNext)
{
	assert(!ListIsEmpty(_l));
	assert(_pNext != _l.m_pFirst);

	if (_l.m_pFirst->m_pNext == _pNext)
		PopFront(_l);

	else
	{
		List::Node *pPrev = _l.m_pFirst;
		List::Node *pCurremt = pPrev->m_pNext;

		while (pCurremt->m_pNext != _pNext)
		{
			pPrev = pCurremt;
			pCurremt = pCurremt->m_pNext;
		}

		pPrev->m_pNext = _pNext;
		delete pCurremt;
	}
}
void ListRead(List & _l, std::istream &_stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream)
			ListPushBack(_l, temp);
		else
			break;
	}
}
void ListReadTillZero(List & _l, std::istream &_stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream && temp != 0)
			ListPushBack(_l, temp);
		else
			break;
	}
}
void ListPrint(const List & _l, std::ostream &_stream, char _sep)
{
	const List::Node *pCurrent = _l.m_pFirst;
	while (pCurrent)
	{
		_stream << pCurrent->m_data << _sep;
		pCurrent = pCurrent->m_pNext;
	}
}