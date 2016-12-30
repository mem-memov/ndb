#include "Unit.c"
#include <assert.h>
#include <stdio.h>

static void it_constructs_unit_structure()
{
	struct Unit * unit = Unit_construct(4);
	assert(4 == unit->length && "a constructed unit has size in bytes");
}

static void it_destructs_unit_structure()
{
	struct Unit * unit = Unit_construct(4);
	Unit_destruct(unit);
	assert(1 && "it_destructs_unit_structure");
}

int main()
{
	it_constructs_unit_structure();
	it_destructs_unit_structure();
	return 0;
}
