#include "tree.hpp"
#include <iostream>
#include <cassert>
#include <iomanip>

char* strCP(const char*_s)
{
	int size = strlen(_s) + 1;
	char* charBuff = new char[size];
	memcpy(charBuff, _s, sizeof(char*)*size);
	return charBuff;
}



TreeNode* NodeCreate(char* _label)
{
	TreeNode* pNode = new TreeNode;
	pNode->m_pMostLeftChild = pNode->m_pParent = pNode->m_pRightSibling = nullptr;
	pNode->m_sLadel = _label;
	return pNode;
}

D_tree* create(char *_label)
{
	D_tree* pTree = new D_tree;

	pTree->m_pRoot = NodeCreate(_label);

	return pTree;
}

void DTreeDestroyNode(TreeNode *_pNode)
{
	TreeNode *pCurrent = _pNode->m_pMostLeftChild;

	while (pCurrent)
	{
		TreeNode *pNext = pCurrent->m_pRightSibling;
		DTreeDestroyNode(pCurrent);
		pCurrent = pNext;
	}
	delete _pNode;
}

void DTreeDestroy(D_tree *_pTree)
{
	DTreeDestroyNode(_pTree->m_pRoot);
	delete _pTree;
}


TreeNode* DTreeRoot(D_tree &_t)
{
	assert(_t.m_pRoot);

	return _t.m_pRoot;
}



TreeNode* DTAddChild(char* _label, TreeNode *_parent)
{
	assert(_parent != nullptr);

	TreeNode *pNewNode = NodeCreate(_label);
	pNewNode->m_pParent = _parent;


	if (!_parent->m_pMostLeftChild)
		_parent->m_pMostLeftChild = pNewNode;
	else
	{
		TreeNode *pNode = _parent->m_pMostLeftChild;

		while (pNode->m_pRightSibling)
		{
			pNode = pNode->m_pRightSibling;
		}
		pNode->m_pRightSibling = pNewNode;
	}

	return pNewNode;
}

TreeNodeLabel DTreeGetNodeLabel(const TreeNode *_pNode)
{
	return _pNode->m_sLadel;
}

TreeNode* DTreeGetParent(const TreeNode *_pNode)
{
	return _pNode->m_pParent;
}

TreeNode* DTreeGetLeftMostChild(const TreeNode *_pNode)
{
	return _pNode->m_pMostLeftChild;
}

TreeNode* DTreeGetRightSibling(const TreeNode *_pNode)
{
	return _pNode->m_pRightSibling;
}



void DTDirectWalk(const TreeNode *_pNode, treeNodeVisitFunction _f, int _INDEX)
{
	for (int i = 0; i < _INDEX; i++)
		std::cout << " ";

	(*_f)(*_pNode);

	

	TreeNode *pCurrent = _pNode->m_pMostLeftChild;

	while (true)
	{
		if (!pCurrent)
			break;

		DTDirectWalk(pCurrent, _f, _INDEX+1);
		pCurrent = pCurrent->m_pRightSibling;
	}
}

void DTReverseWalk(const TreeNode *_pNode, treeNodeVisitFunction _f)
{
	TreeNode *pChild = _pNode->m_pMostLeftChild;

	while (pChild)
	{
		DTReverseWalk(pChild, _f);
		pChild = pChild->m_pRightSibling;
	}
	(*_f)(*_pNode);
}

void DTSymmetricalWalk(const TreeNode *_pNode, treeNodeVisitFunction _f)
{
	TreeNode *pCurrent = _pNode->m_pMostLeftChild;

	if (pCurrent)
		DTSymmetricalWalk(pCurrent, _f);

	(*_f)(*_pNode);

	if (!pCurrent)
		return;

	while (true)
	{
		pCurrent = pCurrent->m_pRightSibling;
		if (!pCurrent)
			break;
		DTSymmetricalWalk(pCurrent, _f);
	}


}

void DTDirectWalk(const D_tree &_t, treeNodeVisitFunction _f)
{
	DTDirectWalk(_t.m_pRoot, _f, 0);
}
void DTReverseWalk(const D_tree &_t, treeNodeVisitFunction _f)
{
	DTReverseWalk(_t.m_pRoot, _f);
}
void DTSymmetricalWalk(const D_tree &_t, treeNodeVisitFunction _f)
{
	DTSymmetricalWalk(_t.m_pRoot, _f);
}