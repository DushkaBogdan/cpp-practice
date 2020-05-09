#ifndef _INTEGER_MAP_HPP_
#define _INTEGER_MAP_HPP_

struct Map;

Map *MapCreate();
void MapDestroy(Map *_pMap);
void MapClear(Map &_map);
bool MapHasKey(const Map &_map, int _key);
int MapFind(const Map &_map, int _key);
void MapInsertKey(Map &_map, int _key, int _value);

#endif // _INTEGER_MAP_HPP

