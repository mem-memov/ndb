#include "Intersector.h"

long int Intersector_count(long int * theseItems, long int thisLength, long int * thoseItems, long int thatLength)
{
	long int thisOffset = 0;
	long int thatOffset = 0;
	long int resultOffset = 0;

	while ((thisOffset < thisLength) && (thatOffset < thatLength))
	{
		if (theseItems[thisOffset] == thoseItems[thatOffset])
		{
			thisOffset++;
            thatOffset++;
            resultOffset++;
		}
		else
		{
			if (theseItems[thisOffset] < thoseItems[thatOffset])
			{
				thisOffset++;
			} else {
				thatOffset++;
			}
		}
	}

	return resultOffset;
}

void Intersector_intersect(long int * theseItems, long int thisLength, long int * thoseItems, long int thatLength, long int * resultItems, long int resultLength)
{
	long int thisOffset = 0;
	long int thatOffset = 0;
	long int resultOffset = 0;

	while ((thisOffset < thisLength) && (thatOffset < thatLength))
	{
		if (theseItems[thisOffset] == thoseItems[thatOffset])
		{
			resultItems[resultOffset] = theseItems[thisOffset];
			thisOffset++;
            thatOffset++;
            resultOffset++;
		}
		else
		{
			if (theseItems[thisOffset] < thoseItems[thatOffset])
			{
				thisOffset++;
			} else {
				thatOffset++;
			}
		}
	}
}
