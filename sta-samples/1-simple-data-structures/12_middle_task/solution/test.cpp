#include <fstream>
#include <iostream>
#include "string_vector.hpp"
#include "string_vector.cpp"
#include "integer_vector.hpp"
#include "integer_vector.cpp"

int main(int argc, char *argv[])
{
	if (argc > 3)
	{
		std::cout << "Expect less imputs!" << std::endl;
	}
	else if (argc < 3)
		std::cout << "Expect more imputs!" << std::endl;
	else
	{
		char *path = argv[1];
		std::ifstream fIn(path, std::ios::in);

		if (!fIn.is_open())
		{
			std::cout << "Error of opening file!";
			return -1;
		}
		else 
		{
			std::cout << "File is Opened!" << std::endl;

			int LimitAge = atoi(argv[2]);
			assert(LimitAge > 10);

			StringVector names;
			StringVectorInit(names);

			IntegerVector ages;
			IntegerVectorInit(ages);

			char name[10];
			int age;

			int LowestAge = LimitAge;
			

			while (fIn >> name >> age)
			{
				if (IntegerVectorIsEmpty(ages))
				{
					if (LowestAge <= age)
					{
						LowestAge = age;
						StringVectorPushBack(names, name);
						IntegerVectorPushBack(ages, age);
					}
				}
				else
				{
					if (LowestAge == age)
					{
						StringVectorPushBack(names, name);
						IntegerVectorPushBack(ages, age);
					}
					else if (LowestAge < age)
					{
						LowestAge = age;

						StringVectorClear(names);
						InegerVectorClear(ages);

						StringVectorPushBack(names, name);
						IntegerVectorPushBack(ages, age);
					}
				}
			}

			for (int i = 0; i < ages.m_nUsed; i++)
			{
				std::cout << names.m_pString[i] << ' ' << ages.m_pData[i];
				std::cout << std::endl;
			}

			StringVectorDestroy(names);
			IntegerVectorDestroy(ages);
		}
		fIn.close();
	}
}