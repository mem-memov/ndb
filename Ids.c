#include "Ids.h"
#include "Error.h"
#include "Differ.h"
#include "Intersector.h"
#include "Sorter.h"
#include "Uniter.h"
#include <stdlib.h>

struct Ids * Ids_construct(long int length)
{
	struct Ids * ids = malloc(sizeof(struct Ids));

	ids->length = length;

	ids->items = malloc(sizeof(long int) * ids->length);

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
    Error_inIdsBeforeAppendingWithOffset(ids->offset, ids->length, ids->items);
    ids->items[ids->offset] = id;
    ids->offset++;
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

struct Ids * Ids_intersect(struct Ids * theseIds, struct Ids * thoseIds)
{
    Error_inIdsBeforeIntersecting(theseIds->length, theseIds->offset);
    Error_inIdsBeforeIntersecting(thoseIds->length, thoseIds->offset);

    long int theseItems[theseIds->length];
    Ids_copy(theseIds, theseItems, theseIds->length);

    long int thoseItems[thoseIds->length];
    Ids_copy(thoseIds, thoseItems, thoseIds->length);

    Sorter_sort(theseItems, theseIds->length);
    Sorter_sort(thoseItems, thoseIds->length);

    long int resultLength = Intersector_count(theseItems, theseIds->length, thoseItems, thoseIds->length);
    long int resultItems[resultLength];
    Intersector_intersect(theseItems, theseIds->length, thoseItems, thoseIds->length, resultItems, resultLength);

    struct Ids * resultIds = Ids_construct(resultLength);
    long int i;
    for (i = 0; i < resultLength; i++)
    {
        Ids_append(resultIds, resultItems[i]);
    }

    return resultIds;
}

struct Ids * Ids_union(struct Ids * theseIds, struct Ids * thoseIds)
{
    Error_inIdsBeforeUnion(theseIds->length, theseIds->offset);
    Error_inIdsBeforeUnion(thoseIds->length, thoseIds->offset);

    long int theseItems[theseIds->length];
    Ids_copy(theseIds, theseItems, theseIds->length);

    long int thoseItems[thoseIds->length];
    Ids_copy(thoseIds, thoseItems, thoseIds->length);

    Sorter_sort(theseItems, theseIds->length);
    Sorter_sort(thoseItems, thoseIds->length);

    long int resultLength = Uniter_count(theseItems, theseIds->length, thoseItems, thoseIds->length);
    long int resultItems[resultLength];
    Uniter_union(theseItems, theseIds->length, thoseItems, thoseIds->length, resultItems, resultLength);

    struct Ids * resultIds = Ids_construct(resultLength);
    long int i;
    for (i = 0; i < resultLength; i++)
    {
        Ids_append(resultIds, resultItems[i]);
    }

    return resultIds;
}


struct Ids * Ids_difference(struct Ids * theseIds, struct Ids * thoseIds)
{
    Error_inIdsBeforeDifference(theseIds->length, theseIds->offset);
    Error_inIdsBeforeDifference(thoseIds->length, thoseIds->offset);

    long int theseItems[theseIds->length];
    Ids_copy(theseIds, theseItems, theseIds->length);

    long int thoseItems[thoseIds->length];
    Ids_copy(thoseIds, thoseItems, thoseIds->length);

    Sorter_sort(theseItems, theseIds->length);
    Sorter_sort(thoseItems, thoseIds->length);

    long int resultLength = Differ_count(theseItems, theseIds->length, thoseItems, thoseIds->length);
    long int resultItems[resultLength];
    Differ_difference(theseItems, theseIds->length, thoseItems, thoseIds->length, resultItems, resultLength);

    struct Ids * resultIds = Ids_construct(resultLength);
    long int i;
    for (i = 0; i < resultLength; i++)
    {
        Ids_append(resultIds, resultItems[i]);
    }

    return resultIds;
}

struct Ids * Ids_insiders(struct Ids * ids, long int * nodeIds, long int length)
{
    Error_inIdsBeforeInsiders(ids->length, ids->offset);

    long int items[ids->length];
    Ids_copy(ids, items, ids->length);

    Sorter_sort(items, ids->length);
    Sorter_sort(items, ids->length);

    long int resultLength = Intersector_count(nodeIds, length, items, ids->length);
    long int resultItems[resultLength];
    Intersector_intersect(nodeIds, length, items, ids->length, resultItems, resultLength);

    struct Ids * resultIds = Ids_construct(resultLength);
    long int i;
    for (i = 0; i < resultLength; i++)
    {
        Ids_append(resultIds, resultItems[i]);
    }
}

struct Ids * Ids_outsiders(struct Ids * ids, long int * nodeIds, long int length)
{
    Error_inIdsBeforeOutsiders(ids->length, ids->offset);

    long int items[ids->length];
    Ids_copy(ids, items, ids->length);

    Sorter_sort(items, ids->length);
    Sorter_sort(items, ids->length);

    long int resultLength = Differ_count(nodeIds, length, items, ids->length);
    long int resultItems[resultLength];
    Differ_difference(nodeIds, length, items, ids->length, resultItems, resultLength);

    struct Ids * resultIds = Ids_construct(resultLength);
    long int i;
    for (i = 0; i < resultLength; i++)
    {
        Ids_append(resultIds, resultItems[i]);
    }
}
