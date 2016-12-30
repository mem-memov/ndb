#include <stdio.h>

struct Link {
	struct Unit * position;
	struct Unit * destination;
};

struct Link * Link_construct();

void Link_destruct(struct Link * link);

struct Link * Link_create(char unitSizeInBytes, FILE * fileResource, long int destination);

long int Link_destination(struct Link * link);
