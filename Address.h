#ifndef ADDRESS_HEADER
#define ADDRESS_HEADER

struct Address {
    long int length;
};

struct Address * Address_construct(long int length);

void Address_destruct(struct Address * address);

long int Address_position(struct Address * address, long int byteAddress);

long int Address_byteAddress(struct Address * address, long int position);

#endif
