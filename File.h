#ifndef FILE_HEADER
#define FILE_HEADER

#include "Address.h"
#include <stdio.h>

struct File {
    char * path;
    char unitSizeInBytes;
    FILE * resource;
    struct Address * address;
};

struct File * File_construct(char * path, char unitSizeInBytes);

void File_destruct(struct File * file);

char File_unitSizeInBytes(struct File * file);

void File_open(struct File * file);

void File_close(struct File * file);

long int File_read(struct File * file, long int position);

long int File_write(struct File * file, long int position, long int destination);

long int File_newPosition(struct File * file);

#endif
