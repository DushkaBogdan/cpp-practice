#include "string_list.hpp"
#include <iostream>
#include <cassert>

char *StrCopy(const char *_string)
{
	int length = strlen(_string) + 1;
	char *charBuff = new char[length];
	strcpy_s(charBuff, length, _string);
	return charBuff;
}

void StringListInit(StringList &_list)
{
	_list.m_pFirst = _list.m_pLast = nullptr;
}
void StringListDestroy(StringList &_list)
{
	if (!StringListIsEmpty(_list))
	{
		StringList::Node *pNode = _list.m_pFirst;

		while (pNode)
		{
			StringList::Node *pTemp = pNode->m_pNext;
			delete pNode->m_string;
			delete pNode;
			pNode = pTemp;
		}
	}
	_list.m_pFirst = _list.m_pLast = nullptr;
}
void StringListClear(StringList &_list)
{
	StringListDestroy(_list);
}
bool StringListIsEmpty(const StringList &_list)
{
	return _list.m_pFirst == nullptr;
}
void StringListPushBack(StringList &_list, const char *_string)
{
	StringList::Node *pNode = new StringList::Node;
	pNode->m_string = StrCopy(_string);
	pNode->m_pNext = nullptr;

	if (!_list.m_pFirst)
		_list.m_pFirst = pNode;
	else
		_list.m_pLast->m_pNext = pNode;
	_list.m_pLast = pNode;
}
void StringListPushFront(StringList &_list, const char *_string)
{
	StringList::Node *pNode = new StringList::Node;
	pNode->m_string = StrCopy(_string);
	pNode->m_pNext = _list.m_pFirst;

	_list.m_pFirst = pNode;

	if (!_list.m_pLast)
		_list.m_pLast = pNode;
}
void StringListInsertAfter(StringList &_list, StringList::Node *_pPrev, const char *_string)
{
	StringList::Node *pNode = new StringList::Node;
	pNode->m_string = StrCopy(_string);

	if (_pPrev == _list.m_pLast)
	{
		pNode->m_pNext = nullptr;
		_list.m_pLast->m_pNext = pNode;
		_list.m_pLast = pNode;
	}
	else
	{
		pNode->m_pNext = _pPrev->m_pNext;
		_pPrev->m_pNext = pNode;
	}
}
void StringListInsertBefore(StringList &_list, StringList::Node *_pNext, const char *_string)
{
	StringList::Node *pNewNode = new StringList::Node;
	pNewNode->m_string = StrCopy(_string);

	if (_pNext == _list.m_pFirst)
	{
		pNewNode->m_pNext = _list.m_pFirst;
		_list.m_pFirst = pNewNode;
	}
	else
	{
		StringList::Node *pCurrent = _list.m_pFirst;
		while (pCurrent && pCurrent->m_pNext != _pNext)
		{
			pCurrent = pCurrent->m_pNext;
		}

		pNewNode->m_pNext = _pNext;
		pCurrent->m_pNext = pNewNode;
	}
}

void StringListPushSorted(StringList &_list, const char *_string)
{
	

	if (_list.m_pFirst == nullptr)
	{
		StringList::Node *pNewNode = new StringList::Node;
		pNewNode->m_string = StrCopy(_string);
		pNewNode->m_pNext = nullptr;
		_list.m_pFirst = _list.m_pLast = pNewNode;
	}
	else
	{
		StringList::Node *pPrev = _list.m_pFirst;

		if (strcmp(pPrev->m_string, _string) > 0)
			StringListPushFront(_list, _string);
		else if (strcmp(_list.m_pLast->m_string, _string) < 0)
		{
			StringListPushBack(_list, _string);
		}
		else if (strcmp(_list.m_pFirst->m_string, _string) == 0 
			||   strcmp(_list.m_pLast->m_string, _string) == 0)
		{
			return;
		}
		else
		{
			StringList::Node *pCurrent = pPrev->m_pNext;

			while ((strcmp(pCurrent->m_string, _string) <= 0))
			{
				if ((strcmp(pCurrent->m_string, _string) == 0))
				{
					return;
				}
				pPrev = pCurrent;
				pCurrent = pCurrent->m_pNext;
			}
			
			StringListInsertAfter(_list, pPrev, _string);

		}

		
	}
}

void StringListPopBack(StringList &_list)
{
	assert(_list.m_pFirst != nullptr);

	if (_list.m_pFirst == _list.m_pLast)
	{
		StringListDestroy(_list);
	}
	else
	{
		StringList::Node *pCurrent = _list.m_pFirst;
		while (pCurrent->m_pNext != _list.m_pLast)
			pCurrent = pCurrent->m_pNext;

		delete _list.m_pLast->m_string;
		delete _list.m_pLast;

		pCurrent->m_pNext = nullptr;
		_list.m_pLast = pCurrent;

	}
}
void StringListPopFront(StringList &_list)
{
	assert(_list.m_pFirst!= nullptr);

	if (_list.m_pFirst == _list.m_pLast)
	{
		StringListDestroy(_list);
	}
	else
	{
		StringList::Node *pTemp = _list.m_pFirst->m_pNext;
		delete _list.m_pFirst->m_string;
		delete _list.m_pFirst;
		_list.m_pFirst = pTemp;
	}
}
void StringListPopAfter(StringList &_list, StringList::Node *_pPrev)
{
	assert(_pPrev != _list.m_pLast);
	if (_pPrev->m_pNext == _list.m_pLast)
		StringListPopBack(_list);
	else
	{
		StringList::Node *pDyingNode = _pPrev->m_pNext;
		_pPrev->m_pNext = pDyingNode->m_pNext;

		delete pDyingNode->m_string;
		delete pDyingNode;
	}
}
void StringListPopBefore(StringList &_list, StringList::Node *_pNext)
{
	assert(_pNext != _list.m_pFirst);
	if (_list.m_pFirst->m_pNext == _pNext)
		StringListPopFront(_list);
	else
	{
		StringList::Node *pPrev = _list.m_pFirst;
		StringList::Node *pCurrent = pPrev->m_pNext;

		while (pCurrent->m_pNext != _pNext && pCurrent)
		{
			pPrev = pCurrent;
			pCurrent = pCurrent->m_pNext;
		}

		pPrev->m_pNext = _pNext;

		delete pCurrent->m_string;
		delete pCurrent;
	}
}

void StringListPrint(const StringList &_list, std::ostream &_stream, char _sep)
{
	if (StringListIsEmpty(_list))
		_stream << "List is Empty!\n";
	else
	{
		StringList::Node* pCurrent = _list.m_pFirst;

		while (pCurrent)
		{
			_stream << pCurrent->m_string << _sep;
			pCurrent = pCurrent->m_pNext;
		}
		_stream << "\n";
	}
}

void StringListPushSortedDuplicated(StringList &_list, const char *_string)
{
	if (_list.m_pFirst == nullptr)
	{
		StringList::Node *pNewNode = new StringList::Node;
		pNewNode->m_string = StrCopy(_string);
		pNewNode->m_pNext = nullptr;
		_list.m_pFirst = _list.m_pLast = pNewNode;
	}
	else
	{
		StringList::Node *pPrev = _list.m_pFirst;

		if (strcmp(pPrev->m_string, _string) >= 0)
			StringListPushFront(_list, _string);
		else if (strcmp(_list.m_pLast->m_string, _string) <= 0)
		{
			StringListPushBack(_list, _string);
		}
		else
		{
			StringList::Node *pCurrent = pPrev->m_pNext;

			while ((strcmp(pCurrent->m_string, _string) <= 0))
			{
				if ((strcmp(pCurrent->m_string, _string) == 0))
				{
					StringListInsertAfter(_list, pCurrent, _string);
					break;
				}
				pPrev = pCurrent;
				pCurrent = pCurrent->m_pNext;
			}

			StringListInsertAfter(_list, pPrev, _string);

		}


	}
}