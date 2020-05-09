#include <fstream>
#include <iostream>
#include <string>
#include "string_vector.hpp"
#include "string_vector.cpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Expect path!";
		return -1;
	}
	else
	{
		std::ifstream fIn(argv[1], std::ios::in);

		if (!fIn.is_open())
		{
			std::cout << "File is not opened!";
			return -1;
		}
		else
		{
			int LongestStr = 0;
			char string[100];

			StringVector s;
			StringVectorInit(s);

			while (!fIn.eof())
			{
				fIn.getline(string, 100, '\n');
				
				if (strlen(string) > LongestStr)
				{
					LongestStr = strlen(string);
					StringVectorClear(s);
					StringVectorPushBack(s, string);
				}
				else if (strlen(string) == LongestStr)
					StringVectorPushBack(s, string);
			}
			
			StringVectorPrint(s, std::cout);
			StringVectorDestroy(s);
		}
		fIn.close();
	}
}