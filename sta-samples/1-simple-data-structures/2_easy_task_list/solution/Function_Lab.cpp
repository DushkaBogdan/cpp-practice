#include "integer_vector.hpp"

void Sort_Sequense(const IntegerVector &_v)
{
	IntegerVector t;
	IntegerVectorInit(t);

	IntegerVectorPushBack(t, _v.m_pData[0]);

	int counter = 1;

	for (int i = 1; i < _v.m_nUsed; i++)
	{
		if (_v.m_pData[i] - _v.m_pData[i - 1] == 1)
		{
			IntegerVectorPushBack(t, _v.m_pData[i]);
			counter++;
			if (i == _v.m_nUsed - 1 && counter >= 3)
			{
				if (!IntegerVectorIsEmpty(t))
					IntegerVectorPrint(t, std::cout);
			}
		}
		else
		{
			if (counter >= 3)
			{
				IntegerVectorPrint(t, std::cout);
				std::cout << std::endl;
			}
			InegerVectorClear(t);
			counter = 1;
			IntegerVectorPushBack(t, _v.m_pData[i]);
		}
	}

	IntegerVectorDestroy(t);
}