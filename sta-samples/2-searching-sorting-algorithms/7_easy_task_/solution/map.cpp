#include "map.hpp"
#include "integer_vector.cpp"
#include "string_vector.cpp"
#include <cassert>

struct Map
{
	IntegerVector m_keys;
	StringVector m_values;
};

Map *MapCreate()
{
	Map *pMap = new Map;
	IntegerVectorInit(pMap->m_keys);
	StringVectorInit(pMap->m_values);
	return pMap;
}
void MapDestroy(Map *_pMap)
{
	IntegerVectorDestroy(_pMap->m_keys);
	StringVectorDestroy(_pMap->m_values);
	delete _pMap;
}
void MapClear(Map &_map)
{
	InegerVectorClear(_map.m_keys);
	StringVectorClear(_map.m_values);
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
char *MapFind(const Map &_map, int _key)
{
	int position = findKeyPosition(_map, _key);
	
	assert(position != -1);

	return _map.m_values.m_pString[position];

}
void MapInsertKey(Map &_map, int _key, char *_string)
{
	int position = findKeyPosition(_map, _key);

	if (position == -1)
	{
		IntegerVectorPushBack(_map.m_keys, _key);
		StringVectorPushBack(_map.m_values, _string);
	}
	else
	{
		delete _map.m_values.m_pString[position];

		_map.m_values.m_pString[position] = StringCopy(_string);
	}
}

void MapPrint(const Map &_map, std::ostream &_stream)
{
	for (int i = 0; i < _map.m_keys.m_nUsed; i++)
	{
		_stream << "Key = " << _map.m_keys.m_pData[i]
			<< " " << "Value = " << _map.m_values.m_pString[i] << "\n";
	}
}