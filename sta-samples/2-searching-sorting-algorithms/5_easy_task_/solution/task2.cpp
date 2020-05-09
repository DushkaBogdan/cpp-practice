#include <iostream>
#include <ctime>


void binarySearch(int *_arr, int _size, int _searchValue, int &_counter, bool &hasIndex)
{
	int firstIndex = 0;
	int lastIndex = _size;
	int midIndex = -1;

	while (firstIndex < lastIndex)
	{
		++_counter;
		midIndex = ((lastIndex - firstIndex) / 2) + firstIndex;

		if (_arr[midIndex] == _searchValue)
		{
			hasIndex = true;
			break;
		}
		else if (_searchValue < _arr[midIndex])
			lastIndex = midIndex;
		else
			firstIndex = midIndex + 1;
	}
}

void selectionSort(int *_arr, int _size)
{
	for (int i = 0; i < _size-1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < _size; j++)
		{
			if (_arr[j] < _arr[lowIndex])
				lowIndex = j;
		}
		std::swap(_arr[i], _arr[lowIndex]);
	}
}

void quickSort(int *_arr, const int _size)
{
	
	if (_size < 100)
	{
		selectionSort(_arr, _size);
		return;
	}

	int leftIndex = -1, rightIndex = _size;

	int tempIndex = rand() % _size;

	int temp = _arr[tempIndex];

	while (true)
	{
		while (_arr[++leftIndex] < temp);

		while (_arr[--rightIndex] > temp)
		{
			if (leftIndex == rightIndex)
				break;
		}

		if (leftIndex >= rightIndex)
			break;

		std::swap(_arr[leftIndex], _arr[rightIndex]);
	}

	if (leftIndex == 0)
		leftIndex = 1;

	quickSort(_arr, leftIndex);
	quickSort(_arr + leftIndex, _size - leftIndex);
}


int main()
{
	srand(time(0));

	const int size = 1000000;
	int *arr = new int[size];

	for (int i = 0; i < size; i++)
		arr[i] = rand() % 400;


	int pivotIndex = rand() % size;

	int pivot = arr[pivotIndex];

	bool hasValue = false;
	bool hasValue1 = false;
	int counter = 0;
	int counter1 = 0;
	clock_t clock0 = clock();

	for (int i = 0; i < size; i++)
	{
		++counter;
		if (arr[i] == pivot)
		{
			hasValue = true;
			break;
		}
	}


	clock_t clock1 = clock();

	quickSort(arr, size);
	//selectionSort(arr, size);

	clock_t clock1_1 = clock();

	binarySearch(arr, size, pivot, counter1, hasValue1);

	clock_t clock2 = clock();

	std::cout << "Searching Value is = " << pivot
		<< "; Sequense has " << (hasValue == true ? " " : " no ") << "value"
		<< "; Sequense has " << (hasValue1 == true ? " " : " no ") << "value1" << std::endl;
	std::cout
		<< "Clock1 - CLock0 = " << (clock1 - clock0)
		<< "; Clock1_1 = " << (clock1_1)
		<< "; Clock2 - Clock1_1 = " << (clock2 - clock1_1)
		<< std::endl;
	std::cout << "Counter = " << counter << "; Counter1 = " << counter1 << std::endl;

	delete[] arr;



	
}