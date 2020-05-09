#include "integer_list_for_vector.hpp"
#include <cassert>

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
		IntegerVectorDestroy(pCurrent->_vector);
		delete pCurrent;
		pCurrent = temp;
	}
	_list.m_pFirst = _list.m_pLast = nullptr;
}

bool IntegerListIsEmpty(const IntegerList &_list)
{
	return !_list.m_pFirst;
}

void IntegerListPushBack(IntegerList &_list, IntegerVector &_v)
{
	IntegerList::Node *pNew = new IntegerList::Node;
	pNew->_vector = _v;
	pNew->m_pNext = nullptr;

	if (!IntegerListIsEmpty(_list))
	{
		_list.m_pLast->m_pNext = pNew;
	}
	else
	{
		_list.m_pFirst = pNew;
	}

	_list.m_pLast = pNew;
}

void IntegerListPushFront(IntegerList &_list, IntegerVector &_v)
{
	IntegerList::Node *pNew = new IntegerList::Node;
	pNew->_vector = _v;

	if (IntegerListIsEmpty(_list))
	{
		pNew->m_pNext = nullptr;
		_list.m_pLast = pNew;
	}
	else
	{
		pNew->m_pNext = _list.m_pFirst;
	}

	_list.m_pFirst = pNew;
}

void IntegerListInsertAfter(IntegerList &_list, IntegerList::Node *_pPrev, IntegerVector &_v)
{
	assert(!IntegerListIsEmpty(_list));
	assert(_pPrev != nullptr);

	IntegerList::Node *pNew = new IntegerList::Node;
	pNew->_vector = _v;

	if (_pPrev == _list.m_pLast)
	{
		pNew->m_pNext = nullptr;
		_list.m_pLast->m_pNext = pNew;
		_list.m_pLast = pNew;
	}
	else
	{
		pNew->m_pNext = _pPrev->m_pNext;
		_pPrev->m_pNext = pNew;
	}
}

void IntegerListInsertBefore(IntegerList &_list, IntegerList::Node *_pNext, IntegerVector &_v)
{
	assert(!IntegerListIsEmpty(_list));
	assert(_pNext != nullptr);

	if (_pNext == _list.m_pFirst)
	{
		IntegerListPushFront(_list, _v);
	}
	else
	{
		IntegerList::Node *pNew = new IntegerList::Node;
		pNew->_vector = _v;

		IntegerList::Node *pPrev = _list.m_pFirst;

		while (pPrev->m_pNext != _pNext)
		{
			pPrev = pPrev->m_pNext;
		}

		pNew->m_pNext = _pNext;
		pPrev->m_pNext = pNew;
	}
}

void IntegerListPopBack(IntegerList &_list)
{
	assert(!IntegerListIsEmpty(_list));

	IntegerList::Node *pDyingNode = _list.m_pLast;

	if (_list.m_pFirst == _list.m_pLast)
	{
		_list.m_pFirst = _list.m_pLast = nullptr;
	}
	else
	{
		IntegerList::Node *pCurrent = _list.m_pFirst;
		while (pCurrent->m_pNext != _list.m_pLast)
		{
			pCurrent = pCurrent->m_pNext;
		}

		pCurrent->m_pNext = nullptr;
		_list.m_pLast = pCurrent;
	}
	IntegerVectorDestroy(pDyingNode->_vector);
	delete pDyingNode;
}

void IntegerListPopFront(IntegerList &_list)
{
	assert(!IntegerListIsEmpty(_list));

	IntegerList::Node *pDyingNode = _list.m_pFirst;

	if (_list.m_pFirst == _list.m_pLast)
	{
		_list.m_pFirst = _list.m_pLast = nullptr;
	}
	else
	{
		_list.m_pFirst = pDyingNode->m_pNext;
	}
	IntegerVectorDestroy(pDyingNode->_vector);
	delete pDyingNode;
}

void IntegerListDeleteAfter(IntegerList &_list, IntegerList::Node *_pPrev)
{
	assert(!IntegerListIsEmpty(_list));
	assert(_pPrev != _list.m_pLast);
	assert(_pPrev != nullptr);

	if (_pPrev->m_pNext == _list.m_pLast)
	{
		IntegerListPopBack(_list);
	}
	else
	{
		IntegerList::Node *pDyingNode = _pPrev->m_pNext;
		_pPrev->m_pNext = pDyingNode->m_pNext;
		IntegerVectorDestroy(pDyingNode->_vector);
		delete pDyingNode;
	}
}

void IntegerListDeleteBefore(IntegerList &_list, IntegerList::Node *_pNext)
{
	assert(!IntegerListIsEmpty(_list));
	assert(_pNext != _list.m_pFirst);
	assert(_pNext != nullptr);

	if (_list.m_pFirst->m_pNext == _pNext)
	{
		IntegerListPopFront(_list);
	}
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
		IntegerVectorDestroy(pCurrent->_vector);
		delete pCurrent;
	}
}

void IntegerListPrint(IntegerList &_list, std::ostream &_stream, char _sep)
{
	if (IntegerListIsEmpty(_list))
	{
		_stream << "List is Empty!";
	}
	else
	{
		IntegerList::Node *pCurrent = _list.m_pFirst;
		while (pCurrent)
		{
			IntegerVectorPrint(pCurrent->_vector, _stream);
			_stream << std::endl;
			pCurrent = pCurrent->m_pNext;
		}
	}


}