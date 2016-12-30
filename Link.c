#include "Link.h"
#include "Unit.c"
#include <stdio.h>
#include <stdlib.h>

struct Link * Link_construct()
{
	struct Link * link = malloc(sizeof(struct Link));

	link->position = NULL;
	link->destination = NULL;

	return link;
}

void Link_destruct(struct Link * link)
{
	if (NULL != link->position) {
		Unit_destruct(link->position);
	}

	if (NULL != link->destination) {
		Unit_destruct(link->destination);
	}

	free(link);
}

struct Link * Link_create(char unitSizeInBytes, FILE * fileResource, long int destination)
{
    struct Link * link = Link_construct();

    fseek(fileResource, 0, SEEK_END);
    long int position = ftell(fileResource);

    link->position = Unit_create(unitSizeInBytes, position);
    link->destination = Unit_create(unitSizeInBytes, destination);

    Unit_write(link->destination, fileResource);

    return link;
}

long int Link_destination(struct Link * link)
{
    return Unit_value(link->destination);
}
