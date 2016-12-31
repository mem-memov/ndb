#include "File.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct File * File_construct(char * path, char unitSizeInBytes)
{
	struct File * file = malloc(sizeof(struct File));

	file->path = malloc(strlen(path)+1);
	strcpy(file->path, path);

	file->unitSizeInBytes = unitSizeInBytes;

	file->resource = NULL;

    file->isAppending = 0;
    file->isReading = 0;
    file->isInserting = 0;

	return file;
}

void File_destruct(struct File * file)
{
	if (NULL != file->resource) {
        // error: resource not closed
	}

	free(file->path);
	free(file);
}

void File_openForAppending(struct File * file)
{
	if (NULL != file->resource) {
        // error: resource already open
	}

    file->resource = fopen(file->path, "a+b");

    if (NULL == file->resource) {
        // error opening file
    }

    file->isAppending = 1;
    file->isReading = 0;
    file->isInserting = 0;
}

void File_openForReading(struct File * file)
{
	if (NULL != file->resource) {
        // error: resource already open
	}

    file->resource = fopen(file->path, "rb");

    if (NULL == file->resource) {
        // error opening file
    }

    file->isAppending = 0;
    file->isReading = 1;
    file->isInserting = 0;
}

void File_close(struct File * file)
{
	if (NULL == file->resource) {
        // error: resource not open
	}

    fclose(file->resource);

    file->resource = NULL;

    file->isAppending = 0;
    file->isReading = 0;
    file->isInserting = 0;
}

void File_seekEnd(struct File * file)
{
	if (NULL == file->resource) {
        // error: resource not open
	}

	fseek(file->resource, 0, SEEK_END);
}

void File_seekPosition(struct File * file, long int position)
{
	if (NULL == file->resource) {
        // error: resource not open
	}

    fseek(file->resource, position, SEEK_SET);
}

long int File_position(struct File * file)
{
	if (NULL == file->resource) {
        // error: resource not open
	}

    return ftell(file->resource);
}

void File_appendByte(struct File * file, char byte)
{
    if (0 == file->isAppending) {
        // error: file is open in wrong mode
    }

    fwrite(&byte, sizeof(char), 1, file->resource);
}

void File_readBytes(struct File * file, char * buffer, char length)
{
    fread(buffer, 1, length, file->resource);
}

char File_unitSizeInBytes(struct File * file)
{
    return file->unitSizeInBytes;
}
