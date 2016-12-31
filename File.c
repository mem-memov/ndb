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

	return file;
}

void File_destruct(struct File * file)
{
	if (NULL != file->resource) {
        // error: resource not closed
        exit(1);
	}

	free(file->path);
	free(file);
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

void File_seekEnd(struct File * file)
{
	if (NULL == file->resource) {
        // error: resource not open
        exit(1);
	}

	fseek(file->resource, 0, SEEK_END);
}

void File_seekPosition(struct File * file, long int position)
{
	if (NULL == file->resource) {
        // error: resource not open
        exit(1);
	}

    fseek(file->resource, position, SEEK_SET);
}

long int File_position(struct File * file)
{
	if (NULL == file->resource) {
        // error: resource not open
        exit(1);
	}

    return ftell(file->resource);
}

void File_appendByte(struct File * file, char byte)
{
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
