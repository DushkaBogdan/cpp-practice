#include "map.hpp"
#include "integer_vector.cpp"

struct Map
{
	IntegerVector m_keys;
	IntegerVector m_values;
};

Map* MapCreate()
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

int findKeyPosition(const Map &_map, const int _key)
{
	int position = -1;

	for (int i = 0; i < _map.m_keys.m_nUsed; i++)
	{
		if (_map.m_keys.m_pData[i] == _key)
		{
			position = i;
			break;
		}
	}

	return position;
}

bool MapIsEmpty(const Map &_map)
{
	return IntegerVectorIsEmpty(_map.m_keys);
}

bool MapHasKey(const Map &_map, const int _key)
{
	return findKeyPosition(_map, _key) != -1;
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
		_map.m_values.m_pData[position] += _value;
	}
}

void MapPrint(const Map &_map, std::ostream &_stream)
{
	if (!MapIsEmpty(_map))
	{
		for (int i = 0; i < _map.m_keys.m_nUsed; i++)
		{
			_stream << "Length: " << _map.m_keys.m_pData[i] << "; Count: "
				<< _map.m_values.m_pData[i] << std::endl;
		}
	}
}
