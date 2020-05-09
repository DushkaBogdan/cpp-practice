#include "string_set.hpp"
#include "string_vector.cpp"
#include <iostream>
#include "vld.h"



int main()
{
	StringSet *set = StringSetCreate();

	char *arr[6] = { "dr", "aBB", "lc", "cddd", "dr", "wdym"};
	char *arr1[20] = { "dr", "asd", "lc", "cddd", "dr", "awdjajd",
		"kbnd", "uwnd", "o", "kn", "ws", "asd", "asd", "ft", "ws", "vv", "ews", "asd", "tax", "mmi"};

	for (int i = 0; i < 20; i++)
	{
		StringSetInsertKeyDuplicated(*set, arr1[i]);
	}

	std::cout << StringSetKeysCount(*set, "ws");
		

	StringSetDestroy(set);
}