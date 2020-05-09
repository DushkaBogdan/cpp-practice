#include "h_table.hpp"
#include <iostream>
#include <cassert>

struct HTable
{
	struct Element
	{
		char *m_pString;
		enum {NOT_OCCUPIED, OCCUPIED, DELETED} m_status;
	};

	int m_nSize;
	int m_nUsed;
	Element* m_pData;
};

HTable* HTableCreate(int _initialSize)
{
	HTable *pTable = new HTable;

	pTable->m_nSize = _initialSize;
	pTable->m_nUsed = 0;

	pTable->m_pData = new HTable::Element[_initialSize];
	
	memset(pTable->m_pData, 0, sizeof(HTable::Element*)*_initialSize);

	return pTable;
}

void HTableDestroy(HTable *_pHt)
{
	HTableClear(*_pHt);

	delete[] _pHt->m_pData;
	delete _pHt;
}

void HTableClear(HTable &_hT)
{
	_hT.m_nUsed = 0;
	for (int i = 0; i < _hT.m_nSize; i++)
	{
		if (_hT.m_pData[i].m_status == HTable::Element::OCCUPIED)
			delete _hT.m_pData[i].m_pString;
		_hT.m_pData[i].m_status = HTable::Element::NOT_OCCUPIED;
	}
}
int HTableNumElements(const HTable &_ht)
{
	return _ht.m_nUsed;
}

unsigned int HashCode(const char *_str)
{
	unsigned int hashcode = 0;

	for (; *_str; *_str++)
	{
		char c = *_str;
		hashcode = (hashcode << 5) + c;
	}
	return hashcode;
}

char* strCP(const char *_str)
{
	int size = strlen(_str) +1;
	char *charBuff = new char[size];
	memcpy(charBuff, _str, size);
	return charBuff;
}

bool HTableTryToInsert(HTable &_ht, int _bucNum, char *_key)
{
	if (_ht.m_pData[_bucNum].m_status != HTable::Element::OCCUPIED)
	{
		_ht.m_pData[_bucNum].m_pString = strCP(_key);
		_ht.m_pData[_bucNum].m_status = HTable::Element::OCCUPIED;
		_ht.m_nUsed++;
		return true;
	}
	else if (strcmp(_ht.m_pData[_bucNum].m_pString, _key) == 0)
		return true;
	else
		return false;
}

void HTableDoubleSize(HTable &_ht)
{
	int oldSize = _ht.m_nSize;
	int oldUsed = _ht.m_nUsed;

	_ht.m_nSize <<= 1;

	HTable::Element *oldData = _ht.m_pData;

	_ht.m_pData = new HTable::Element[_ht.m_nSize];

	for (int i = 0; i < _ht.m_nSize; i++)
		_ht.m_pData[i].m_status = HTable::Element::NOT_OCCUPIED;

	for (int i = 0; i < oldSize; i++)
		if (oldData[i].m_status == HTable::Element::OCCUPIED)
			HTableInsert(_ht, oldData[i].m_pString);

	_ht.m_nUsed = oldUsed;

	for (int i = 0; i < oldSize; i++)
		if (oldData[i].m_status == HTable::Element::OCCUPIED)
			delete oldData[i].m_pString;

	delete[] oldData;
}

void HTableInsert(HTable &_ht, char *_key)
{
	if ((_ht.m_nUsed << 1) >= _ht.m_nSize)
		HTableDoubleSize(_ht);

	unsigned int hashCode = HashCode(_key);
	int bucNum = hashCode % _ht.m_nSize;

	for (int i = bucNum; i < _ht.m_nSize; i++)
		if (HTableTryToInsert(_ht, i, _key))
			return;

	for (int i = 0; i < bucNum; i++)
		if (HTableTryToInsert(_ht, i, _key))
			return;
}

bool HTableHasKey(const HTable &_ht, char *_key)
{
	unsigned int hashCode = HashCode(_key);
	int bucNum = hashCode % _ht.m_nSize;

	for (int i = bucNum; i < _ht.m_nSize; i++)
	{
		if (_ht.m_pData[i].m_status == HTable::Element::NOT_OCCUPIED)
			break;
		else if (_ht.m_pData[i].m_status == HTable::Element::OCCUPIED &&
				 strcmp(_ht.m_pData[i].m_pString, _key) == 0)
			return true;
	}

	for (int i = 0; i < bucNum; i++)
	{
		if (_ht.m_pData[i].m_status == HTable::Element::NOT_OCCUPIED)
			break;
		else if (_ht.m_pData[i].m_status == HTable::Element::OCCUPIED &&
			strcmp(_ht.m_pData[i].m_pString, _key) == 0)
			return true;
	}

	return false;
}

void HTableRemove(HTable &_ht, char *_key)
{
	unsigned int hashCode = HashCode(_key);
	int bucNum = hashCode % _ht.m_nSize;

	for (int i = bucNum; i < _ht.m_nSize; i++)
	{
		if (_ht.m_pData[i].m_status == HTable::Element::OCCUPIED &&
			strcmp(_ht.m_pData[i].m_pString, _key) == 0)
		{
			_ht.m_pData[i].m_status = HTable::Element::DELETED;
			--_ht.m_nUsed;
			delete _ht.m_pData[i].m_pString;
			return;
		}
	}

	for (int i = 0; i < bucNum; i++)
	{
		if (_ht.m_pData[i].m_status == HTable::Element::OCCUPIED &&
			strcmp(_ht.m_pData[i].m_pString, _key) == 0)
		{
			_ht.m_pData[i].m_status = HTable::Element::DELETED;
			--_ht.m_nUsed;
			delete _ht.m_pData[i].m_pString;
			return;
		}
	}

	assert(!"key Not Found");
}

int HTableGetSize(const HTable &_ht)
{
	return _ht.m_nSize;
}