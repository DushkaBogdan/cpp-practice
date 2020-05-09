#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <iostream>

struct Map;

Map *MapCreate();

void MapDestroy(Map *_pMap);

void MapClear(Map &_map);

bool MapIsEmpty(const Map &_map);

bool MapHasKey(const Map &_map, const char *_key);

void MapInsertKey(Map &_map, const char *_key, const int _value);

void MapDeleteKey(Map &_map, char *_key);

int MapFind(const Map &_map, const char *_key);

void MapPrint(const Map &_map, std::ostream &_stream);

#endif //_MAP_HPP_

