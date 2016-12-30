#include "Unit.h"
#include <stdlib.h>
#include <stdio.h>

struct Unit * Unit_construct(char length)
{
	struct Unit * unit = malloc(sizeof(struct Unit));

	unit->length = length;
	unit->bytes = malloc(length);

    char i;
    for (i = 0; i < unit->length; i++) {
        unit->bytes[i] = 0;
    };

	return unit;
}

void Unit_destruct(struct Unit * unit)
{
	free(unit->bytes);
	free(unit);
}

struct Unit * Unit_create(char length, long int value)
{
    struct Unit * unit = Unit_construct(length);

    char i;
    char offset;
    for (i = 0; i < unit->length; i++ ) {
        offset = 8 * (unit->length - i - 1);
        unit->bytes[i] = (value >> offset) & 0xFF;
    }

    return unit;
}

void Unit_write(struct Unit * unit, FILE * fileResource)
{
    char i;
    char byte;
    for (i = 0; i < unit->length; i++) {
        byte = unit->bytes[i];
        fwrite(&byte, sizeof(char), 1, fileResource);
    };
}

long int Unit_value(struct Unit * unit)
{
    long int value = 0 + unit->bytes[0];

    char i;
    char byte;
    for (i = 1; i < unit->length; i++) {
        byte = (long int)unit->bytes[i];
        value = value * 256 * i + byte;
    };

    return value;
}
