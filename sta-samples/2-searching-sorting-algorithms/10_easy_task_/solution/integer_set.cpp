#include "integer_set.hpp"
#include "integer_list.cpp"
#include <cassert>

struct IntegerSet
{
	IntegerList m_list;
};

IntegerSet* IntegerSetCreate()
{
	IntegerSet *pSet = new IntegerSet;
	IntegerListInit(pSet->m_list);
	return pSet;
}

void IntegerSetDestroy(IntegerSet *_pSet)
{
	IntegerListDestroy(_pSet->m_list);
	delete _pSet;
}
void IntegerSetClear(IntegerSet &_set)
{
	IntegerListDestroy(_set.m_list);
}
bool IntegerSetIsEmpty(const IntegerSet &_set)
{
	return IntegerListIsEmpty(_set.m_list);
}
bool IntegerSetHasKey(const IntegerSet &_set, int _key)
{
	assert(!IntegerSetIsEmpty(_set));

	IntegerList::Node *pCurrent = _set.m_list.m_pFirst;

	while (pCurrent)
	{
		if (pCurrent->m_value == _key)
			return true;
		pCurrent = pCurrent->m_pNext;
	}
	return false;
}
void IntegerSetInsertKey(IntegerSet &_set, int _key)
{
	IntegerListPushBack(_set.m_list, _key);
}
void IntegerSetRemoveKey(IntegerSet &_set, int _key)
{
	if (_set.m_list.m_pFirst->m_value == _key)
		IntegerListPopFront(_set.m_list);
	else if (_set.m_list.m_pLast->m_value == _key)
		IntegerListPopBack(_set.m_list);
	else
	{
		IntegerList::Node *pPrev = _set.m_list.m_pFirst;
		IntegerList::Node *pCurrent = pPrev->m_pNext;

		while (pCurrent)
		{
			if (pCurrent->m_value == _key)
			{
				pPrev->m_pNext = pCurrent->m_pNext;
				delete pCurrent;
				break;
			}
			pPrev = pCurrent;
			pCurrent = pCurrent->m_pNext;
		}
	}
}

void IntegerSetPrint(const IntegerSet &_set, std::ostream &_stream, char _sep)
{
	IntegerListPrint(_set.m_list, _stream, _sep);
}

void IntegerSetUnite(
	const IntegerSet &_firstSet,
	const IntegerSet &_secondSet,
	IntegerSet &_targetSet)
{
	IntegerSetClear(_targetSet);

	IntegerList::Node *pCurrent = _firstSet.m_list.m_pFirst;
	while (pCurrent)
	{
		IntegerListPushBack(_targetSet.m_list, pCurrent->m_value);
		pCurrent = pCurrent->m_pNext;
	}
	pCurrent = _secondSet.m_list.m_pFirst;
	while (pCurrent)
	{
		if (!IntegerSetHasKey(_firstSet, pCurrent->m_value))
			IntegerListPushBack(_targetSet.m_list, pCurrent->m_value);
		pCurrent = pCurrent->m_pNext;
	}
}

void IntegerSetInterSec(
	const IntegerSet &_firstSet,
	const IntegerSet &_secondSet,
	IntegerSet &_targetSet)
{
	IntegerSetClear(_targetSet);

	IntegerList::Node *pCurrent = _firstSet.m_list.m_pFirst;
	while (pCurrent)
	{
		if (IntegerSetHasKey(_secondSet, pCurrent->m_value))
			IntegerSetInsertKey(_targetSet, pCurrent->m_value);
		pCurrent = pCurrent->m_pNext;
	}
}

void IntegerSetDiff(
	const IntegerSet &_firstSet,
	const IntegerSet &_secondSet,
	IntegerSet &_targetSet)
{
	IntegerSetClear(_targetSet);

	IntegerList::Node *pCurrent = _firstSet.m_list.m_pFirst;
	while (pCurrent)
	{
		if (!IntegerSetHasKey(_secondSet, pCurrent->m_value))
			IntegerSetInsertKey(_targetSet, pCurrent->m_value);
		pCurrent = pCurrent->m_pNext;
	}
}

bool IntegerSetIsSubset(const IntegerSet &_set1, const IntegerSet &_targerSet)
{
	IntegerList::Node *pCurrent = _set1.m_list.m_pFirst;
	while (pCurrent)
	{
		if (!IntegerSetHasKey(_targerSet, pCurrent->m_value))
			return false;
		pCurrent = pCurrent->m_pNext;
	}
	return true;
}


bool IntegerSetIsEqual(const IntegerSet &_set1, const IntegerSet &_set2)
{
	if (IntegerListSize(_set1.m_list) == IntegerListSize(_set2.m_list) &&
		IntegerSetIsSubset(_set1, _set2))
		return true;
	else
		return false;
}

int IntegerSetMinKey(const IntegerSet &_set)
{
	IntegerList::Node *pCurrent = _set.m_list.m_pFirst;
	int min = pCurrent->m_value;
	while (pCurrent)
	{
		if (pCurrent->m_value < min)
			min = pCurrent->m_value;
		pCurrent = pCurrent->m_pNext;
	}
	return min;
}

int IntegerSetMaxKey(const IntegerSet &_set)
{

	IntegerList::Node *pCurrent = _set.m_list.m_pFirst;
	int max = pCurrent->m_value;
	while (pCurrent)
	{
		if (pCurrent->m_value > max)
			max = pCurrent->m_value;
		pCurrent = pCurrent->m_pNext;
	}
	return max;
}