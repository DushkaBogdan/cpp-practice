#include "multi_map.hpp"
#include "integer_vector.cpp"

struct Map
{
	IntegerVector m_keys;
	IntegerVector m_values;
};

Map* mapCreate()
{
	Map *pMap = new Map;
	IntegerVectorInit(pMap->m_keys);
	IntegerVectorInit(pMap->m_values);

	return pMap;
}

void mapDestroy(Map *_pMap)
{
	IntegerVectorDestroy(_pMap->m_keys);
	IntegerVectorDestroy(_pMap->m_values);

	delete _pMap;
}

void mapClear(Map &_map)
{
	InegerVectorClear(_map.m_keys);
	InegerVectorClear(_map.m_values);
}

int findKeyPositionFront(const Map &_map, int _key)
{
	int position = -1;

	for (int i = 0; i < _map.m_keys.m_nUsed; i++)
	{
		if (_key == _map.m_keys.m_pData[i])
		{
			position = i;
			break;
		}
	}
	return position;
}

int findKeyPosition(const Map &_map, int _key)
{
	int position = -1;

	for (int i = 1; i < _map.m_keys.m_nUsed; i++)
	{
		if (_key == _map.m_keys.m_pData[i - 1] && _key != _map.m_keys.m_pData[i])
		{
			position = i - 1;
			break;
		}
	}
	return position;
}

void mapInsertKey(Map &_map, int _key, int _value)
{
	if (IntegerVectorIsEmpty(_map.m_keys))
	{
		IntegerVectorPushBack(_map.m_keys, _key);
		IntegerVectorPushBack(_map.m_values, _value);
	}
	else
	{
		int position = findKeyPosition(_map, _key);

		if (position == -1)
		{
			int counter = 0;
			while (_map.m_keys.m_pData[counter] < _key && counter < _map.m_keys.m_nUsed)
			{
				counter++;
			}

			if (counter == _map.m_keys.m_nUsed)
			{
				IntegerVectorPushBack(_map.m_keys, _key);
				IntegerVectorPushBack(_map.m_values, _value);
			}
			else
			{
				IntegerVectorInsertAt(_map.m_keys, counter, _key);
				IntegerVectorInsertAt(_map.m_values, counter, _value);
			}
		}
		else
		{
			IntegerVectorInsertAt(_map.m_keys, position, _key);
			IntegerVectorInsertAt(_map.m_values, position, _value);
		}
	}
}

void mapDeleteKey(Map &_map, int _key)
{
	while (true)
	{
		int keyPosition = findKeyPositionFront(_map, _key);
		if (keyPosition == -1)
			break;
		IntegerVectorDeleteAt(_map.m_keys, keyPosition);
		IntegerVectorDeleteAt(_map.m_values, keyPosition);
	}
}

bool mapIsEmpty(const Map &_map)
{
	return IntegerVectorIsEmpty(_map.m_keys);
}

bool mapHasKey(const Map &_map, int _key)
{
	return findKeyPosition(_map, _key) != -1;
}

int mapFind(const Map &_map, int _key)
{
	int frontPosition = findKeyPositionFront(_map, _key);
	return _map.m_values.m_pData[frontPosition];
}

int valuesCountOfKey(const Map &_map, int _key)
{
	int counter = 0; 
	for (int i = 1; i <= _map.m_keys.m_nUsed; i++)
	{
		if (_map.m_keys.m_pData[i - 1] == _key)
		{
			counter++;
			if (_map.m_keys.m_pData[i] != _key)
				break;
		}
	}
	return counter;
}

void MapPrint(const Map &_map, std::ostream &_stream)
{

	IntegerVectorPrint(_map.m_keys, _stream);
	_stream << std::endl;
	IntegerVectorPrint(_map.m_values, _stream);
}