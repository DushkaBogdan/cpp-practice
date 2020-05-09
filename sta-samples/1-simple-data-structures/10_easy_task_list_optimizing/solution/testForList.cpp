#include "integer_list.hpp"
//#include "integer_list.cpp"
#include <cassert>
#include "vld.h"

int IntegerListAccumulate(const IntegerList & _list);

bool IntegerListIsSorted(const IntegerList & _list);

void IntegerListSplice( IntegerList & _sourceList,
						IntegerList::Node * _pSplitNode,
						IntegerList & _targetList1,
						IntegerList & _targetList2);

int main()
{
	IntegerList l;
	IntegerListInit(l);

	IntegerListReadTillZero(l, std::cin);
	
	IntegerList l1;
	IntegerListInit(l1);

	IntegerList l2;
	IntegerListInit(l2);

	std::cout << "List befor Spice: " << std::endl;
	IntegerListPrint(l, std::cout);

	std::cout << std::endl;
	IntegerListSplice(l, l.m_pFirst, l1, l2);

	std::cout << "List After Spice: " << std::endl;
	IntegerListPrint(l, std::cout);

	std::cout << std::endl;
	
	std::cout <<"First Spiced List: "<< std::endl;
	IntegerListPrint(l1, std::cout);

	std::cout << std::endl;

	std::cout <<"Second Spiced List: " << std::endl;
	IntegerListPrint(l2, std::cout);

	IntegerListDestroy(l1);
	IntegerListDestroy(l2);

}

int IntegerListAccumulate(const IntegerList & _list)
{

	assert(!IntegerListIsEmpty(_list));
	int sum = 0;
	IntegerList::Node *pCurrent = _list.m_pFirst;

	while (pCurrent)
	{
		sum += pCurrent->m_value;
		pCurrent = pCurrent->m_pNext;
	}
	return sum;
}

bool IntegerListIsSorted(const IntegerList & _list)
{
	assert(!IntegerListIsEmpty(_list));

	IntegerList::Node *pPrev = _list.m_pFirst;
	IntegerList::Node *pCurrent = _list.m_pFirst->m_pNext;
	

	while (pCurrent)
	{
		if (pCurrent->m_value < pPrev->m_value)
		{
			return false;
			break;
		}
		else
		{
			pPrev = pCurrent;
			pCurrent = pCurrent->m_pNext;
		}
	}

}

void IntegerListSplice(IntegerList & _sourceList,
	IntegerList::Node * _pSplitNode,
	IntegerList & _targetList1,
	IntegerList & _targetList2)
{
	assert(!IntegerListIsEmpty(_sourceList));

	if (_pSplitNode == _sourceList.m_pFirst)
		_targetList1.m_pFirst = _targetList1.m_pLast = nullptr;
	else
	{
	IntegerList::Node *pCurrent = _sourceList.m_pFirst;
	while (pCurrent->m_pNext != _pSplitNode)
		pCurrent = pCurrent->m_pNext;

		_targetList1.m_pFirst = _sourceList.m_pFirst;
		_targetList1.m_pLast = pCurrent;
		pCurrent->m_pNext = nullptr;
	}

	_targetList2.m_pFirst = _pSplitNode;
	_targetList2.m_pLast = _sourceList.m_pLast;

	_sourceList.m_pFirst = _sourceList.m_pLast = nullptr;

}