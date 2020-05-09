#ifndef _MAP_HPP_
#include <iostream>

struct Map;

Map *MapCreate();
void MapDestroy(Map *_pMap);
void MapClear(Map &_map);
bool MapHasKey(const Map &_map, int _key);
char *MapFind(const Map &_map, int _key);
void MapInsertKey(Map &_map, int _key, char *_string);

void MapPrint(const Map &_map, std::ostream &_stream);

#define _MAP_HPP_
#endif _MAP_HPP_

