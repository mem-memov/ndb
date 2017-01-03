#include "Error.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Error_inFileWhileConstructingWithUnitSize(char unitSizeInBytes)
{
    if (0 >= unitSizeInBytes) {
        fprintf(stderr, "Error_inFileWhileConstructingWithUnitSize: units of no length.\n");
        exit(1);
    }
}

void Error_inFileWhileDestructingResource(FILE * resource)
{
    if (NULL != resource) {
        fprintf(stderr, "Error_inFileWhileDestructingResource: resource not closed.\n");
        exit(1);
    }
}

void Error_inFileBeforeOpening(FILE * resource)
{
    if (NULL != resource) {
        fprintf(stderr, "Error_inFileBeforeOpening: resource already open.\n");
        exit(1);
    }
}

void Error_inFileAfterOpeningWithWrongUnitSize(long int firstDestination)
{
    if (1 != firstDestination) {
        fprintf(stderr, "Error_inFileAfterOpeningWithWrongUnitSize: wrong file format.\n");
        exit(1);
    }
}

void Error_inFileAfterOpening(FILE * resource)
{
    if (NULL == resource) {
        fprintf(stderr, "Error_inFileAfterOpening: failed.\n");
        exit(1);
    }
}

void Error_inFileBeforeClosing(FILE * resource)
{
    if (NULL == resource) {
        fprintf(stderr, "Error_inFileBeforeClosing: resource not open.\n");
        exit(1);
    }
}

void Error_inFileBeforeGeneratingNewPosition(FILE * resource)
{
    if (NULL == resource) {
        fprintf(stderr, "Error_inFileBeforeGeneratingNewPosition: resource not open.\n");
        exit(1);
    }
}

void Error_inFileWhileCheckingNodeIdOutOfRange(long int newPosition, long int nodeId)
{
    if (newPosition <= nodeId) {
        fprintf(stderr, "Error_inFileWhileCheckingNodeIdOutOfRange: %ld is too big.\n", nodeId);
        exit(1);
    }

    if (0 >= nodeId) {
        fprintf(stderr, "Error_inFileWhileCheckingNodeIdOutOfRange: %ld is too small.\n", nodeId);
        exit(1);
    }
}

void Error_inFileWhileCheckingNodeIdEqualsPosition(long int position, long int nodeId)
{
    if (position != nodeId) {
        fprintf(stderr, "Error_inFileWhileCheckingNodeIdEqualsPosition: %ld is not a node id.\n", nodeId);
        exit(1);
    }
}
