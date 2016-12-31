#ifndef LINK_HEADER
#define LINK_HEADER

#include "File.h"

struct Link {
	struct Unit * position;
	struct Unit * destination;
};

struct Link * Link_construct();

void Link_destruct(struct Link * link);

struct Link * Link_create(struct File * file, long int destination);

long int Link_destination(struct Link * link);

struct Link * Link_read(struct File * file, long int position);

#endif
