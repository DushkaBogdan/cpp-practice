#ifndef _MAP_STRING_DOUBLR_HPP_
#define _MAP_STRING_DOUBLR_HPP_
struct Map;

Map* MapCreate();
void MapDestroy(Map *_pMap);
void MapClear(Map &_map);
void MapInsertKey(Map &_map, const char *_str, double _value);
void MapPrint(const Map &_map);
double MapFind(const Map &_map, const char *_str);

#endif //_MAP_STRING_DOUBLR_HPP_

