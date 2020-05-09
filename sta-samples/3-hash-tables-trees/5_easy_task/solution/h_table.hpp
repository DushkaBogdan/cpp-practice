#ifndef _H_TABLE_HPP_
#define _H_TABLE_HPP_

struct HTable;

HTable* HTableCreate(int _initialSize);

void HTableDestroy(HTable *_pHt);

void HTableClear(HTable &_hT);

int HTableNumElements(const HTable &_ht);

int HTableGetSize(const HTable &_ht);

void HTableInsert(HTable &_ht, char *_key);

bool HTableHasKey(const HTable &_ht, char *_key);

void HTableRemove(HTable &_ht, char *_key);

#endif //_H_TABLE_HPP_



