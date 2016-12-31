#include <stdio.h>

struct Unit {
    char length;
	char * bytes;
};

struct Unit * Unit_construct(char length);

void Unit_destruct(struct Unit * unit);

struct Unit * Unit_create(char length, long int value);

void Unit_write(struct Unit * unit, FILE * fileResource);

long int Unit_value(struct Unit * unit);

struct Unit * Unit_read(char length, FILE * fileResource, long int position);
