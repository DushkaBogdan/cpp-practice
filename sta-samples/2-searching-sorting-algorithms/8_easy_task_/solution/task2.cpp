#include "integer_vector.hpp"
#include <iostream>
#include "vld.h"

void quickSorting(int *_arr, int _size)
{
	if (_size == 1)
		return;
	
	int leftIndex = -1;
	int rightIndex = _size;

	int ranIndex = rand() % _size;
	int rand = _arr[ranIndex];

	while (true)
	{
		while (_arr[++leftIndex] < rand);
		while (_arr[--rightIndex] > rand)
		{
			if (leftIndex == rightIndex)
				break;
		}
		if (leftIndex >= rightIndex)
			break;
		std::swap(_arr[leftIndex], _arr[rightIndex]);
	}

	if (leftIndex == 0)
		++leftIndex;

	quickSorting(_arr, leftIndex);
	quickSorting(_arr + leftIndex, _size - leftIndex);
}

int main()
{
	IntegerVector v;
	IntegerVectorInit(v);

	while (true)
	{
		int temp;
		std::cin >> temp;

		if (temp <= 0)
			break;
		IntegerVectorPushBack(v, temp);
	}

	quickSorting(v.m_pData, v.m_nUsed);

	int diff = v.m_pData[1] - v.m_pData[0];
	bool isNotProgressive = false;

	for (int i = 2; i < v.m_nUsed; i++)
	{
		if ((v.m_pData[i] - v.m_pData[i - 1]) != diff)
		{
			isNotProgressive = true;
			break;
		}
	}
	if (isNotProgressive)
		std::cout << "Cant be Progressive!" << std::endl;
	else
		std::cout << "Can be Progressive!" << std::endl;

	IntegerVectorDestroy(v);
}