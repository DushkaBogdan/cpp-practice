#include "integer_vector.hpp"
#include "integer_vector.cpp"

void IntegerVectorPrintback(const IntegerVector &_v)
{
	IntegerVector v1;
	IntegerVectorInit(v1);

	std::cout << "Input Position: ";
	int position;
	std::cin >> position;
	assert(position > 0 && position <= _v.m_nUsed);

	for (int i = _v.m_nUsed-1; i >= position; i--)
		IntegerVectorPushBack(v1, _v.m_pData[i]);
	for (int i = 0; i < position; i++)
		IntegerVectorPushBack(v1, _v.m_pData[i]);

	IntegerVectorPrint(v1, std::cout);

	IntegerVectorDestroy(v1);
}