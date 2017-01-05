#include "Entry.h"
#include "Link.h"
#include "File.h"
#include "Ids.h"
#include "Error.h"
#include <stdlib.h>

struct Entry * Entry_construct()
{
	struct Entry * entry = malloc(sizeof(struct Entry));

	entry->insideLink = NULL;
	entry->outsideLink = NULL;
	entry->nextEntry = NULL;

	return entry;
}

void Entry_destruct(struct Entry * entry)
{
	if (NULL != entry->insideLink) {
		Link_destruct(entry->insideLink);
	}

	if  (NULL != entry->outsideLink) {
		Link_destruct(entry->outsideLink);
	}

	free(entry);
}

struct Entry * Entry_create(struct File * file, long int outsideDestination)
{
    struct Entry * entry = Entry_construct();

    entry->outsideLink = Link_create(file, outsideDestination);
    entry->insideLink = Link_create(file, 0);

    return entry;
}

void Entry_update(struct Entry * entry, struct File * file, long int insideDestination)
{
    Link_update(entry->insideLink, file, insideDestination);
}

long int Entry_outside(struct Entry * entry)
{
    return Link_destination(entry->outsideLink);
}

long int Entry_position(struct Entry * entry)
{
    return Link_position(entry->outsideLink);
}

struct Entry * Entry_read(struct File * file, long int position)
{
    struct Entry * entry = Entry_construct();

    entry->outsideLink = Link_read(file, position);
    entry->insideLink = Link_read(file, position + 1);

    long int insideDestination = Link_destination(entry->insideLink);

    if (0 != insideDestination) {
        entry->nextEntry = Entry_read(file, insideDestination);
    }

    return entry;
}

long int Entry_count(struct Entry * entry)
{
    if (NULL != entry->nextEntry) {
        return 1 + Entry_count(entry->nextEntry);
    }

    return 1;
}

void Entry_outsides(struct Entry * entry, struct Ids * ids)
{
    Ids_append(ids, Entry_outside(entry));

    if (NULL != entry->nextEntry) {
        return Entry_outsides(entry->nextEntry, ids);
    }

    Error_inEntrySearchingOutsideLinks();
}

struct Entry * Entry_tail(struct Entry * entry)
{
    if (NULL != entry->nextEntry) {
        return Entry_tail(entry->nextEntry);
    }

    return entry;
}

char Entry_hasOutside(struct Entry * entry, long int outsideDestination)
{
    if (Entry_outside(entry) == outsideDestination) {
        return 1;
    }

    if (NULL != entry->nextEntry) {
        return Entry_hasOutside(entry->nextEntry, outsideDestination);
    }

    return 0;
}
