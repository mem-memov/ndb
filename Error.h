#ifndef ERROR_HEADER
#define ERROR_HEADER

#include <stdio.h>

void Error_inAddressWhileConstructing(char length);

void Error_inFileWhileConstructingWithUnitSize(char unitSizeInBytes);
void Error_inFileWhileDestructingResource(FILE * resource);
void Error_inFileBeforeOpening(FILE * resource);
void Error_inFileAfterOpeningWithWrongUnitSize(long int firstDestination);
void Error_inFileAfterOpening(FILE * resource);
void Error_inFileBeforeClosing(FILE * resource);
void Error_inFileBeforeGeneratingNewPosition(FILE * resource);
void Error_inFileWhileCheckingNodeIdOutOfRange(long int newPosition, long int nodeId);
void Error_inFileWhileCheckingNodeIdEqualsPosition(long int position, long int nodeId);

void Error_inEntrySearchingOutsideLinks();

void Error_inIdsBeforeAppendingWithOffset(long int offset, long int length, long int * items);
void Error_inIdsBeforeCopying(long int length, long int offset);

void Error_inNodeBeforeConnecting(long int fromNodeId, long int toNodeId);

#endif
