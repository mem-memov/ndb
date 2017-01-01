#include "Link.h"
#include "Unit.h"
#include "File.h"
#include <stdlib.h>

struct Link * Link_construct()
{
	struct Link * link = malloc(sizeof(struct Link));

	link->positionUnit = NULL;
	link->destinationUnit = NULL;

	return link;
}

void Link_destruct(struct Link * link)
{
	if (NULL != link->positionUnit) {
		Unit_destruct(link->positionUnit);
	}

	if (NULL != link->destinationUnit) {
		Unit_destruct(link->destinationUnit);
	}

	free(link);
}

struct Link * Link_create(struct File * file, long int destination)
{
    struct Link * link = Link_construct();

    long int newPosition = File_newPosition(file);

    link->positionUnit = Unit_create(File_unitSizeInBytes(file), newPosition);
    link->destinationUnit = Unit_create(File_unitSizeInBytes(file), destination);

    Unit_write(link->destinationUnit, file, Unit_value(link->positionUnit));

    return link;
}

long int Link_position(struct Link * link)
{
    return Unit_value(link->positionUnit);
}

long int Link_destination(struct Link * link)
{
    return Unit_value(link->destinationUnit);
}

struct Link * Link_read(struct File * file, long int position)
{
    struct Link * link = Link_construct();

    link->positionUnit = Unit_create(File_unitSizeInBytes(file), position);
    link->destinationUnit = Unit_read(file, position);

    return link;
}

void Link_update(struct Link * link, struct File * file, long int destination)
{
    struct Unit * oldDestinationUnit = link->destinationUnit;
    struct Unit * newDestinationUnit = Unit_create(File_unitSizeInBytes(file), destination);

    link->destinationUnit = newDestinationUnit;
    Unit_destruct(oldDestinationUnit);

    Unit_write(link->destinationUnit, file, Unit_value(link->positionUnit));
}
