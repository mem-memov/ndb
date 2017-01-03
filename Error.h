#ifndef ERROR_HEADER
#define ERROR_HEADER

#include <stdio.h>

void Error_inFileWhileConstructingWithUnitSize(char unitSizeInBytes);
void Error_inFileWhileDestructingResource(FILE * resource);
void Error_inFileBeforeOpening(FILE * resource);
void Error_inFileAfterOpeningWithWrongUnitSize(long int firstDestination);
void Error_inFileAfterOpening(FILE * resource);
void Error_inFileBeforeClosing(FILE * resource);
void Error_inFileBeforeGeneratingNewPosition(FILE * resource);
void Error_inFileWhileCheckingNodeIdOutOfRange(long int newPosition, long int nodeId);
void Error_inFileWhileCheckingNodeIdEqualsPosition(long int position, long int nodeId);

#endif
