#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <iostream>

struct Map;

Map* MapCreate();

void MapDestroy(Map *_pMap);

void MapClear(Map &_map);

bool MapIsEmpty(const Map &_map);

bool MapHasKey(const Map &_map, const int _key);

void MapInsertKey(Map &_map, int _key, int _value);

void MapPrint(const Map &_map, std::ostream &_stream);

#endif _MAP_HPP_


