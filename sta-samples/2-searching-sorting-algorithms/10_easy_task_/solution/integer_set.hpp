#ifndef _INTEGER_SET_HPP_
#define _INTEGER_SET_HPP_
#include <iostream>

struct IntegerSet;

IntegerSet *IntegerSetCreate();
void IntegerSetDestroy(IntegerSet *_pSet);
void IntegerSetClear(IntegerSet &_set);
bool IntegerSetIsEmpty(const IntegerSet &_set);
bool IntegerSetHasKey(const IntegerSet &_set, int _key);
void IntegerSetInsertKey(IntegerSet &_set, int _key);
void IntegerSetRemoveKey(IntegerSet &_set, int _key);
void IntegerSetPrint(const IntegerSet &_set, std::ostream &_stream, char _sep = ' ');

void IntegerSetUnite(
	const IntegerSet &_firstSet,
	const IntegerSet &_secondSet,
	IntegerSet &_targetSet);

void IntegerSetInterSec(
	const IntegerSet &_firstSet,
	const IntegerSet &_secondSet,
	IntegerSet &_targetSet);

void IntegerSetDiff(
	const IntegerSet &_firstSet,
	const IntegerSet &_secondSet,
	IntegerSet &_targetSet);

bool IntegerSetIsSubset(const IntegerSet &_set1, const IntegerSet &_targerSet);
bool IntegerSetIsEqual(const IntegerSet &_set1, const IntegerSet &_set2);
int IntegerSetMinKey(const IntegerSet &_set);
int IntegerSetMaxKey(const IntegerSet &_set);

#endif //_INTEGER_SET_HPP_