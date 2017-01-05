#ifndef ENTRY_HEADER
#define ENTRY_HEADER

#include "File.h"
#include "Ids.h"

struct Entry {
	struct Link * outsideLink;
	struct Link * insideLink;
	struct Entry * nextEntry;
};

struct Entry * Entry_construct();

void Entry_destruct(struct Entry * entry);

struct Entry * Entry_create(struct File * file, long int outsideDestination);

void Entry_update(struct Entry * entry, struct File * file, long int insideDestination);

long int Entry_outside(struct Entry * entry);

long int Entry_position(struct Entry * entry);

struct Entry * Entry_read(struct File * file, long int position);

long int Entry_count(struct Entry * entry);

void Entry_outsides(struct Entry * entry, struct Ids * ids);

struct Entry * Entry_tail(struct Entry * entry);

char Entry_hasOutside(struct Entry * entry, long int outsideDestination);

#endif
