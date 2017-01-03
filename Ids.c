#include "Ids.h"
#include "Error.h"
#include <stdlib.h>

struct Ids * Ids_construct(long int length)
{
	struct Ids * ids = malloc(sizeof(struct Ids));

	ids->length = length;
	ids->items = malloc(sizeof(long int));

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

long int Ids_get(struct Ids * ids, long int offset)
{
    Error_inIdsBeforeGetting(offset, ids->length);
    return ids->items[offset];
}

void Ids_set(struct Ids * ids, long int offset, long int id)
{
    Error_inIdsBeforeGetting(offset, ids->length);
    ids->items[offset] = id;
}

long int Ids_copy(struct Ids * ids, long int * buffer, int length, int offset)
{
    int i = offset;

    while (
        i >= 0
        && i < length
        && i < ids->length
    ) {
        buffer[i] = ids->items[offset];
        i++;
    }

    return ids->length;
}


