#ifndef _ST_TREE_HPP_
#define _ST_TREE_HPP_

struct St_Tree;

St_Tree* treeCreate(int _size);

void setNodeLadel(St_Tree &_tree, int _index, char* _ladel);

void setParentIndex(St_Tree &_tree, int _index, int _parentIndex);

void treeDestroy(St_Tree *_tree);

void treeClear(St_Tree &_tree);

/*==============================================================================*/
typedef char* NodeLabel;

NodeLabel getLabel(const St_Tree &_tree, int _index);

int getRootIndex(const St_Tree &_tree);

int getParentIndex(const St_Tree &_tree, int _index);

int getLeftMostChildIndex(const St_Tree &_tree, int _parentIndex);

int getRightSiblingIndex(const St_Tree &_tree, int _index);

/*=============================================================================*/

typedef void(*NodeVisitFunction)(const St_Tree &_tree, int _i);

void TreeDirectWalk(const St_Tree &_tree,  NodeVisitFunction _f);
void TreeReverseWalk(const St_Tree &_tree,  NodeVisitFunction _f);
void TreeSymmetricWalk(const St_Tree &_tree, NodeVisitFunction _f);

#endif //_ST_TREE_HPP_

