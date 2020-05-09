#ifndef _STRING_LIST_HPP_
#define _STRING_LIST_HPP_
#include <iostream>

struct StringList
{
	struct Node
	{
		char *m_string;
		Node *m_pNext;
	};
	Node *m_pFirst, *m_pLast;
};

void StringListInit(StringList &_list);
void StringListDestroy(StringList &_list);
void StringListClear(StringList &_list);
bool StringListIsEmpty(const StringList &_list);
void StringListPushBack(StringList &_list, const char *_string);
void StringListPushPop(StringList &_list, const char *_string);
void StringListInsertAfter(StringList &_list, StringList::Node *_pPrev, const char *_string);
void StringListInsertBefore(StringList &_list, StringList::Node *_pNext, const char *_string);
void StringListPushSorted(StringList &_list, const char *_string);
void StringListPushSortedDuplicated(StringList &_list, const char *_string);
void StringListPopBack(StringList &_list);
void StringListPopFront(StringList &_list);
void StringListPopAfter(StringList &_list, StringList::Node *_pPrev);
void StringListPopBefore(StringList &_list, StringList::Node *_pNext);
void StringListPrint(const StringList &_list, std::ostream &_stream, char _sep = ' ');

#endif //_STRING_LIST_HPP_