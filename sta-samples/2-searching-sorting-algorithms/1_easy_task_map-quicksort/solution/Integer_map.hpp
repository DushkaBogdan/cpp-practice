#ifndef _INTEGER_MAP_HPP_
#define _INTEGER_MAP_HPP_

struct IntegerMap;

IntegerMap *IntegerMapCreate(int _Alloc = 10);

void IntegerMapDestroy(IntegerMap *_pMap);

void IntegerMapClear(IntegerMap &_map);

bool IntegerMapIsEmpty(const IntegerMap &_map);

bool IntegerMapHasKey(const IntegerMap &_map, int _key);

void IntegerMapInsert(IntegerMap &_map, int _key, int _value);

int IntegerMapFind(const IntegerMap &_map, int _key);

void IntegerMapRemoveKey(IntegerMap &_map, int _key);

#endif //_INTEGER_MAP_HPP_

