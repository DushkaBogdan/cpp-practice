#ifndef _BIT_SET_HPP_
#define _BIT_SET_HPP_

struct BitSet;

BitSet *BitSetCreate();

void BitSetDestroy(BitSet *_pSet);

void BitSetClear(BitSet &_set);

bool BitSetHasKey(const BitSet &_set, __int64 _key);

void BitSetInsertKey(BitSet &_set, __int64 _key);

void BitSetRemoveKey(BitSet &_set, __int64 _key);

void BitSetUnite(
	const BitSet &_set1,
	const BitSet &_set2,
	BitSet &_targetSet);

void BitSetDifferense(
	const BitSet &_set1,
	const BitSet &_set2,
	BitSet &_targetSet);

void BitSetIntersection(
	const BitSet &_set1,
	const BitSet &_set2,
	BitSet &_targetSet);

void BitSetDisplay(const BitSet &_set);

#endif _BIT_SET_HPP_