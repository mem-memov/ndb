#include "Address.h"
#include <stdlib.h>

struct Address * Address_construct(long int length)
{
    struct Address * address = malloc(sizeof(struct Address));

    address->length = length;

    return address;
}

void Address_destruct(struct Address * address)
{
	free(address);
}

long int Address_position(struct Address * address, long int byteAddress)
{
    return (byteAddress / address->length) + 1;
}

long int Address_byteAddress(struct Address * address, long int position)
{
    return (position - 1) * address->length;
}
