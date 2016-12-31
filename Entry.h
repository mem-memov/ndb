#ifndef ENTRY_HEADER
#define ENTRY_HEADER

#include "File.h"

struct Entry {
	struct Link * outside;
	struct Link * inside;
	struct Entry * next;
};

struct Entry * Entry_construct();

void Entry_destruct(struct Entry * entry);

struct Entry * Entry_create(struct File * file);

long int Entry_outside(struct Entry * entry);

struct Entry * Entry_read(struct File * file, long int outsideDestination);

long int Entry_count(struct Entry * entry);

long int Entry_outsides(struct Entry * entry, long int index);

void Entry_connect(struct Entry * entry, struct File * file, long int toNodeId);

#endif
