#include <iostream>
#include "vld.h"

void selectionSorting(char **_arr, int _size)
{
	for (int i = 0; i < _size-1; i++)
	{
		int LowIndex = i;
		for (int j = i + 1; j < _size; j++)
		{
			if (strlen(_arr[LowIndex]) > strlen(_arr[j]))
				LowIndex = j;
		}

		std::swap(_arr[i], _arr[LowIndex]);
	}
}

char* strCopy(const char* _arr)
{
	int length = strlen(_arr);
	char *charBuff = new char[length + 1];
	strcpy(charBuff, _arr);

	return charBuff;
}

void mergeSorted(
	char** _first, int _firstSize,
	char**_second, int _otherSize,
	char **_arr)
{
	int firstIndex = 0, secondIndex = 0, destIndex = 0;

	while (firstIndex < _firstSize && secondIndex < _otherSize)
	{
		if (strlen( _first[firstIndex]) <= strlen( _second[secondIndex]))
		{
			_arr[destIndex] = _first[firstIndex];
			++firstIndex;
		}
		else
		{
			_arr[destIndex] = _second[secondIndex];
			++secondIndex;
		}

		++destIndex;
	}

	if (firstIndex < _firstSize)
	{
		memcpy(_arr + destIndex,
			_first + firstIndex,
			sizeof(char*)*(_firstSize - firstIndex));
	}
	else if (secondIndex < _otherSize)
	{
		memcpy(_arr + destIndex,
			_second + secondIndex,
			sizeof(char*)*(_otherSize - secondIndex));
	}

}

void mergeSorting(char **_arr, int _size)
{
	if (_size < 3)
		selectionSorting(_arr, _size);
	else
	{
		int firstSize = _size / 2;
		int otherSize = _size - firstSize;

		char **first = new char*[firstSize];
		memcpy(first, _arr, sizeof(char*)*firstSize);

		char **second = new char*[otherSize];		
		memcpy(second, _arr + firstSize, sizeof(char*)*otherSize);

		mergeSorting(first, firstSize);
		mergeSorting(second, otherSize);

		mergeSorted(first, firstSize, second, otherSize, _arr);

		
		delete[] first;

		
		delete[] second;
	}
}