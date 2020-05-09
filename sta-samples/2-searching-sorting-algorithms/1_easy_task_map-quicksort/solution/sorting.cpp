#include <iostream>
#include <ctime>

void bubbleSorting(int *_arr, const int _size)
{
	for (int i = _size; i > 0; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (_arr[j - 1] < _arr[j])
			{
				int temp = _arr[j - 1];
				_arr[j - 1] = _arr[j];
				_arr[j] = temp;
			}
		}
	}
}

void insertionSorting(int *_arr, const int _size)
{
	for (int i = 1; i < _size; i++)
	{
		int j = i;
		while (j && (_arr[j - 1] < _arr[j]))
		{
			int temp = _arr[j - 1];
			_arr[j - 1] = _arr[j];
			_arr[j] = temp;

			--j;
		}
	}
}

void selectionSorting(int *_arr, const int _size)
{
	for (int i = 0; i < _size-1; i++)
	{
		int lowIndex = i;
		for (int j = i+1; j < _size; j++)
		{
			if (_arr[j] < _arr[lowIndex])
				lowIndex = j;
		}
		int temp = _arr[lowIndex];
		_arr[lowIndex] = _arr[i];
		_arr[i] = temp;
	}
}


void mergeSorted(
	const int *_pFirst, const  int _firstSize,
	const int *_pSecond, const int _secondSize,
	int *_pTarget)
{
	int firstIndex = 0, secondIndex = 0, targetIndex = 0;

	while (firstIndex < _firstSize && secondIndex < _secondSize)
	{
		if (_pFirst[firstIndex] <= _pSecond[secondIndex])
		{
			_pTarget[targetIndex] = _pFirst[firstIndex];
			firstIndex++;
		}
		else
		{
			_pTarget[targetIndex] = _pSecond[secondIndex];
			secondIndex++;
		}
		++targetIndex;
	}

	if (_firstSize > firstIndex)
	{
		memcpy(_pTarget +targetIndex,
			_pFirst + firstIndex,
			sizeof(int)*(_firstSize - firstIndex));
	}
	else if (_secondSize > secondIndex)
	{
		memcpy(_pTarget + targetIndex,
			_pSecond + secondIndex,
			sizeof(int)*(_secondSize - secondIndex));
	}
}

void mergeSorting(int *_arr, const int _size)
{
	if (_size < 10)
	{
		selectionSorting(_arr, _size);
	}
	else
	{
		int firstSize = _size / 2;
		int otherSize = _size - firstSize;

		int *firstArr = new int[firstSize];
		memcpy(firstArr, _arr, sizeof(int)*firstSize);

		int *secondArr = new int[otherSize];
		memcpy(secondArr, _arr + firstSize, sizeof(int)*otherSize);


		mergeSorting(firstArr, firstSize);
		mergeSorting(secondArr, otherSize);

		mergeSorted(firstArr, firstSize, secondArr, otherSize, _arr);

		delete[] firstArr;
		delete[] secondArr;
	}
}

void quickSorting(int *_arr, int _size)
{
	if (_size < 10)
	{
		selectionSorting(_arr, _size);
		return;
	}

	int leftIndex = -1, rightIndex = _size;

	int thirdSize = _size / 3;

	int pivotPosition1 = rand() % thirdSize;
	int pivotPosition2 = rand() % thirdSize + thirdSize;
	int pivotPosition3 = rand() % thirdSize + (2*thirdSize);
	
	int pivotPosition = 0;

	if (   (_arr[pivotPosition1] >= _arr[pivotPosition2] && _arr[pivotPosition1] <= _arr[pivotPosition3])
		|| (_arr[pivotPosition1] <= _arr[pivotPosition2] && _arr[pivotPosition1] >= _arr[pivotPosition3]))
		pivotPosition = pivotPosition1;
	else if ((_arr[pivotPosition2] >= _arr[pivotPosition1] && _arr[pivotPosition2] <= _arr[pivotPosition3])
		||   (_arr[pivotPosition2] <= _arr[pivotPosition1] && _arr[pivotPosition2] >= _arr[pivotPosition3]))
	{
		pivotPosition = pivotPosition2;
	}
	else if ((_arr[pivotPosition3] >= _arr[pivotPosition2] && _arr[pivotPosition3] <= _arr[pivotPosition1])
		||   (_arr[pivotPosition3] <= _arr[pivotPosition2] && _arr[pivotPosition3] >= _arr[pivotPosition1]))
		pivotPosition = pivotPosition3;

	int pivot = _arr[pivotPosition];

	

	while (true)
	{
		while (_arr[++leftIndex] < pivot);

		while (_arr[--rightIndex] >= pivot)
			if (leftIndex == rightIndex)
				break;
		if (leftIndex >= rightIndex)
			break;

		int temp = _arr[leftIndex];
		_arr[leftIndex] = _arr[rightIndex];
		_arr[rightIndex] = temp;
	}

	if (leftIndex == 0)
		leftIndex = 1;

	quickSorting(_arr, leftIndex);

	quickSorting(_arr + leftIndex, _size - leftIndex);
}

int main()
{


	const int arrsize1 = 50000;
	int arr1[arrsize1];

	for (int i = 0; i < arrsize1; i++)
		arr1[i] = rand() % 30;



	clock_t clock1 = clock();

	quickSorting(arr1, arrsize1);

	clock_t clock2 = clock();

	
	double timeInSec = ((double)(clock2 - clock1) / (double)CLOCKS_PER_SEC);

	std::cout << std::endl << "Time of sorting array: " << timeInSec << " sec;" << std::endl;

}