#include "Entry.c"
#include <assert.h>
#include <stdio.h>

static void it_constructs_entry_structure()
{
	struct Entry * entry = Entry_construct();
	assert(NULL == entry->outside && "a constructed entry has no outside link");
	assert(NULL == entry->inside && "a constructed entry has no inside link");
}

static void it_destructs_entry_structure()
{
	struct Entry * entry = Entry_construct();
	Entry_destruct(entry);
	assert(1 && "it_destructs_entry_structure");
}

int main()
{
	it_constructs_entry_structure();
	it_destructs_entry_structure();
	return 0;
}
