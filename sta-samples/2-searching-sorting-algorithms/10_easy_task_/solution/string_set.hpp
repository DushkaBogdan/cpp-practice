#ifndef _STRING_SET_HPP_
#define _STRING_SET_HPP_
#include <iostream>

struct StringSet;

StringSet *StringSetCreate();
void StringSetDestroy(StringSet *_pSet);
void StringSetClear(StringSet &_set);
bool StringSetIsEmpty(const StringSet &_set);
int StringSetKeyPosition(const StringSet &_set, const char *_key);
bool StringSetHasKey(const StringSet &_set, const char *_key);
void StringSetInsertKey(StringSet &_set, const char *_key);
void StringSetInsertKeyDuplicated(StringSet &_set, const char *_key);
void StringSetRemoveKey(StringSet &_set, const char *_key);
void StringSetPrint(const StringSet &_set, std::ostream &_stream, char _sep = ' ');

void StringSetUnite(
	const StringSet &_firstSet,
	const StringSet &_secondSet,
	StringSet &_targetSet);

void StringSetInterSec(
	const StringSet &_firstSet,
	const StringSet &_secondSet,
	StringSet &_targetSet);

void StringSetDiff(
	const StringSet &_firstSet,
	const StringSet &_secondSet,
	StringSet &_targetSet);

int StringSetKeysCount(StringSet &_set, const char *_key);

#endif //_STRING_SET_HPP_