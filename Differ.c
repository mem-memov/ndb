#include "Differ.h"

long int Differ_count(long int * theseItems, long int thisLength, long int * thoseItems, long int thatLength)
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
			}
		}
	}

	while (thisOffset < thisLength)
	{
        thisOffset++;
        resultOffset++;
	}

	return resultOffset;
}

void Differ_difference(long int * theseItems, long int thisLength, long int * thoseItems, long int thatLength, long int * resultItems, long int resultLength)
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
				thatOffset++;
			}
		}
	}

	while (thisOffset < thisLength)
	{
        resultItems[resultOffset] = theseItems[thisOffset];
        thisOffset++;
        resultOffset++;
	}
}
