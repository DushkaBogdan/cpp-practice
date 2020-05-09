#include "st_tree.hpp"
#include <cassert>
#include <iostream>

char* strCpy(const char* _str)
{
	int size = strlen(_str) +1;
	char* Buff = new char[size];
	_memccpy(Buff, _str, ' ', size);

	return Buff;
}

struct St_Tree
{
	int m_nSize;

	char** m_pStrings;
	int* m_pParentindexes;
};

St_Tree* treeCreate(int _size)
{
	St_Tree* pTree = new St_Tree;
	pTree->m_nSize = _size;

	pTree->m_pParentindexes = new int[_size];
	memset(pTree->m_pParentindexes, 0, sizeof(int)*_size);
	pTree->m_pParentindexes[0] = -1;

	pTree->m_pStrings = new char*[_size];
	memset(pTree->m_pStrings, 0, _size*sizeof(char*));

	return pTree;
}

void treeClear(St_Tree &_tree)
{
	for (int i = 0; i < _tree.m_nSize; i++)
		delete _tree.m_pStrings[i];

	delete _tree.m_pStrings;

	delete _tree.m_pParentindexes;
}

void treeDestroy(St_Tree *_tree)
{
	treeClear(*_tree);

	delete _tree;
}

/*==============================================================================*/
typedef char* NodeLabel;

NodeLabel getLabel(const St_Tree &_tree, int _index)
{
	assert(_index < _tree.m_nSize);
	return _tree.m_pStrings[_index];
}

void setNodeLadel(St_Tree &_tree, int _index, char* _ladel)
{
	assert(_index < _tree.m_nSize);

	_tree.m_pStrings[_index] = strCpy(_ladel);

}

int getRootIndex(const St_Tree &)
{
	return 0;
}

int getParentIndex(const St_Tree &_tree, int _index)
{
	assert(_index < _tree.m_nSize);
	return _tree.m_pParentindexes[_index];
}

void setParentIndex(St_Tree &_tree, int _index, int _parentIndex)
{
	assert(_parentIndex < _index);
	assert(_index < _tree.m_nSize);
	_tree.m_pParentindexes[_index] = _parentIndex;
}

int getLeftMostChildIndex(const St_Tree &_tree, int _parentIndex)
{
	assert(_parentIndex < _tree.m_nSize);

	for (int i = _parentIndex+1; i < _tree.m_nSize ; i++)
	{
		if (_parentIndex == _tree.m_pParentindexes[i])
			return i;
	}
	return -1;
}

int getRightSiblingIndex(const St_Tree &_tree, int _index)
{
	assert(_index < _tree.m_nSize);

	int parentIndex = _tree.m_pParentindexes[_index];

	for (int i = _index+1; i < _tree.m_nSize; i++)
	{
		if (_tree.m_pParentindexes[i] == parentIndex)
			return i;
	}
	return -1;
}

/*=============================================================================*/

typedef void (*NodeVisitFunction)(const St_Tree &_tree, int _index);

void TreeDirectWalk(const St_Tree &_tree, int _index, NodeVisitFunction _f)
{
	_f(_tree, _index);

	int child = getLeftMostChildIndex(_tree, _index);

	while (child != -1)
	{
		TreeDirectWalk(_tree, child, _f);
		child = getRightSiblingIndex(_tree, child);
	}
	

}
void TreeReverseWalk(const St_Tree &_tree, int _index, NodeVisitFunction _f)
{
	int nodeIndex = getLeftMostChildIndex(_tree, _index);

	while (nodeIndex != -1)
	{
		TreeReverseWalk(_tree, nodeIndex, _f);
		nodeIndex = getRightSiblingIndex(_tree, nodeIndex);
	}
	_f(_tree, _index);
}

void TreeSymmetricWalk(const St_Tree &_tree, int _index, NodeVisitFunction _f)
{
	int childIndex = getLeftMostChildIndex(_tree, _index);

	if (childIndex != -1)
		TreeSymmetricWalk(_tree, childIndex, _f);

	_f(_tree, _index);

	if (childIndex == -1)
		return;

	while(true)
	{
		childIndex = getRightSiblingIndex(_tree, childIndex);
		if (childIndex == -1)
			break;
		TreeSymmetricWalk(_tree, childIndex, _f);
	}
}

void TreeDirectWalk(const St_Tree &_tree, NodeVisitFunction _f)
{
	TreeDirectWalk(_tree, getRootIndex(_tree), _f);
}

void TreeReverseWalk(const St_Tree &_tree, NodeVisitFunction _f)
{
	TreeReverseWalk(_tree, getRootIndex(_tree), _f);
}

void TreeSymmetricWalk(const St_Tree &_tree, NodeVisitFunction _f)
{
	TreeSymmetricWalk(_tree, getRootIndex(_tree), _f);
}