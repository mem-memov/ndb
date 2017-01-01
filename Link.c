#include "Link.h"
#include "File.h"
#include <stdlib.h>

struct Link * Link_construct()
{
	struct Link * link = malloc(sizeof(struct Link));

	link->position = 0;
	link->destination = 0;

	return link;
}

void Link_destruct(struct Link * link)
{
	free(link);
}

struct Link * Link_create(struct File * file, long int destination)
{
    struct Link * link = Link_construct();

    link->position = File_newPosition(file);
    link->destination = destination;

    File_write(file, link->position, link->destination);

    return link;
}

long int Link_position(struct Link * link)
{
    return link->position;
}

long int Link_destination(struct Link * link)
{
    return link->destination;
}

struct Link * Link_read(struct File * file, long int position)
{
    struct Link * link = Link_construct();

    link->position = position;
    link->destination = File_read(file, position);

    return link;
}

void Link_update(struct Link * link, struct File * file, long int destination)
{
    if (0 != link->destination) {
        // error updating link - link not empty
        exit(1);
    }

    long int oldDestination = link->destination;
    link->destination = destination;

    File_write(file, link->position, link->destination);

    long int actualDestination = File_read(file, link->position);

    if (link->destination != actualDestination) {
        // error: link write race - need to delete created entry
        exit(1);
    }
}
