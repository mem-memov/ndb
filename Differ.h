#ifndef DIFFER_HEADER
#define DIFFER_HEADER

long int Differ_count(long int * theseItems, long int thisLength, long int * thoseItems, long int thatLength);

void Differ_difference(long int * theseItems, long int thisLength, long int * thoseItems, long int thatLength, long int * resultItems, long int resultLength);

#endif
