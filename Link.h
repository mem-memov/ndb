#ifndef LINK_HEADER
#define LINK_HEADER

#include "File.h"

struct Link {
	long int position;
	long int destination;
};

struct Link * Link_construct();

void Link_destruct(struct Link * link);

struct Link * Link_create(struct File * file, long int destination);

long int Link_position(struct Link * link);

long int Link_destination(struct Link * link);

struct Link * Link_read(struct File * file, long int position);

void Link_update(struct Link * link, struct File * file, long int destination);

#endif
