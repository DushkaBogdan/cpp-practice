#include "map_string_double.hpp"
#include "list_double.hpp"

struct Map
{
	IntegerList m_list;
};
Map* MapCreate()
{
	Map *map = new Map;
	IntegerListInit(map->m_list);
	return map;
}
void MapClear(Map &_map)
{
	IntegerListClear(_map.m_list);
}
void MapDestroy(Map *_pMap)
{
	IntegerListDestroy(_pMap->m_list);
	delete _pMap;
}

void MapInsertKey(Map &_map, const char *_str, double _value)
{
	if ((_map.m_list.m_pFirst == nullptr) || (strcmp(_map.m_list.m_pFirst->m_date, _str) > 0))
	{
		IntegerListPushFront(_map.m_list, _value, _str);
		return;
	}
	if (strcmp(_map.m_list.m_pLast->m_date, _str) < 0)
	{
		IntegerListPushBack(_map.m_list, _value, _str);
		return;
	}

	IntegerList::Node *pPrev = _map.m_list.m_pFirst;
	IntegerList::Node *pCurrent = pPrev->m_pNext;

	while (pCurrent)
	{
		if (strcmp(pCurrent->m_date, _str) > 0 && strcmp(pPrev->m_date, _str) < 0)
		{
			IntegerListInsertAfter(_map.m_list, pPrev, _value, _str);
			return;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->m_pNext;
	}

}

void MapPrint(const Map &_map)
{
	IntegerListPrint(_map.m_list, std::cout);
}

double MapFind(const Map &_map, const char *_str)
{
	IntegerList::Node *pCurrent = _map.m_list.m_pFirst;
	IntegerList::Node *pPrev = pCurrent;

	while (pCurrent)
	{
		if ((strcmp(_map.m_list.m_pFirst->m_date, _str) > 0) ||
			(strcmp(_map.m_list.m_pLast->m_date, _str) < 0))
		{
			std::cout << "No such Values!";
			return -1;
		}
		else if (strcmp(pCurrent->m_date, _str) == 0)
		{
			return pCurrent->m_value;
		}
		else if ( (strcmp(pCurrent->m_date, _str) > 0) &&
			      (strcmp(pPrev->m_date, _str) < 0) )
		{
			double temp = (pPrev->m_value + pCurrent->m_value);
			return (temp/ 2);
		}
		
		pPrev = pCurrent;
		pCurrent = pCurrent->m_pNext;
	}
}