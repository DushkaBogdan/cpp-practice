#ifndef _Q_TREE_HPP_
#define _Q_TREE_HPP_


struct Q_tree;

Q_tree* QTreeCreate(int _size);

void QTreeDestroy(Q_tree *_pTree);

typedef char* TreeNodeLabel;

TreeNodeLabel QTreeGetLabel(const Q_tree &_t, int _index);

void QTreeSetLabel(Q_tree &_t, int _index, TreeNodeLabel _l);

int QTreeGetRoot(const Q_tree &_t);

int QTreeGetLeftMostChild(const Q_tree &_t, int _parentIndex);

int QTreeGetRightSibling(const Q_tree &_t, int _index);
//
int QTreeGetParent(const Q_tree &_t, int _index);

void QTreeSetParentIndex(Q_tree &_t, int _parentIndex, int _childIndex);

typedef void (*treeNodeVisitFunction)(const Q_tree &_t, int _index);

void QTDirectWalk(const Q_tree &_t, treeNodeVisitFunction _f);

void QTReverseWalk(const Q_tree &_t, treeNodeVisitFunction _f);

void QTSymmetricalWalk(const Q_tree &_t, treeNodeVisitFunction _f);

#endif // _Q_TREE_HPP_


