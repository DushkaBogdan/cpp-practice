#include "st_tree.hpp"
#include "vld.h"
#include <iostream>

void PrintNodeLabel(const St_Tree &_t, int _index)
{
	std::cout << getLabel(_t, _index) << " ";
}

int main()
{
	const int N_SIZE = 7;

	St_Tree *t = treeCreate(N_SIZE);

	setNodeLadel(*t, 0, "A");
	setNodeLadel(*t, 1, "B");
	setNodeLadel(*t, 2, "C");
	setNodeLadel(*t, 3, "D");
	setNodeLadel(*t, 4, "E");
	setNodeLadel(*t, 5, "F");
	setNodeLadel(*t, 6, "G");

	setParentIndex(*t, 1, 0);
	setParentIndex(*t, 2, 0);
	setParentIndex(*t, 3, 0);
	setParentIndex(*t, 4, 1);
	setParentIndex(*t, 5, 1);
	setParentIndex(*t, 6, 2);
	

	std::cout << std::endl << "Parent Index of 1: " << getParentIndex(*t, 1) << std::endl;

	std::cout << std::endl << "Left Most Child of 0: " << getLeftMostChildIndex(*t, 0) << std::endl;
	std::cout << std::endl << "Left Most Child of 1: " << getLeftMostChildIndex(*t, 1) << std::endl;

	std::cout << std::endl << "Right Sibling of 1: " << getRightSiblingIndex(*t, 1) << std::endl;
	std::cout << std::endl << "Right Sibling of 4: " << getRightSiblingIndex(*t, 4) << std::endl;
	std::cout << std::endl << "Right Sibling of 2: " << getRightSiblingIndex(*t, 2) << std::endl;

	TreeDirectWalk(*t, &PrintNodeLabel);
	std::cout << std::endl;

	TreeReverseWalk(*t, &PrintNodeLabel);
	std::cout << std::endl;

	TreeSymmetricWalk(*t, &PrintNodeLabel);
	std::cout << std::endl;

	treeDestroy(t);
}