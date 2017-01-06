#include "Error.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Error_inAddressWhileConstructing(char length)
{
    if (0 >= length)
    {
        fprintf(stderr, "Error_inAddressWhileConstructing: address of no length.\n");
        exit(1);
    }
}

void Error_inFileWhileConstructingWithUnitSize(char unitSizeInBytes)
{
    if (0 >= unitSizeInBytes)
    {
        fprintf(stderr, "Error_inFileWhileConstructingWithUnitSize: units of no length.\n");
        exit(1);
    }
}

void Error_inFileWhileDestructingResource(FILE * resource)
{
    if (NULL != resource)
    {
        fprintf(stderr, "Error_inFileWhileDestructingResource: resource not closed.\n");
        exit(1);
    }
}

void Error_inFileBeforeOpening(FILE * resource)
{
    if (NULL != resource)
    {
        fprintf(stderr, "Error_inFileBeforeOpening: resource already open.\n");
        exit(1);
    }
}

void Error_inFileAfterOpeningWithWrongUnitSize(long int firstDestination)
{
    if (1 != firstDestination)
    {
        fprintf(stderr, "Error_inFileAfterOpeningWithWrongUnitSize: wrong file format.\n");
        exit(1);
    }
}

void Error_inFileAfterOpening(FILE * resource)
{
    if (NULL == resource)
    {
        fprintf(stderr, "Error_inFileAfterOpening: failed.\n");
        exit(1);
    }
}

void Error_inFileBeforeClosing(FILE * resource)
{
    if (NULL == resource)
    {
        fprintf(stderr, "Error_inFileBeforeClosing: resource not open.\n");
        exit(1);
    }
}

void Error_inFileBeforeGeneratingNewPosition(FILE * resource)
{
    if (NULL == resource)
    {
        fprintf(stderr, "Error_inFileBeforeGeneratingNewPosition: resource not open.\n");
        exit(1);
    }
}

void Error_inFileWhileCheckingNodeIdOutOfRange(long int newPosition, long int nodeId)
{
    if (newPosition <= nodeId)
    {
        fprintf(stderr, "Error_inFileWhileCheckingNodeIdOutOfRange: %ld is too big.\n", nodeId);
        exit(1);
    }

    if (0 >= nodeId)
    {
        fprintf(stderr, "Error_inFileWhileCheckingNodeIdOutOfRange: %ld is too small.\n", nodeId);
        exit(1);
    }
}

void Error_inFileWhileCheckingNodeIdEqualsPosition(long int position, long int nodeId)
{
    if (position != nodeId)
    {
        fprintf(stderr, "Error_inFileWhileCheckingNodeIdEqualsPosition: %ld is not a node id.\n", nodeId);
        exit(1);
    }
}

void Error_inIdsBeforeAppendingWithOffset(long int offset, long int length, long int * items)
{
    if (offset >= length)
    {
        fprintf(stderr, "Error_inIdsBeforeAppendingWithOffset: length %ld is not enough for offset %ld.\n", length, offset);
        exit(1);
    }

    if (0 != items[offset])
    {
        fprintf(stderr, "Error_inIdsBeforeAppendingWithOffset: item %ld is not free.\n", offset);
        exit(1);
    }
}

void Error_inIdsBeforeCopying(long int length, long int offset)
{
    if ((length - 1) == offset)
    {
        fprintf(stderr, "Error_inIdsBeforeCopying: only %ld items of %ld are filled.\n", (offset + 1), length);
        exit(1);
    }
}

void Error_inIdsBeforeIntersecting(long int length, long int offset)
{
    if ((length - 1) == offset)
    {
        fprintf(stderr, "Error_inIdsBeforeIntersecting: only %ld items of %ld are filled.\n", (offset + 1), length);
        exit(1);
    }
}

void Error_inIdsBeforeDifference(long int length, long int offset)
{
    if ((length - 1) == offset)
    {
        fprintf(stderr, "Error_inIdsBeforeDifference: only %ld items of %ld are filled.\n", (offset + 1), length);
        exit(1);
    }
}

void Error_inIdsBeforeUnion(long int length, long int offset)
{
    if ((length - 1) == offset)
    {
        fprintf(stderr, "Error_inIdsBeforeUnion: only %ld items of %ld are filled.\n", (offset + 1), length);
        exit(1);
    }
}

void Error_inIdsBeforeGetting(long int offset, long int length)
{
    long int limit = length - 1;
    if (offset > limit)
    {
        fprintf(stderr, "Error_inIdsBeforeGetting: offset %ld is over limit %ld.\n", offset, limit);
        exit(1);
    }
}

void Error_inIdsBeforeSetting(long int offset, long int length)
{
    long int limit = length - 1;
    if (offset > limit)
    {
        fprintf(stderr, "Error_inIdsBeforeSetting: offset %ld is over limit %ld.\n", offset, limit);
        exit(1);
    }
}

void Error_inLinkBeforeUpdating(long int destination, long int position)
{
    if (0 != destination)
    {
        fprintf(stderr, "Error_inLinkBeforeUpdating: link at position %ld not empty.\n", position);
        exit(1);
    }
}

void Error_inLinkAfterUpdating(long int destination, long int actualDestination, long int position)
{
    if (destination != actualDestination)
    {
        fprintf(stderr, "Error_inLinkAfterUpdating: link at position %ld could not hold the destination %ld which was overwritten by %ld. Data race may have caused this.\n", position, destination, actualDestination);
        exit(1);
    }
}

void Error_inNodeBeforeConnecting(long int fromNodeId, long int toNodeId)
{
    if (fromNodeId == toNodeId)
    {
        fprintf(stderr, "Error_inNodeBeforeConnecting: %ld node self-referencing.\n", fromNodeId);
        exit(1);
    }
}
