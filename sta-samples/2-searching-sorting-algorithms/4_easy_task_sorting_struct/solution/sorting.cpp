#include <iostream>
#include "vld.h"

struct PersonName
{
	char *m_lastName;
	char m_initials[2];
};

void PersonInit(PersonName &_person, int _lastnameSize = 15)
{
	_person.m_lastName = new char[_lastnameSize];
}

void PersonDelete(PersonName &_pPerson)
{
	delete[] _pPerson.m_lastName;
}

void selectionSort(PersonName *_arr, int _size)
{
	for (int i = 0; i < _size - 1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < _size; j++)
		{
			if (    _stricmp(_arr[j].m_lastName, _arr[lowIndex].m_lastName) < 0
				|| (_stricmp(_arr[j].m_lastName, _arr[lowIndex].m_lastName) == 0
				&&  _stricmp(_arr[j].m_initials, _arr[lowIndex].m_initials) < 0))
				lowIndex = j;
		}

		std::swap(_arr[i], _arr[lowIndex]);
	}
}

void bubbleSort(PersonName *_arr, int _size)
{
	for (int i = 0; i < _size-1; i++)
	{
		for (int j = _size - 1; j > i; j--)
		{
			if (_stricmp(_arr[j - 1].m_lastName, _arr[j].m_lastName) > 0
				|| (_stricmp(_arr[j - 1].m_lastName, _arr[j].m_lastName) == 0
				&& _stricmp(_arr[j - 1].m_initials, _arr[j].m_initials) > 0))
			{
				std::swap(_arr[j], _arr[j-1]);
			}
		}
	}
}

int main()
{
	const int size = 5;
	PersonName arr[size];

	for (int i = 0; i < size; i++)
	{
		PersonName name;
		PersonInit(name);
		std::cout << i + 1
			<< " from " << size
			<< ": " << "Input Last Name: ";
		std::cin >> name.m_lastName;
		std::cout << std::endl 
			<< "Input Initials: ";
		std::cin >> name.m_initials;
		std::cout << std::endl;
		arr[i] = name;
	}
	
	//selectionSort(arr, size);
	bubbleSort(arr, size);

	for (int i = 0; i < size; i++)
	{
		std::cout << std::endl << arr[i].m_lastName << ' '
			<< arr[i].m_initials << std::endl;

		PersonDelete(arr[i]);
	}
	
}