#include "q_tree.hpp"
#include "vld.h"
#include <cassert>
#include <iostream>

void PrintLabel(const Q_tree &_t, int _index)
{
	std::cout << QTreeGetLabel(_t, _index);
}

int main()
{
	const int SIZE = 7;

	Q_tree *t = QTreeCreate(SIZE);
	QTreeSetLabel(*t, 0, "Aa");
	QTreeSetLabel(*t, 1, "Bb");
	QTreeSetLabel(*t, 2, "Cc");
	QTreeSetLabel(*t, 3, "Dd");
	QTreeSetLabel(*t, 4, "Ee");
	QTreeSetLabel(*t, 5, "Ff");
	QTreeSetLabel(*t, 6, "Gg");

	QTreeSetParentIndex(*t, 0, 1);
	QTreeSetParentIndex(*t, 0, 2);
	QTreeSetParentIndex(*t, 0, 3);
	QTreeSetParentIndex(*t, 1, 4);
	QTreeSetParentIndex(*t, 1, 5);
	QTreeSetParentIndex(*t, 2, 6);


	QTDirectWalk(*t, &PrintLabel);
	std::cout << std::endl;

	QTReverseWalk(*t, &PrintLabel);
	std::cout << std::endl;

	QTSymmetricalWalk(*t, &PrintLabel);
	std::cout << std::endl;

	QTreeDestroy(t);
}