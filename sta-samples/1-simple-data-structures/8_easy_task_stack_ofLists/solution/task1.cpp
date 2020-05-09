#include "integer_vector.hpp";
#include "integer_vector.cpp";

/*=====================================================================================*/

void IntegerVectorInsertSequense(IntegerVector &_v)
{
	std::cout << "Input position: ";
	int position;
	std::cin >> position;

	assert(position >= 0 && position < _v.m_nUsed);

	IntegerVector vector2print;
	IntegerVectorInit(vector2print);

	for (int i = 0; i < position; i++)
		IntegerVectorPushBack(vector2print, _v.m_pData[i]);

	std::cout << "Input your sequense to insert: ";
	IntegerVectorReadTillZero(vector2print, std::cin);

	for (int i = position; i < _v.m_nUsed; i++)
		IntegerVectorPushBack(vector2print, _v.m_pData[i]);

	IntegerVectorPrint(vector2print, std::cout);

	IntegerVectorDestroy(vector2print);
}

/*=====================================================================================*/