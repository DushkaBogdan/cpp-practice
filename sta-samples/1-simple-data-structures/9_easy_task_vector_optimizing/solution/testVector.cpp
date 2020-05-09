#include "integer_vector.hpp"
#include "integer_vector.cpp"
//#include <iostream>

#include "vld.h"

void IntegerVectorReserve(IntegerVector & _v, int _nCells);

void IntegerVectorShrinkToFit(IntegerVector & _v);

int IntegerVectorRemainingCapacity(const IntegerVector & _v);

int main()
{
	IntegerVector v;
	IntegerVectorInit(v);

	IntegerVectorPushBack(v, 1);
	IntegerVectorReserve(v, 2);
	IntegerVectorPushBack(v, 2);
	v.m_pData[1] = 11;
	v.m_pData[2] = 22;
	


	IntegerVectorPrint(v, std::cout);

	/*std::cout << "Remain Cells: " <<IntegerVectorRemainingCapacity(v) <<std::endl;

	std::cout << "Old size before Shrink: " << v.m_nAllocated <<std::endl;
	IntegerVectorShrinkToFit(v);
	std::cout << "New size after Shrink: " << v.m_nAllocated << std::endl;*/

	IntegerVectorDestroy(v);
}

void IntegerVectorReserve(IntegerVector & _v, int _nCells)
{
	if (_v.m_nUsed + _nCells >= _v.m_nAllocated)
		IntegerVectorGrow(_v);
	
	std::cout << "Cells :";
	for (int i = _v.m_nUsed; i < _v.m_nUsed + _nCells; i++)
	{
		std::cout << i << ' ';
	}

	std::cout << " were reserved!" << std::endl;
	_v.m_nUsed += _nCells;
}

void IntegerVectorShrinkToFit(IntegerVector & _v)
{
	if (_v.m_nAllocated > _v.m_nUsed)
	{
		int newSize = _v.m_nUsed;
		int *pNewArr = new int[newSize];

		memcpy(pNewArr, _v.m_pData, sizeof(int)*_v.m_nUsed);

		delete[] _v.m_pData;
		_v.m_pData = pNewArr;
		_v.m_nAllocated = newSize;
	}
}

int IntegerVectorRemainingCapacity(const IntegerVector & _v)
{
	return (_v.m_nAllocated - _v.m_nUsed);
}