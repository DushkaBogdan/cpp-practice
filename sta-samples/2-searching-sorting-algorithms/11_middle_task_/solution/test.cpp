#include "bit_set.hpp"
#include <iostream>
#include <cassert>

void displayBits1(__int64 _value);


int main()
{
	
	__int64 arr[64];
	__int64 flag = 1;
	for (int i = 0; i < 64; i++)
	{
		arr[i] = flag;
		flag <<= 1;
	}

	
	BitSet *set = BitSetCreate();
	BitSet *set1 = BitSetCreate();
	BitSet *targetSet = BitSetCreate();

	BitSetInsertKey(*set, arr[4]);
	BitSetInsertKey(*set, arr[2]);
	BitSetInsertKey(*set, arr[63]);
	BitSetRemoveKey(*set, arr[4]);
	assert(BitSetHasKey(*set, arr[2]));
	assert(!BitSetHasKey(*set, arr[4]));

	BitSetInsertKey(*set1, arr[2]);
	BitSetInsertKey(*set1, arr[7]);

	BitSetDifferense(*set, *set1, *targetSet);

	BitSetDisplay(*targetSet);

	BitSetDestroy(set);
	BitSetDestroy(set1);
	BitSetDestroy(targetSet);


}


void displayBits1(__int64 _value)
{
	_int64 dispMask = __int64(1) << 63;
	//dispMask <<= 63;

	for (int i = 1; i <= 64; i++)
	{
		std::cout << (_value & dispMask ? "1" : "0");
		if (i % 8 == 0)
			std::cout << " ";

		_value <<= 1;
	}
}

