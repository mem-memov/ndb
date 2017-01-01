#ifndef UNIT_HEADER
#define UNIT_HEADER

#include "File.h"

struct Unit {
    char length;
	char * bytes;
};

struct Unit * Unit_construct(char length);

void Unit_destruct(struct Unit * unit);

long int Unit_value(struct Unit * unit);

struct Unit * Unit_create(char length, long int value);

struct Unit * Unit_read(struct File * file, long int position);

void Unit_write(struct Unit * unit, struct File * file, long int position);

void Unit_checkNodeId(struct File * file, long int position);

#endif
