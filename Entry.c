#include "Entry.h"
#include "Link.h"
#include "File.h"
#include <stdlib.h>

struct Entry * Entry_construct()
{
	struct Entry * entry = malloc(sizeof(struct Entry));

	entry->inside = NULL;
	entry->outside = NULL;
	entry->next = NULL;

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

struct Entry * Entry_create(struct File * file)
{
    struct Entry * entry = Entry_construct();

    File_openForAppending(file);
    File_seekEnd(file);

    long int outsidePosition = File_position(file);
    long int outsideDestination = (outsidePosition / File_unitSizeInBytes(file)) + 1;
    long int insideDestination = 0;

    entry->outside = Link_create(file, outsideDestination);
    entry->inside = Link_create(file, insideDestination);

    File_close(file);

    return entry;
}

long int Entry_outside(struct Entry * entry)
{
    return Link_destination(entry->outside);
}

struct Entry * Entry_read(struct File * file, long int outsideDestination)
{
    struct Entry * entry = Entry_construct();

    long int outsidePosition = (outsideDestination - 1) * File_unitSizeInBytes(file);
    long int insidePosition = outsidePosition + File_unitSizeInBytes(file);

    entry->outside = Link_read(file, outsidePosition);
    entry->inside = Link_read(file, insidePosition);

    long int insideDestination = Link_destination(entry->inside);

    if (0 != insideDestination) {
        entry->next = Entry_read(file, insideDestination);
    }

    return entry;
}

long int Entry_count(struct Entry * entry)
{
    if (NULL != entry->next) {
        return 1 + Entry_count(entry->next);
    }

    return 1;
}

long int Entry_outsides(struct Entry * entry, long int index)
{
    if (0 == index) {
        return Entry_outside(entry);
    }

    if (NULL != entry->next) {
        return Entry_outsides(entry->next, index-1);
    }

    // error getting entry
}
