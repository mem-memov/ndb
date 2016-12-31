#include <stdio.h>

struct Entry {
	struct Link * outside;
	struct Link * inside;
	struct Entry * next;
};

struct Entry * Entry_construct();

void Entry_destruct(struct Entry * entry);

struct Entry * Entry_create(char unitSizeInBytes, char * path);

long int Entry_outside(struct Entry * entry);

struct Entry * Entry_read(char unitSizeInBytes, FILE * fileResource, long int outsideDestination);

long int Entry_count(struct Entry * entry);

long int Entry_outsides(struct Entry * entry, long int index);
