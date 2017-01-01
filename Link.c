#include "Link.h"
#include "Unit.h"
#include "File.h"
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

struct Link * Link_create(struct File * file, long int destination)
{
    struct Link * link = Link_construct();

    long int newPosition = File_newPosition(file);

    link->position = Unit_create(File_unitSizeInBytes(file), newPosition);
    link->destination = Unit_create(File_unitSizeInBytes(file), destination);

    Unit_write(link->destination, file, Unit_value(link->position));

    return link;
}

long int Link_position(struct Link * link)
{
    return Unit_value(link->position);
}

long int Link_destination(struct Link * link)
{
    return Unit_value(link->destination);
}

struct Link * Link_read(struct File * file, long int position)
{
    struct Link * link = Link_construct();

    link->position = Unit_create(File_unitSizeInBytes(file), position);
    link->destination = Unit_read(file, position);

    return link;
}

void Link_update(struct Link * link, struct File * file, long int destination)
{
    Unit_write(link->destination, file, Unit_value(link->position));
}
