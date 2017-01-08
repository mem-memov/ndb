#include "File.h"
#include "Address.h"
#include "Error.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct File * File_construct(char * path, char unitSizeInBytes)
{
	struct File * file = malloc(sizeof(struct File));

	file->path = malloc(strlen(path)+1);
	strcpy(file->path, path);

	Error_inFileWhileConstructingWithUnitSize(unitSizeInBytes);
	file->unitSizeInBytes = unitSizeInBytes;

	file->resource = NULL;

	file->address = Address_construct(unitSizeInBytes);

	return file;
}

void File_destruct(struct File * file)
{
	Error_inFileWhileDestructingResource(file->resource);

	Address_destruct(file->address);
	free(file->path);
	free(file);
}

char File_unitSizeInBytes(struct File * file)
{
    return file->unitSizeInBytes;
}

void File_open(struct File * file)
{
	Error_inFileBeforeOpening(file->resource);

    file->resource = fopen(file->path, "rb+");

    if (NULL == file->resource)
    { // possibly file doesn't exist, let's create it
        file->resource = fopen(file->path, "ab+");
        Error_inFileAfterOpening(file->resource);
        fclose(file->resource);
        file->resource = fopen(file->path, "rb+");
        Error_inFileAfterOpening(file->resource);
    } else { // otherwise check unitsize
        long int firstDestination = File_read(file, 0);
        Error_inFileAfterOpeningWithWrongUnitSize(firstDestination);
    }
}

void File_close(struct File * file)
{
	Error_inFileBeforeClosing(file->resource);

    fclose(file->resource);
    file->resource = NULL;
}

long int File_read(struct File * file, long int position)
{
	long int byteAddress = Address_byteAddress(file->address, position);

	unsigned char bytes[file->unitSizeInBytes];

    fseek(file->resource, byteAddress, SEEK_SET);
    fread(bytes, 1, file->unitSizeInBytes, file->resource);

    long int destination = 0;
    int i;
    int offset;
    int skipCount = 0;
    char nonEmptyFound = 0;
    for (i = 0; i < file->unitSizeInBytes; i++)
    {
        if (0 == nonEmptyFound)
        {
            if (0 == bytes[i])
            {
                skipCount++;
            }
            else
            {
                nonEmptyFound = 1;
                destination = bytes[i];
            }
        }
        else
        {
            offset = 8 * (i - skipCount);
            destination = (destination << offset) | bytes[i];
        }
    };

    return destination;
}

long int File_write(struct File * file, long int position, long int destination)
{
	long int byteAddress = Address_byteAddress(file->address, position);

	unsigned char bytes[file->unitSizeInBytes];
    char i;
    char offset;
    for (i = 0; i < file->unitSizeInBytes; i++ )
    {
        offset = 8 * (file->unitSizeInBytes - i - 1);
        bytes[i] = (destination >> offset) & 0xFF;
    }

    fseek(file->resource, byteAddress, SEEK_SET);
    fwrite(bytes, sizeof(char), file->unitSizeInBytes, file->resource);
}

long int File_newPosition(struct File * file)
{
	Error_inFileBeforeGeneratingNewPosition(file->resource);

    fseek(file->resource, 0, SEEK_END);
    long int byteAddress = ftell(file->resource);

    return Address_position(file->address, byteAddress);
}

void File_checkNodeId(struct File * file, long int nodeId)
{
    long int newPosition = File_newPosition(file);
    Error_inFileWhileCheckingNodeIdOutOfRange(newPosition, nodeId);

    long int position = File_read(file, nodeId);
    Error_inFileWhileCheckingNodeIdEqualsPosition(position, nodeId);
}
