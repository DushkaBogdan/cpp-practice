#include <iostream>
#include <fstream>
#include "vld.h"
#include "map_string_double.hpp"
#include "list_double.hpp"



int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Expacting 1 value!";
		return -1;
	}

	char* path = argv[1];

	std::ifstream fIn(path, std::ios::in);

	if (!fIn.is_open())
	{
		std::cout << "Wrong path: " << path << std::endl;
		return -1;
	}
	else
	{

		Map *map = MapCreate();

		char buff[100];
		double a;

		while (fIn >> buff >> a)
			MapInsertKey(*map, buff, a);


		MapPrint(*map);

		std::cout << std::endl;

		std::cout << MapFind(*map, "14/11/2012") << std::endl;
		std::cout << MapFind(*map, "13/11/2012") << std::endl;
		std::cout << MapFind(*map, "07/11/2012") << std::endl;
		std::cout << MapFind(*map, "19/11/2012") << std::endl;

		MapDestroy(map);

	}

	
	fIn.close();

}