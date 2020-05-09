#ifndef _MULTI_MAP_HPP_
#define _MULTI_MAP_HPP_

#include <iostream>

struct Map;

Map* mapCreate();

void mapDestroy(Map *_pMap);

void mapClear(Map &_map);

void mapInsertKey(Map &_map, int _key, int _value);

void mapDeleteKey(Map &_map, int _key);

bool mapIsEmpty(const Map &_map);

bool mapHasKey(const Map &_map, int _key);

int mapFind(const Map &_map, int _key);

int valuesCountOfKey(const Map &_map, int _key);

void MapPrint(const Map &_map, std::ostream &_stream);

#endif //_MULTI_MAP_HPP_


