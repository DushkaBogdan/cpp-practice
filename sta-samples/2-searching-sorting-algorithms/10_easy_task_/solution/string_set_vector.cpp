#include "string_set.hpp"
#include "string_vector.hpp"

struct StringSet
{
	StringVector m_Strings;
};

StringSet *StringSetCreate()
{
	StringSet *pSet = new StringSet;
	StringVectorInit(pSet->m_Strings);

	return pSet;
}
void StringSetDestroy(StringSet *_pSet)
{
	StringVectorDestroy(_pSet->m_Strings);
	delete _pSet;
}
void StringSetClear(StringSet &_set)
{
	StringVectorClear(_set.m_Strings);
}
bool StringSetIsEmpty(const StringSet &_set)
{
	return _set.m_Strings.m_nUsed == 0;
}



int StringSetKeyPosition (const StringSet &_set, const char *_key)
{
	int minIndex = 0, maxIndex = _set.m_Strings.m_nUsed, midIndex = 0;

	while (minIndex < maxIndex)
	{
		midIndex = (maxIndex + minIndex) >> 1;

		int result = strcmp(_key, _set.m_Strings.m_pString[midIndex]);

		if (result == 0)
		{
			return midIndex;
		}

		else if (result < 0)
		{
			maxIndex = midIndex;
		}
		else
		{
			minIndex = midIndex + 1;
		}
			
	}
	return -1;
}

bool StringSetHasKey(const StringSet &_set, const char *_key)
{
	return (StringSetKeyPosition(_set, _key) != -1);
}

void StringSetInsertKey(StringSet &_set, const char *_key)
{
	StringVectorPushBack(_set.m_Strings, _key);
}

void StringSetInsertKeyDuplicated(StringSet &_set, const char *_key)
{
	if ( StringSetIsEmpty(_set) )
		StringVectorPushBack(_set.m_Strings, _key);
	else
	{
		if (strcmp(_set.m_Strings.m_pString[0], _key) >= 0)
		{
			StringVectorPushFront(_set.m_Strings, _key);
		}
		else if (strcmp(_set.m_Strings.m_pString[(_set.m_Strings.m_nUsed - 1)], _key) <= 0)
			StringVectorPushBack(_set.m_Strings, _key);
		else
		{
			for (int i = 0; i < _set.m_Strings.m_nUsed; i++)
			{
				if (strcmp(_set.m_Strings.m_pString[i], _key) >= 0)
				{
					StringVectorInsertAt(_set.m_Strings, i, _key);
					break;
				}
			}
		}
		
	}
}

void StringSetPrint(const StringSet &_set, std::ostream &_stream, char _sep)
{
	StringVectorPrint(_set.m_Strings, _stream);
}

int StringSetKeysCount(StringSet &_set, const char *_key)
{
	int midPos = StringSetKeyPosition(_set, _key);
	if (midPos == -1)
		return 0;
	int pos = midPos-1;

	int count = 1;

	
	while (pos >= 0)
	{
		if (strcmp(_set.m_Strings.m_pString[pos], _key) == 0)
		{
			count++;
			pos--;
		}
		else
			break;
	}

	pos = midPos + 1;

	while (pos < _set.m_Strings.m_nUsed)
	{
		if (strcmp(_set.m_Strings.m_pString[pos], _key) == 0)
		{
			count++;
			pos++;
		}
		else
			break;
	}
	return count;
}