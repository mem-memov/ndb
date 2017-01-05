#include "Ids.h"
#include "Error.h"
#include <stdlib.h>

struct Ids * Ids_construct(long int length)
{
	struct Ids * ids = malloc(sizeof(struct Ids));

	ids->length = length;

	ids->items = malloc(sizeof(long int));

	long int i;
	for (i = 0; i < ids->length; i++)
	{
        ids->items[i] = 0; // indicator of free item, ids start with number one
	}

	ids->offset = 0;

	return ids;
}

void Ids_destruct(struct Ids * ids)
{
    free(ids->items);
    free(ids);
}

long int Ids_length(struct Ids * ids)
{
    return ids->length;
}

void Ids_append(struct Ids * ids, long int id)
{
    ids->offset++;
    Error_inIdsBeforeAppendingWithOffset(ids->offset, ids->length, ids->items);
    ids->items[ids->offset] = id;
}

long int Ids_copy(struct Ids * ids, long int * buffer, int length)
{
    Error_inIdsBeforeCopying(ids->length, ids->offset);

    int i = 0;

    while (i < length && i < ids->length)
    {
        buffer[i] = ids->items[i];
        i++;
    }

    return ids->length;
}


