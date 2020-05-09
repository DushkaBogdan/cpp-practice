#include "map.hpp"
#include "vld.h"
#include <iostream>

int main()
{

	Map *map = MapCreate();

	const int size = 5;

	int keys[size] = { 5, 9, 61, 3, 2 };

	char *values[] = { "First", "Second", "Third", "Forth", "Fifth" };

	for (int i = 0; i < size; i++)
	{
		MapInsertKey(*map, keys[i], values[i]);
	}

	while (true)
	{
		int key;
		std::cin >> key;

		if (!std::cin || key == 0)
			break;
		
		if (!MapHasKey(*map, key))
			std::cout << "There is no key, try again!" << std::endl;
		else
			std::cout << "Name of ID: " << key << " is " << MapFind(*map, key) << std::endl;

	}

	MapDestroy(map);
}