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

struct Entry * Entry_create(struct File * file, long int outsideDestination);

void Entry_update(struct Entry * entry, struct File * file, long int insideDestination);

long int Entry_outside(struct Entry * entry);

long int Entry_position(struct Entry * entry);

struct Entry * Entry_read(struct File * file, long int position);

long int Entry_count(struct Entry * entry);

long int Entry_outsides(struct Entry * entry, long int index);

struct Entry * Entry_tail(struct Entry * entry);

#endif
