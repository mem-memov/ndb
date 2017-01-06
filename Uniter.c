#include "Uniter.h"

long int Uniter_count(long int * theseItems, long int thisLength, long int * thoseItems, long int thatLength)
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
				resultOffset++;
			}
			else
			{
				thatOffset++;
				resultOffset++;
			}
		}
	}

	while (thisOffset < thisLength)
	{
        thisOffset++;
        resultOffset++;
	}

	while (thatOffset < thatLength)
	{
        thatOffset++;
        resultOffset++;
	}

	return resultOffset;
}

void Uniter_union(long int * theseItems, long int thisLength, long int * thoseItems, long int thatLength, long int * resultItems, long int resultLength)
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
				resultItems[resultOffset] = theseItems[thisOffset];
				thisOffset++;
				resultOffset++;
			}
			else
			{
				resultItems[resultOffset] = thoseItems[thatOffset];
				thatOffset++;
				resultOffset++;
			}
		}
	}

	while (thisOffset < thisLength)
	{
        resultItems[resultOffset] = theseItems[thisOffset];
        thisOffset++;
        resultOffset++;
	}

	while (thatOffset < thatLength)
	{
        resultItems[resultOffset] = thoseItems[thatOffset];
        thatOffset++;
        resultOffset++;
	}
}
