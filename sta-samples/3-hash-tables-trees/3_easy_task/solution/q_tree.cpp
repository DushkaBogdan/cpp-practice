#include "q_tree.hpp"
#include <iostream>
#include <cassert>

struct Q_tree
{
	int m_nNodes;
	char** m_pLadels;

	struct Node
	{
		int m_Index;
		Node* m_pNext;
	};
	Node** m_pHeader;

};

Q_tree* QTreeCreate(int _size)
{
	assert(_size > 0);

	Q_tree *pTree = new Q_tree;
	pTree->m_nNodes = _size;

	pTree->m_pLadels = new char*[_size];
	memset(pTree->m_pLadels, 0, sizeof(char*)*_size);

	pTree->m_pHeader = new Q_tree::Node*[_size];
	memset(pTree->m_pHeader, 0, sizeof(Q_tree::Node*)*_size);

	return pTree;
}

void QTreeDestroy(Q_tree *_pTree)
{
	for (int i = 0; i < _pTree->m_nNodes; i++)
	{
		Q_tree::Node *pCurrent = _pTree->m_pHeader[i];
		while (pCurrent)
		{
			Q_tree::Node *pTemp = pCurrent->m_pNext;
			delete pCurrent;
			pCurrent = pTemp;
		}
	}

	delete[] _pTree->m_pLadels;
	delete[] _pTree->m_pHeader;

	delete _pTree;
}

TreeNodeLabel QTreeGetLabel(const Q_tree &_t, int _index)
{
	assert(_index >= 0 && _index < _t.m_nNodes);
	return _t.m_pLadels[_index];
}

void QTreeSetLabel(Q_tree &_t, int _index, TreeNodeLabel _l)
{
	assert(_index >= 0 && _index < _t.m_nNodes);
	_t.m_pLadels[_index] = _l;
}

void QTreeSetParentIndex(Q_tree &_t, int _parentIndex, int _childIndex)
{
	assert(_parentIndex < _childIndex);
	assert(_childIndex < _t.m_nNodes);

	Q_tree::Node* newNode = new Q_tree::Node;
	newNode->m_Index = _childIndex;
	newNode->m_pNext = nullptr;

	Q_tree::Node *pCurrent = _t.m_pHeader[_parentIndex];

	if (!pCurrent)
		_t.m_pHeader[_parentIndex] = newNode;
	else
	{
		while (pCurrent->m_pNext)
			pCurrent = pCurrent->m_pNext;

		pCurrent->m_pNext = newNode;
	}
}

int QTreeGetRoot(const Q_tree &_t)
{
	return 0;
}

int QTreeGetLeftMostChild(const Q_tree &_t, int _parentIndex)
{
	assert(_parentIndex < _t.m_nNodes);

	Q_tree::Node *pCurrent = _t.m_pHeader[_parentIndex];

	return pCurrent ? pCurrent->m_Index : -1;
}

int QTreeGetRightSibling(const Q_tree &_t, int _index)
{
	assert(_index < _t.m_nNodes);

	for (int i = 0; i < _index; i++)
	{
		Q_tree::Node *pCurrent = _t.m_pHeader[i];

		while (pCurrent)
		{
			if (pCurrent->m_Index == _index)
			{
				Q_tree::Node *pNext = pCurrent->m_pNext;
				return pNext ? pNext->m_Index : -1;
			}
			pCurrent = pCurrent->m_pNext;
		}
	}
	
	return - 1;
}
int QTreeGetParent(const Q_tree &_t, int _index)
{
	assert(_index < _t.m_nNodes);

	for (int i = 0; i < _index; i++)
	{
		Q_tree::Node *pCurrent = _t.m_pHeader[i];

		while (pCurrent)
		{
			if (pCurrent->m_Index == _index)
				return i;
			pCurrent = pCurrent->m_pNext;
		}
	}
	return -1;
}

void QTDirectWalk(const Q_tree &_t, int _index, treeNodeVisitFunction _f)
{
		
	_f(_t, _index);
	std::cout << std::endl;

	int childIndex = QTreeGetLeftMostChild(_t, _index);

	while (childIndex != -1)
	{
		QTDirectWalk(_t, childIndex, _f);
		childIndex = QTreeGetRightSibling(_t, childIndex);
	}
}

void QTReverseWalk(const Q_tree &_t, int _index, treeNodeVisitFunction _f)
{
	int childIndex = QTreeGetLeftMostChild(_t, _index);

	while (childIndex != -1)
	{
		QTReverseWalk(_t, childIndex, _f);
		childIndex = QTreeGetRightSibling(_t, childIndex);
	}

	_f(_t, _index);
}
//
void QTSymmetricalWalk(const Q_tree &_t, int _index, treeNodeVisitFunction _f)
{
	int childIndex = QTreeGetLeftMostChild(_t, _index);

	if (childIndex != -1)
		QTSymmetricalWalk(_t, childIndex, _f);

	(*_f)(_t, _index);

	if (childIndex == -1)
		return;

	while (true)
	{
		childIndex = QTreeGetRightSibling(_t, childIndex);

		if (childIndex == -1)
			break;

		QTSymmetricalWalk(_t, childIndex, _f);
	}
}


void QTDirectWalk(const Q_tree &_t, treeNodeVisitFunction _f)
{
	QTDirectWalk(_t, 0, _f);
}

void QTReverseWalk(const Q_tree &_t, treeNodeVisitFunction _f)
{
	QTReverseWalk(_t, 0, _f);
}
//
void QTSymmetricalWalk(const Q_tree &_t, treeNodeVisitFunction _f)
{
	QTSymmetricalWalk(_t, 0, _f);
}