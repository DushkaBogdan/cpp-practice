#include <iostream>
#include <fstream>

#include "vld.h"

void selectionSortingStr(char **_strArr, int _size)
{
	for (int i = 0; i < (_size-1); i++)
	{
		int lowIndex = i;

		for (int j = i+1; j < _size; j++)
		{
			if (_stricmp(_strArr[j], _strArr[lowIndex]) < 0)
				lowIndex = j;
		}
		std::swap(_strArr[i], _strArr[lowIndex]);
	}
}

void quickSortingStr(char **_strArr, int _size)
{

	if (_size < 3)
	{
		selectionSortingStr(_strArr, _size);
		return;
	}
	int tempIndex = rand() % _size;
	char *temp = _strArr[tempIndex];

	int leftIndex = -1;
	int rightIndex = _size;

	while (true)
	{
		while (_stricmp(_strArr[++leftIndex], temp) < 0);
		while (_stricmp(_strArr[--rightIndex], temp) > 0)
		{
			if (leftIndex == rightIndex)
				break;
		}

		if (leftIndex >= rightIndex)
			break;

		std::swap(_strArr[leftIndex], _strArr[rightIndex]);
	}

	if (leftIndex == 0)
	{
		leftIndex = 1;
	}

	quickSortingStr(_strArr, leftIndex);
	quickSortingStr(_strArr + leftIndex, _size - leftIndex);

}

char *strCopy(const char* _str)
{
	int length = strlen(_str);
	char *charBuff = new char[length + 1];
	//strcpy(charBuff, _str);
	strcpy_s(charBuff, (length + 1), _str);

	return charBuff;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Expected 1 expression!" << std::endl;
		return -1;
	}
	else
	{
		char *path = argv[1];

		std::ifstream fIn;
		fIn.open(path, std::ios::in);

		if (!fIn.is_open())
		{
			std::cout << "Error of opening file: " << path << std::endl;
			return -1;
		}
		else
		{
			char **stringArr = new char*[50];
			int counter = 0;

			while (true)
			{
				if (fIn.eof())
					break;
				char charBuff[50];
				fIn >> charBuff;

				stringArr[counter++] = strCopy( charBuff );
			}

			//selectionSortingStr(stringArr, counter);
			quickSortingStr(stringArr, counter);

			for (int i = 0; i < counter; i++)
				std::cout << stringArr[i] << " ";


			for (int i = 0; i < counter; i++)
				delete[] stringArr[i];
			delete[] stringArr;
		}

		fIn.close();
	}
}