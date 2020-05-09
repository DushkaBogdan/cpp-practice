#include "string_set.hpp"
#include "string_list.hpp"
#include <cassert>
#include <iostream>

struct StringSet
{
	StringList m_list;
};

StringSet* StringSetCreate()
{
	StringSet *pSet = new StringSet;
	StringListInit(pSet->m_list);
	return pSet;
}

void StringSetDestroy(StringSet *_pSet)
{
	StringListDestroy(_pSet->m_list);
	delete _pSet;
}
void StringSetClear(StringSet &_set)
{
	StringListDestroy(_set.m_list);
}
bool StringSetIsEmpty(const StringSet &_set)
{
	return StringListIsEmpty(_set.m_list);
}
bool StringSetHasKey(const StringSet &_set, const char *_key)
{
	assert(!StringSetIsEmpty(_set));

	StringList::Node *pCurrent = _set.m_list.m_pFirst;

	while (pCurrent)
	{
		if (strcmp(pCurrent->m_string, _key) == 0)
			return true;
		pCurrent = pCurrent->m_pNext;
	}
	return false;
}
void StringSetInsertKey(StringSet &_set, const char *_key)
{
	StringListPushSorted(_set.m_list, _key);
}

void StringSetInsertKeyDuplicated(StringSet &_set, const char *_key)
{
	StringListPushSortedDuplicated(_set.m_list, _key);
}
void StringSetRemoveKey(StringSet &_set, const char *_key)
{
	StringList::Node *pPrev = _set.m_list.m_pFirst;

	if (strcmp(pPrev->m_string, _key) == 0)
	{
		StringListPopFront(_set.m_list);
		return;
	}
	if (strcmp(_set.m_list.m_pLast->m_string, _key) == 0)
	{
		StringListPopBack(_set.m_list);
		return;
	}

	StringList::Node *pCurrent = pPrev->m_pNext;

	while(pCurrent)
	{
		if (strcmp(pCurrent->m_string, _key) == 0)
		{
			pPrev->m_pNext = pCurrent->m_pNext;
			delete pCurrent->m_string;
			delete pCurrent;
			return;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->m_pNext;
	}
}

void StringSetPrint(const StringSet &_set, std::ostream &_stream, char _sep)
{
	StringListPrint(_set.m_list, _stream, _sep);
}

void StringSetUnite(
	const StringSet &_firstSet,
	const StringSet &_secondSet,
	StringSet &_targetSet)
{
	StringSetClear(_targetSet);

	StringList::Node *pCurrent = _firstSet.m_list.m_pFirst;
	while (pCurrent)
	{
		StringListPushSorted(_targetSet.m_list, pCurrent->m_string);
		pCurrent = pCurrent->m_pNext;
	}
	pCurrent = _secondSet.m_list.m_pFirst;
	while (pCurrent)
	{
		StringListPushSorted(_targetSet.m_list, pCurrent->m_string);
		pCurrent = pCurrent->m_pNext;
	}
}

void StringSetInterSec(
	const StringSet &_firstSet,
	const StringSet &_secondSet,
	StringSet &_targetSet)
{
	StringSetClear(_targetSet);

	StringList::Node *pCurrent = _firstSet.m_list.m_pFirst;
	while (pCurrent)
	{
		if (StringSetHasKey(_secondSet, pCurrent->m_string))
			StringSetInsertKey(_targetSet, pCurrent->m_string);
		pCurrent = pCurrent->m_pNext;
	}
}

void StringSetDiff(
	const StringSet &_firstSet,
	const StringSet &_secondSet,
	StringSet &_targetSet)
{
	StringSetClear(_targetSet);

	StringList::Node *pCurrent = _firstSet.m_list.m_pFirst;
	while (pCurrent)
	{
		if (!StringSetHasKey(_secondSet, pCurrent->m_string))
			StringSetInsertKey(_targetSet, pCurrent->m_string);
		pCurrent = pCurrent->m_pNext;
	}
}