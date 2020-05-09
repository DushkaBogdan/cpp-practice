#include <iostream>
#include "vld.h"


struct Point
{
	int m_x, m_y;
	Point()
		:m_x(0), m_y(0)
	{}
	Point(int _x, int _y)
		:m_x(_x), m_y(_y)
	{}
};

double findDistance(const Point _p)
{
	return sqrt((pow(_p.m_x, 2) + pow(_p.m_y, 2)));
}

void selectionSort(Point *_arr, int _size)
{
	for (int i = 0; i < _size - 1; i++)
	{
		int lowIndex = i;
		for (int j = i; j < _size; j++)
		{
			if (  findDistance(_arr[j])
				< findDistance(_arr[lowIndex]))
			{
				lowIndex = j;
			}
		}
		std::swap(_arr[i], _arr[lowIndex]);
	}
}

void quickSorting(
	Point *_arr,
	int _size,
	void (*_sortingFunction)(Point *_arr1, int _size1))
{
	if (_sortingFunction != nullptr && _size < 4)
		_sortingFunction(_arr, _size);
	else if (_size != 1)
	{
		int pivotIndex = rand() % _size;
		Point pivot = _arr[pivotIndex];

		int leftIndex = -1, rightIndex = _size;

		while (true)
		{
			while (findDistance(_arr[++leftIndex]) < findDistance(pivot));
			while (findDistance(_arr[--rightIndex]) > findDistance(pivot))
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

		quickSorting(_arr, leftIndex, _sortingFunction);
		quickSorting(_arr + leftIndex,(_size - leftIndex), _sortingFunction);
	}
}

int main()
{
	const int size = 15;
	Point arr[size];
	for (int i = 0; i < size; i++)
	{
		Point temp((rand() % 9), (rand() % 9));
		arr[i] = temp;
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << "a.m_x" << i << ": " << arr[i].m_x 
			<< " ; a.m_y" << i << ": " <<  arr[i].m_y
			<< " findDistance: " << findDistance(arr[i])
			<< std::endl;
	}

	//selectionSort(arr, size);
	quickSorting(arr, size, nullptr);

	std::cout << std::endl << "After Sorting: " << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << "a.m_x" << i << ": " << arr[i].m_x
			<< " ; a.m_y" << i << ": " << arr[i].m_y
			<< " findDistance: " << findDistance(arr[i])
			<< std::endl;
	}
	
}