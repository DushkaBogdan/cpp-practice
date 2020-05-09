#include "integer_map.hpp"
#include "vld.h"
#include <iostream>
#include <cassert>

int main()
{
	Map *Hotel = MapCreate();

	for (int i = 0; i < 20; i++)
	{
		MapInsertKey(*Hotel, i + 1, 0);
	}

	while (true)
	{
		std::cout << "Input Command (From 1 to 4): ";
		int temp;
		std::cin >> temp;
		
		if (temp <= 0 || temp > 4)
		{
			std::cout << "Invalid Command! Try again!" << std::endl;
			continue;
		}

		if (temp == 4)
			break;

		std::cout << "Input number (From 1 to 20): ";

		int number;
		std::cin >> number;

		if (number <= 0 || number > 20)
		{
			std::cout << "Invalid Number! Try again!" << std::endl;
			continue;
		}

		if (temp == 1)
		{
			std::cout << "Number: " << number << " is "
				<<	(MapFind(*Hotel, number) == 0 ?	" " : " not ")
				<< "Free!" << std::endl;
			
		}
		else if (temp == 2)
		{
			if (MapFind(*Hotel, number) == 0)
				MapInsertKey(*Hotel, number, 1);
			else
				std::cout << "Number: " << number << " is already occupied!" << std::endl;
		}
		else if (temp == 3)
		{
			if (MapFind(*Hotel, number) == 1)
				MapInsertKey(*Hotel, number, 0);
			else
				std::cout << "Number: " << number << " is already Free!" << std::endl;
		}
	}

	MapDestroy(Hotel);
}
