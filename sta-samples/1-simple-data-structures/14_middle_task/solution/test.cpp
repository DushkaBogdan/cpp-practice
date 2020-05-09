#include <iostream>
#include <fstream>
#include <cassert>
#include "integer_vector.hpp"
#include "integer_vector.cpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Incorrect input format!" << std::endl;
		return -1;
	}
	char *firstFilePath = argv[1];
	char *secondFilePath = argv[2];
	char *thirdFilePath = argv[3];


	std::ifstream fIn1(firstFilePath, std::ios::in);
	std::ifstream fIn2(secondFilePath, std::ios::in);
	std::ofstream fOut(thirdFilePath);

	if (!fIn1.is_open())
	{
		std::cout << "Error of opening file " << firstFilePath << std::endl;
		return -1;
	}
	if (!fIn2.is_open())
	{
		std::cout << "Error of opening file " << secondFilePath << std::endl;
		return -1;
	}
	if (!fOut.is_open())
	{
		std::cout << "Error of opening file " << thirdFilePath << std::endl;
		return -1;
	}

	IntegerVector numbers;
	IntegerVectorInit(numbers);

	IntegerVector sums;
	IntegerVectorInit(sums);

	

	while (true)
	{
		int number;
		int sum;

		fIn1 >> number >> sum;

		if (fIn1.eof())
			break;
		else if (!fIn1)
		{
			std::cout << "Mistake in file...\n";
			IntegerVectorDestroy(numbers);
			IntegerVectorDestroy(sums);
			return -1;
		}
		
		if (IntegerVectorIsEmpty(numbers))
		{
			IntegerVectorPushBack(numbers, number);
			IntegerVectorPushBack(sums, sum);
		}
		else
		{
			bool hasData = false;
			int positionOfData;
			for (int i = 0; i < numbers.m_nUsed; i++)
			{
				if (numbers.m_pData[i] == number)
				{
					hasData = true;
					positionOfData = i;
					break;
				}
			}
			if (hasData)
			{
				sums.m_pData[positionOfData] += sum;
			}
			else
			{
					IntegerVectorPushBack(numbers, number);
					IntegerVectorPushBack(sums, sum);
			}
		}
	}

	/*===============================================================================*/


	while (true)
	{

		int number;
		int sum;

		fIn2 >> number >> sum;

		

		if (IntegerVectorIsEmpty(numbers))
		{
			IntegerVectorPushBack(numbers, number);
			IntegerVectorPushBack(sums, sum);
		}
		else
		{
			bool hasData = false;
			int positionOfData;
			for (int i = 0; i < numbers.m_nUsed; i++)
			{
				if (numbers.m_pData[i] == number)
				{
					hasData = true;
					positionOfData = i;
					break;
				}
			}
			if (hasData)
			{
				sums.m_pData[positionOfData] += sum;
			}
			else
			{
				IntegerVectorPushBack(numbers, number);
				IntegerVectorPushBack(sums, sum);
			}
		}
	}

	/*========================================================================================*/

	for (int i = 0; i < numbers.m_nUsed; i++)
	{
		fOut << numbers.m_pData[i] << ' ' << sums.m_pData[i] << std::endl;
		
	}

	/*==========================================================================================*/
	fIn1.close();
	fIn2.close();
	fOut.close();

	IntegerVectorDestroy(numbers);
	IntegerVectorDestroy(sums);
}
