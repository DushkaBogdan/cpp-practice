#include "map.hpp"
#include "integer_vector.hpp"
#include "string_vector.hpp"

struct Map
{
	StringVector m_keys;
	IntegerVector m_values;
};

Map *MapCreate()
{
	Map *pMap = new Map;
	StringVectorInit(pMap->m_keys);
	IntegerVectorInit(pMap->m_values);

	return pMap;
}

void MapDestroy(Map *_pMap)
{
	StringVectorDestroy(_pMap->m_keys);
	IntegerVectorDestroy(_pMap->m_values);

	delete _pMap;
}

void MapClear(Map &_map)
{
	StringVectorClear(_map.m_keys);
	InegerVectorClear(_map.m_values);
}

bool MapIsEmpty(const Map &_map)
{
	return StringVectorIsEmpty(_map.m_keys);
}

int MapFindKeyPosition(const Map &_map, const char *_key)
{
	int position = -1;

	for (int i = 0; i < _map.m_keys.m_nUsed; i++)
	{
		if (strcmp(_map.m_keys.m_pString[i], _key) == 0)
		{
			position = i;
			break;
		}
	}
	return position;
}

bool MapHasKey(const Map &_map, const char *_key)
{
	return MapFindKeyPosition(_map, _key) != -1;
}

void MapInsertKey(Map &_map, const char *_key, const int _value)
{
	int flag = MapFindKeyPosition(_map, _key);

	if (flag != -1)
	{

		_map.m_values.m_pData[flag] = _value;
	}
	else
	{
		StringVectorPushBack(_map.m_keys, _key);
		IntegerVectorPushBack(_map.m_values, _value);
	}
}

void MapDeleteKey(Map &_map, char *_key)
{
	int position = MapFindKeyPosition(_map, _key);

	if (position == -1)
		std::cout << "There is no such Key in Map!" << std::endl;
	else
	{
		StringVectorDeleteAt(_map.m_keys, position);
		IntegerVectorDeleteAt(_map.m_values, position);
	}
}

int MapFind(const Map &_map, const char *_key)
{
	int position = MapFindKeyPosition(_map, _key);

	return _map.m_values.m_pData[position];
}

void MapPrint(const Map &_map, std::ostream &_stream)
{
	if (!MapIsEmpty(_map))
	{
		for (int i = 0; i < _map.m_keys.m_nUsed; i++)
		{
			_stream << _map.m_keys.m_pString[i] << ' ' << _map.m_values.m_pData[i] << std::endl;
		}
	}
	else
		_stream << "Map is Empty!" << std::endl;
}