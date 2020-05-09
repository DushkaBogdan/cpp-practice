#include "bit_set.hpp"
#include <iostream>

struct BitSet
{
	__int64 m_set;
};

BitSet *BitSetCreate()
{
	BitSet *pSet = new BitSet;
	pSet->m_set = 0;
	return pSet;
}
void BitSetDestroy(BitSet *_pSet)
{
	delete _pSet;
}
void BitSetClear(BitSet &_set)
{
	_set.m_set = 0;
}
bool BitSetHasKey(const BitSet &_set, __int64 _key)
{
	return (_set.m_set & _key);
}
void BitSetInsertKey(BitSet &_set, __int64 _key)
{
	_set.m_set |= _key;
}
void BitSetRemoveKey(BitSet &_set, __int64 _key)
{
	_set.m_set &= ~(_key);
}
void BitSetUnite(
	const BitSet &_set1,
	const BitSet &_set2,
	BitSet &_targetSet)
{
	BitSetClear(_targetSet);

	_targetSet.m_set = _set1.m_set | _set2.m_set;
}

void BitSetDifferense(
	const BitSet &_set1,
	const BitSet &_set2,
	BitSet &_targetSet)
{
	_targetSet.m_set = _set1.m_set & ~(_set2.m_set);
}

void BitSetIntersection(
	const BitSet &_set1,
	const BitSet &_set2,
	BitSet &_targetSet)
{
	_targetSet.m_set = _set1.m_set & _set2.m_set;
}

void BitSetDisplay(const BitSet &_set)
{
	_int64 value = _set.m_set;
	_int64 dispMask = 1;
	dispMask <<= 63;

	for (int i = 1; i <= 64; i++)
	{
		std::cout << (value & dispMask ? "1" : "0");
		if (i % 8 == 0)
			std::cout << " ";

		value <<= 1;
	}
}