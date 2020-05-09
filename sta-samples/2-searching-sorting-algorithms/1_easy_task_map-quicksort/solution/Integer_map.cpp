#include "Integer_map.hpp"
#include <cassert>
#include <iostream>

struct IntegerMap
{
	int m_nUsed;
	int m_nAllocated;
	struct Cell
	{
		int m_key;
		int m_value;
	};
	Cell *m_pData;
};

IntegerMap *IntegerMapCreate(int _Alloc)
{
	IntegerMap *pMap = new IntegerMap;

	pMap->m_nAllocated = _Alloc;
	pMap->m_nUsed = 0;
	pMap->m_pData = new IntegerMap::Cell[_Alloc];

	return pMap;
}

void IntegerMapDestroy(IntegerMap *_pMap)
{
	delete[] _pMap->m_pData;
	delete _pMap;
}

void IntegerMapClear(IntegerMap &_map)
{
	_map.m_nUsed = 0;
}

/*===========================================================================*/

void IntegerMapGrow(IntegerMap &_map)
{
	int newSize = _map.m_nAllocated * 2;
	IntegerMap::Cell *newArray = new IntegerMap::Cell[newSize];

	std::memcpy(newArray, _map.m_pData, sizeof(IntegerMap::Cell)*_map.m_nUsed);

	delete[] _map.m_pData;
	_map.m_pData = newArray;

	_map.m_nAllocated = newSize;
}

void IntegerMapPushBack(IntegerMap &_map, int _key, int _value)
{
	if (_map.m_nUsed == _map.m_nAllocated)
		IntegerMapGrow(_map);

	_map.m_pData[_map.m_nUsed].m_key = _key;
	_map.m_pData[_map.m_nUsed].m_value = _value;

	_map.m_nUsed++;
}

void IntegerMapDeleteAt(IntegerMap &_map, int _position)
{
	assert(_position >= 0 && _position < _map.m_nUsed);

	for (int i = _position + 1; i < _map.m_nUsed; i++)
		_map.m_pData[i - 1] = _map.m_pData[i];

	_map.m_nUsed--;
}

/*=========================================================================================*/

bool IntegerMapIsEmpty(const IntegerMap &_map)
{
	return _map.m_nUsed == 0;
}

int IntegerMapFindPosition(const IntegerMap &_map, int _key)
{
	for (int i = 0; i < _map.m_nUsed; i++)
	{
		if (_key == _map.m_pData[i].m_key)
			return i;
	}
	return -1;
}

bool IntegerMapHasKey(const IntegerMap &_map, int _key)
{
	assert(!IntegerMapIsEmpty(_map));

	return IntegerMapFindPosition(_map, _key) != -1;
}

void IntegerMapInsert(IntegerMap &_map, int _key, int _value)
{
	int position = IntegerMapFindPosition(_map, _key);

	if (position == -1)
		IntegerMapPushBack(_map, _key, _value);
	else
		_map.m_pData[position].m_value = _value;
}

int IntegerMapFind(const IntegerMap &_map, int _key)
{
	int position = IntegerMapFindPosition(_map, _key);

	assert(position != -1);

	return _map.m_pData[position].m_value;
}

void IntegerMapRemoveKey(IntegerMap &_map, int _key)
{
	int position = IntegerMapFindPosition(_map, _key);

	if (position != -1)
		IntegerMapDeleteAt(_map, position);
}

