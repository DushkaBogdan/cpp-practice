#define _CRT_SECURE_NO_WARNINGS
#include "string_vector.hpp"
#include <cassert>

char *StringCopy(const char *_str)
{
	int len = strlen(_str);
	char *charBuff = new char[len+1];
	strcpy(charBuff, _str);

	return charBuff;
}

void StringVectorInit(StringVector &_v, int _nAllocated)
{
	_v.m_nAllocated = _nAllocated;
	_v.m_pString = new char*[_nAllocated];
	_v.m_nUsed = 0;
}

void StringVectorDestroy(StringVector &_v)
{
	StringVectorClear(_v);
	delete[]_v.m_pString;
}

void StringVectorClear(StringVector &_v)
{
	for (int i = 0; i < _v.m_nUsed; i++)
		delete[] _v.m_pString[i];
	_v.m_nUsed = 0;
}

bool StringVectorIsEmpty(const StringVector &_v)
{
	return _v.m_nUsed == 0;
}

void StringVectorGrow(StringVector &_v)
{
	int nSize = _v.m_nAllocated * 2;
	char **pArr = new char*[nSize];
	memcpy(pArr, _v.m_pString, (sizeof(char*)*_v.m_nUsed) );

	delete[]_v.m_pString;
	_v.m_pString = pArr;
	_v.m_nAllocated = nSize;
}

void StringVectorPushBack(StringVector &_v,const char *_string)
{
	if (_v.m_nUsed == _v.m_nAllocated)
		StringVectorGrow(_v);
	_v.m_pString[_v.m_nUsed++] = StringCopy(_string); /*==========================================================*/
}

void StringVectorPushFront(StringVector &_v,const char *_string)
{
	if (_v.m_nUsed == _v.m_nAllocated)
		StringVectorGrow(_v);

	for (int i = _v.m_nUsed; i > 0; i--)
		_v.m_pString[i] = _v.m_pString[i - 1];
	_v.m_pString[0] = StringCopy(_string);
	++_v.m_nUsed;
}

void StringVectorInsertAt(StringVector &_v, int _position,const char *_string)
{
	assert(!StringVectorIsEmpty(_v));
	assert(_position >= 0 && _position < _v.m_nUsed);

	for (int i = _v.m_nUsed; i > _position; i--)
		_v.m_pString[i] = _v.m_pString[i - 1];
	_v.m_pString[_position] = StringCopy(_string);
	++_v.m_nUsed;
}

void StringVectorPopBack(StringVector &_v)
{
	assert(!StringVectorIsEmpty(_v));

	--_v.m_nUsed;
}

void StringVectorPopFront(StringVector &_v)
{
	assert(!StringVectorIsEmpty(_v));

	for (int i = 1; i < _v.m_nUsed; i++)
		_v.m_pString[i - 1] = _v.m_pString[i];
	--_v.m_nUsed;
}

void StringVectorDeleteAt(StringVector &_v, int _position)
{
	assert(!StringVectorIsEmpty(_v));
	assert(_position >= 0 && _position < _v.m_nUsed);

	for (int i = _position + 1; i < _v.m_nUsed; i++)
		_v.m_pString[i - 1] = _v.m_pString[i];
	--_v.m_nUsed;
}

void StringVectorRead(StringVector &_v, std::istream &_stream)
{
	while (true)
	{
		char charBuff[1024];
		_stream >> charBuff;

		if (_stream)
			StringVectorPushBack(_v, charBuff);
		else
			break;
	}
}

void StringVectorPrint(const StringVector &_v, std::ostream &_stream, char _sep)
{
	if (StringVectorIsEmpty(_v))
		std::cout << "Vector Is Empty!";
	else
	{
		for (int i = 0; i < _v.m_nUsed; i++)
			_stream << _v.m_pString[i] << _sep;
	}
}