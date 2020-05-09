#include <iostream>
#include "vld.h"
#include <ctime>

void selectionSorting(int *_arr, int _size)
{
	for (int i = 0; i < _size-1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < _size; j++)
		{
			if (_arr[j] < _arr[lowIndex])
				lowIndex = j;
		}
		std::swap(_arr[lowIndex], _arr[i]);
	}
}

void bubbleSorting(int *_arr, int _size)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = _size - 1; j > i; j--)
		{
			if (_arr[j - 1] > _arr[j])
				std::swap(_arr[j - 1], _arr[j]);
		}
	}
}

void insertionSorting(int *_arr, int _size)
{
	for (int i = 1; i < _size; i++)
	{
		int j = i;
		while (j && _arr[j] < _arr[j - 1])
		{
			std::swap(_arr[j - 1], _arr[j]);
			--j;
		}
	}
}

void mergeSorting(const int *_first, int _firstSize,
				  const int *_second, int _secondSize,
				  int *_target)
{
	int FirstIndex = 0, SecondIndex = 0, TargetIndex = 0;

	while (FirstIndex < _firstSize && SecondIndex <  _secondSize)
	{
		if (_first[FirstIndex] <= _second[SecondIndex])
		{
			_target[TargetIndex++] = _first[FirstIndex];
			++FirstIndex;
		}
		else
		{
			_target[TargetIndex++] = _second[SecondIndex];
			++SecondIndex;
		}
	}

	if (_firstSize > FirstIndex)
	{
		memcpy(_target + TargetIndex, _first + FirstIndex, sizeof(int)*(_firstSize - FirstIndex));
	}
	else if (_secondSize > SecondIndex)
	{
		memcpy(_target + TargetIndex, _second + SecondIndex, sizeof(int)*(_secondSize - SecondIndex));
	}
}

void mergingSorting(int *_arr, int _size, void (*_easySorting)(int *_ar1, int _size1))
{
	if (_easySorting != nullptr && _size < 20)
		_easySorting(_arr, _size);
	else
	{
		if (_size != 1)
		{
			int firstSize = _size / 2;
			int otherSize = _size - firstSize;

			int *first = new int[firstSize];
			memcpy(first, _arr, sizeof(int)*firstSize);

			int *second = new int[otherSize];
			memcpy(second, _arr + firstSize, sizeof(int)*otherSize);

			mergingSorting(first, firstSize, _easySorting);
			mergingSorting(second, otherSize, _easySorting);

			mergeSorting(first, firstSize, second, otherSize, _arr);

			delete[] first;
			delete[] second;
		}
		
	}
	
}

int main()
{
	const int size = 200000;

	int arr[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 70;
	}

	time_t time1 = clock();

	mergingSorting(arr, size, nullptr) ;

	time_t time2 = clock();

	
	std::cout << time2 - time1 << std::endl;
}