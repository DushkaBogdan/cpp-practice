#include <iostream>
#include "vld.h"
#include "integer_vector.hpp"

int findMinimum(const IntegerVector _vector)
{
	int min = _vector.m_pData[0];
	for (int i = 1; i < _vector.m_nUsed; i++)
	{
		if (_vector.m_pData[i] < min)
			min = _vector.m_pData[i];
	}
	return min;
}

void SelectionSorting(IntegerVector *_arr, int _size)
{
	for (int i = 0; i < _size-1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < _size; j++)
		{
			if ( ( findMinimum(_arr[j]) < findMinimum(_arr[lowIndex]) ) ||
				(findMinimum(_arr[j]) == findMinimum(_arr[lowIndex])
				&& (_arr[j].m_nUsed < _arr[lowIndex].m_nUsed)))
				lowIndex = j;
			
			
		}
		std::swap(_arr[lowIndex], _arr[i]);
	}
}

void BubbleSorting(IntegerVector *_arr, int _size)
{
	for (int i = 0; i < _size - 1; i++)
	{
		for (int j = _size-1; j > i; j--)
		{
			if ((findMinimum(_arr[j-1]) > findMinimum(_arr[j])) ||
				(findMinimum(_arr[j-1]) == findMinimum(_arr[j])
				&& (_arr[j-1].m_nUsed > _arr[j].m_nUsed)))
				std::swap(_arr[j], _arr[j-1]);
		}
	}
}

void InsertionSorting(IntegerVector *_arr, int _size)
{
	for (int i = 1; i < _size; i++)
	{
		int j = i;

		while (j && ((findMinimum(_arr[j - 1]) > findMinimum(_arr[j])) ||
			(findMinimum(_arr[j - 1]) == findMinimum(_arr[j])
			&& (_arr[j - 1].m_nUsed > _arr[j].m_nUsed))))
		{
			std::swap(_arr[j], _arr[j - 1]);
			--j;
		}
	}
}

int main()
{
	int size = 3;
	IntegerVector *arrVectors = new IntegerVector[size];

	for (int i = 0; i < size; i++)
	{
		IntegerVector vector;
		IntegerVectorInit(vector);
		std::cout << "Input Vector till zero: ";
		IntegerVectorReadTillZero(vector, std::cin);
		arrVectors[i] = vector;
	}

	//SelectionSorting(arrVectors, size);
	//BubbleSorting(arrVectors, size);
	InsertionSorting(arrVectors, size);

	for (int i = 0; i < size; i++)
	{
		IntegerVectorPrint(arrVectors[i], std::cout);
		std::cout << std::endl;
	}

	for (int i = 0; i < size; i++)
	{
		IntegerVectorDestroy(arrVectors[i]);
	}

	delete[] arrVectors;
}