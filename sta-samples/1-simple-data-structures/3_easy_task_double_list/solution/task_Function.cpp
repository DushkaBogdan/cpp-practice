#include "integer_vector.hpp"
#include <cassert>

void IntegerVectorDeleteBlockAt(IntegerVector & _vector, int _position, int _blockSize)
{
	assert(!IntegerVectorIsEmpty(_vector));
	assert(_position >= 0 && _position <_vector.m_nUsed);
	assert(_blockSize > 0 && _blockSize <= _vector.m_nUsed);

	for (int i = _position + 1; i < _vector.m_nUsed; i++)
		_vector.m_pData[i - 1] = _vector.m_pData[i + _blockSize - 1];

	_vector.m_nUsed = _vector.m_nUsed - _blockSize;
}