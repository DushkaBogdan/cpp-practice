#include "integer_map.hpp"
#include "integer_vector.cpp"
#include <cassert>

struct Map
{
	IntegerVector m_keys;
	IntegerVector m_values;
};

Map *MapCreate()
{
	Map *pMap = new Map;
	IntegerVectorInit(pMap->m_keys);
	IntegerVectorInit(pMap->m_values);
	return pMap;
}
void MapDestroy(Map *_pMap)
{
	IntegerVectorDestroy(_pMap->m_keys);
	IntegerVectorDestroy(_pMap->m_values);
	delete _pMap;
}
void MapClear(Map &_map)
{
	InegerVectorClear(_map.m_keys);
	InegerVectorClear(_map.m_values);
}

int findKeyPosition(const Map &_map, int _key)
{
	int pos = -1;

	for (int i = 0; i < _map.m_keys.m_nUsed; i++)
	{
		if (_key == _map.m_keys.m_pData[i])
		{
			pos = i;
			break;
		}
	}
	return pos;
}

bool MapHasKey(const Map &_map, int _key)
{
	return findKeyPosition(_map, _key) != -1;
}
int MapFind(const Map &_map, int _key)
{
	int position = findKeyPosition(_map, _key);

	assert(position != -1);

	return _map.m_values.m_pData[position];

}
void MapInsertKey(Map &_map, int _key, int _value)
{
	int position = findKeyPosition(_map, _key);

	if (position == -1)
	{
		IntegerVectorPushBack(_map.m_keys, _key);
		IntegerVectorPushBack(_map.m_values, _value);
	}
	else
	{
		_map.m_values.m_pData[position] = _value;
	}
}