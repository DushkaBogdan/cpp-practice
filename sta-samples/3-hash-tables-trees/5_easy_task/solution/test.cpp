#include "h_table.hpp"
#include "vld.h"
#include <iostream>
#include <cassert>



int main()
{
	HTable *ht = HTableCreate(10);

	HTableInsert(*ht, "Hello!");
	HTableInsert(*ht, "Buggy");
	HTableInsert(*ht, "mah");

	assert(HTableHasKey(*ht, "Hello!"));
	assert(!HTableHasKey(*ht, "Hi!"));
	assert(HTableGetSize(*ht) == 10);

	HTableInsert(*ht, "Raw");
	HTableInsert(*ht, "muta");
	HTableInsert(*ht, "faaar");

	assert(HTableGetSize(*ht) == 20);
	assert(HTableNumElements(*ht) == 6);
	HTableRemove(*ht, "Hello!");
	assert(!HTableHasKey(*ht, "Hello!"));
	assert(HTableNumElements(*ht) == 5);

	HTableDestroy(ht);
}