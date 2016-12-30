#include "Link.c"
#include <assert.h>
#include <stdio.h>

static void it_constructs_link_structure()
{
	struct Link * link = Link_construct();
	assert(NULL == link->position && "a constructed link has no position unit");
	assert(NULL == link->destination && "a constructed link has no destination unit");
}

static void it_destructs_link_structure()
{
	struct Link * link = Link_construct();
	Link_destruct(link);
	assert(1 && "it_destructs_link_structure");
}

int main()
{
	it_constructs_link_structure();
	it_destructs_link_structure();
	return 0;
}
