#include "Entry.h"
#include "Link.c"
#include <stdlib.h>
#include <stdio.h>

struct Entry * Entry_construct()
{
	struct Entry * entry = malloc(sizeof(struct Entry));

	entry->inside = NULL;
	entry->outside = NULL;

	return entry;
}

void Entry_destruct(struct Entry * entry)
{
	if (NULL != entry->inside) {
		Link_destruct(entry->inside);
	}

	if  (NULL != entry->outside) {
		Link_destruct(entry->outside);
	}

	free(entry);
}

struct Entry * Entry_create(char unitSizeInBytes, char * path)
{
    struct Entry * entry = Entry_construct();

    FILE * fileResource = fopen(path, "a+b");

    if (NULL == fileResource) {
        // error opening file
    }

    fseek(fileResource, 0, SEEK_END);

    long int outsidePosition = ftell(fileResource);
    long int outsideDestination = (outsidePosition / unitSizeInBytes) + 1;
    long int insideDestination = 0;

    entry->outside = Link_create(unitSizeInBytes, fileResource, outsideDestination);
    entry->inside = Link_create(unitSizeInBytes, fileResource, insideDestination);

    fclose(fileResource);

    return entry;
}

long int Entry_outside(struct Entry * entry)
{
    return Link_destination(entry->outside);
}
