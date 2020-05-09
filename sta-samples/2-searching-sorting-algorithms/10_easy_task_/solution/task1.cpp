//#include "integer_set.hpp"
//#include "integer_list.hpp"
//#include "vld.h"
//#include <iostream>
//#include <cassert>
//
//
//
//int main()
//{
//	IntegerSet *set = IntegerSetCreate();
//	IntegerSet *set1 = IntegerSetCreate();
//	IntegerSet *set2 = IntegerSetCreate();
//	assert(IntegerSetIsEmpty(*set));
//
//	int arr[] = { 0, 10, 15, 20 };
//	int arr1[] = { 10, 0, 15, 20 };
//
//	for (int i = 0; i < 4; i++)
//		IntegerSetInsertKey(*set, arr[i]);
//	for (int i = 0; i < 4; i++)
//		IntegerSetInsertKey(*set1, arr1[i]);
//
//	IntegerSetUnite(*set, *set1, *set2);
//
//	assert(IntegerSetIsSubset(*set, *set2));
//	assert(IntegerSetIsSubset(*set1, *set2));
//	assert(IntegerSetIsEqual(*set1, *set));
//	assert(IntegerSetMinKey(*set1) == 0);
//	assert(IntegerSetMaxKey(*set1) == 20);
//
//	//IntegerSetPrint(*set2, std::cout);
//
//	IntegerSetDestroy(set);
//	IntegerSetDestroy(set1);
//	IntegerSetDestroy(set2);
//}