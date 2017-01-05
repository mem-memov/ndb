#ifndef INTERSECTOR_HEADER
#define INTERSECTOR_HEADER

long int Intersector_count(long int * theseItems, long int thisLength, long int * thoseItems, long int thatLength);

void Intersector_intersect(long int * theseItems, long int thisLength, long int * thoseItems, long int thatLength, long int * resultItems, long int resultLength);

#endif
