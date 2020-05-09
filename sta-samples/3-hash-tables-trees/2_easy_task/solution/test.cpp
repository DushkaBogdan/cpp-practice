#include "d_tree.hpp"
//#include "d_tree.cpp"
#include "vld.h"

#include <iostream>

void PrintNode(const TreeNode &_pNode)
{
	std::cout << _pNode.m_sLadel << " ";
}

void main()
{
	D_tree *t = create("Aa");

	TreeNode *pNodeB = DTAddChild("Bb", t->m_pRoot);
	TreeNode *pNodeC = DTAddChild("Cc", t->m_pRoot);
	DTAddChild("Dd", t->m_pRoot);

	DTAddChild("Ee", pNodeB);
	DTAddChild("Ff", pNodeB);

	DTAddChild("Gg", pNodeC);

	DTDirectWalk(*t, &PrintNode);
	std::cout << std::endl;

	DTReverseWalk(*t, &PrintNode);
	std::cout << std::endl;

	DTSymmetricalWalk(*t, &PrintNode);
	std::cout << std::endl;

	DTreeDestroy(t);

}