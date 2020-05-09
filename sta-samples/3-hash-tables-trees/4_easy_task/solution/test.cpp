#include "tree.hpp"
#include "vld.h"
#include <iostream>

void PrintLabel(const TreeNode &_pNode)
{
	std::cout << DTreeGetNodeLabel(&_pNode) << std::endl;
}

int main()
{
	D_tree *tree = create("University");

	TreeNode *NodeKN = DTAddChild("KN", tree->m_pRoot);
	TreeNode *NodeKIU = DTAddChild("KIU", tree->m_pRoot);
	TreeNode *NodeAKT = DTAddChild("AKT", tree->m_pRoot);
	TreeNode *NodeITM = DTAddChild("ITM", tree->m_pRoot);
	TreeNode *NodeIK = DTAddChild("IK", tree->m_pRoot);
	TreeNode *NodeELBI = DTAddChild("ELBI", tree->m_pRoot);
	TreeNode *NodeIPZI = DTAddChild("IPZI", tree->m_pRoot);
	TreeNode *NodeFNIG = DTAddChild("FNIG", tree->m_pRoot);

	DTAddChild("IUS", NodeKN);
	DTAddChild("SHI", NodeKN);
	DTAddChild("ST", NodeKN);
	DTAddChild("PI", NodeKN);
	DTAddChild("MST", NodeKN);

	DTAddChild("KITS", NodeKIU);
	DTAddChild("EOM", NodeKIU);
	DTAddChild("APOT", NodeKIU);
	DTAddChild("BIT", NodeKIU);
	DTAddChild("FFS", NodeKIU);

	DTAddChild("KITAM", NodeAKT);
	DTAddChild("PEEA", NodeAKT);
	DTAddChild("PHYS", NodeAKT);
	DTAddChild("OP", NodeAKT);

	DTAddChild("INF", NodeITM);
	DTAddChild("PM", NodeITM);
	DTAddChild("BM", NodeITM);
	DTAddChild("EK", NodeITM);
	DTAddChild("SI", NodeITM);

	DTAddChild("IKI", NodeIK);
	DTAddChild("IMI", NodeIK);
	DTAddChild("MTE", NodeIK);

	DTAddChild("BMI", NodeELBI);
	DTAddChild("MEEPP", NodeELBI);
	DTAddChild("FOET", NodeELBI);
	DTAddChild("FVS", NodeELBI);

	DTAddChild("MTS", NodeIPZI);
	DTAddChild("KRSTZI", NodeIPZI);
	DTAddChild("RTIKS", NodeIPZI);
	DTAddChild("MIRES", NodeIPZI);
	DTAddChild("IM", NodeIPZI);

	DTAddChild("MP", NodeFNIG);
	DTAddChild("PN", NodeFNIG);
	DTAddChild("UKR", NodeFNIG);

	DTDirectWalk(*tree, &PrintLabel);

	DTreeDestroy(tree);
}