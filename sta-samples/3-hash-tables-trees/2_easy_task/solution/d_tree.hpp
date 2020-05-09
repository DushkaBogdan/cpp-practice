#ifndef _D_TREE_HPP_
#define _D_TREE_HPP_

struct TreeNode
{
	TreeNode* m_pParent;
	TreeNode* m_pMostLeftChild;
	TreeNode* m_pRightSibling;
	char* m_sLadel;
};

struct D_tree
{
	TreeNode *m_pRoot;
};

D_tree* create(char *_label);

void DTreeDestroy(D_tree *_pTree);


TreeNode* DTreeRoot(D_tree &_t);

TreeNode* DTAddChild(char* _label, TreeNode *_parent);

typedef char* TreeNodeLabel;

TreeNodeLabel DTreeGetNodeLabel(const D_tree &_t, TreeNode *_pNode);

TreeNode* DTreeGetParent(const D_tree &_t, TreeNode *_pNode);

TreeNode* DTreeGetLeftMostChild(const D_tree &_t, TreeNode *_pNode);

TreeNode* DTreeGetRightSibling(const D_tree &_t, TreeNode *_pNode);

typedef void (*treeNodeVisitFunction)(const TreeNode &_pNode);

void DTDirectWalk(const D_tree &_t, treeNodeVisitFunction _f);

void DTReverseWalk(const D_tree &_t, treeNodeVisitFunction _f);

void DTSymmetricalWalk(const D_tree &_t, treeNodeVisitFunction _f);

#endif // _D_TREE_HPP_



