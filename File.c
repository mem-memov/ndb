#include "File.h"
#include "Address.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct File * File_construct(char * path, char unitSizeInBytes)
{
	struct File * file = malloc(sizeof(struct File));

	file->path = malloc(strlen(path)+1);
	strcpy(file->path, path);

    if (0 == unitSizeInBytes) {
        // error: units of no length
        exit(1);
    }
	file->unitSizeInBytes = unitSizeInBytes;

	file->resource = NULL;

	file->address = Address_construct(unitSizeInBytes);

	return file;
}

void File_destruct(struct File * file)
{
	if (NULL != file->resource) {
        // error: resource not closed
        exit(1);
	}

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
	if (NULL != file->resource) {
        // error: resource already open
        exit(1);
	}

    file->resource = fopen(file->path, "rb+");

    // possibly file doesn't exist, let's create it
    if (NULL == file->resource) {
        file->resource = fopen(file->path, "ab+");
        fclose(file->resource);
        file->resource = fopen(file->path, "rb+");
    }

    if (NULL == file->resource) {
        // error opening file
        exit(1);
    }
}

void File_close(struct File * file)
{
	if (NULL == file->resource) {
        // error: resource not open
        exit(1);
	}

    fclose(file->resource);

    file->resource = NULL;
}

void File_writeBytes(struct File * file, char * bytes, long int position)
{
	long int byteAddress = Address_byteAddress(file->address, position);

    fseek(file->resource, byteAddress, SEEK_SET);

    fwrite(bytes, sizeof(char), file->unitSizeInBytes, file->resource);
}

void File_readBytes(struct File * file, char * buffer, long int position)
{
	long int byteAddress = Address_byteAddress(file->address, position);

    fseek(file->resource, byteAddress, SEEK_SET);

    fread(buffer, 1, file->unitSizeInBytes, file->resource);
}

long int File_newPosition(struct File * file)
{
	if (NULL == file->resource) {
        // error: resource not open
        exit(1);
	}

    fseek(file->resource, 0, SEEK_END);
    long int byteAddress = ftell(file->resource);

    return Address_position(file->address, byteAddress);
}
