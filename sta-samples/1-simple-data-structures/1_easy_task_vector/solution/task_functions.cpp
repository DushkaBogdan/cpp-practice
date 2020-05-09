#include "lab_functions.hpp"
#include <cassert>

void IntegerVectorReadTillZeroOrNegative(IntegerVector & _vector, std::istream &_stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream && temp > 0)
			IntegerVectorPushBack(_vector, temp);
		else
			break;
	}
}

void IntegerSort(IntegerVector & _vector)
{

	int position;
	std::cin >> position;

	assert(position >= 0 && position <= _vector.m_nUsed);


	IntegerVector smaller;
	IntegerVectorInit(smaller);

	IntegerVector bigger;
	IntegerVectorInit(bigger);

	int value = _vector.m_pData[position];

	for (int i = 0; i < _vector.m_nUsed; i++)
	{
		(_vector.m_pData[i] <= value) ?
			IntegerVectorPushBack(smaller, _vector.m_pData[i]) :
			IntegerVectorPushBack(bigger, _vector.m_pData[i]);
	}

	IntegerVectorPrint(smaller, std::cout);
	std::cout << std::endl;
	IntegerVectorPrint(bigger, std::cout);

	IntegerVectorDestroy(smaller);
	IntegerVectorDestroy(bigger);
}
