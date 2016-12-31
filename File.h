#ifndef FILE_HEADER
#define FILE_HEADER

#include <stdio.h>

struct File {
    char * path;
    char unitSizeInBytes;
    FILE * resource;
    char isAppending;
    char isReading;
    char isInserting;
};

struct File * File_construct(char * path, char unitSizeInBytes);

void File_destruct(struct File * file);

void File_openForAppending(struct File * file);

void File_openForReading(struct File * file);

void File_close(struct File * file);

void File_seekEnd(struct File * file);

void File_seekPosition(struct File * file, long int position);

long int File_position(struct File * file);

void File_appendByte(struct File * file, char byte);

void File_readBytes(struct File * file, char * buffer, char length);

char File_unitSizeInBytes(struct File * file);

#endif
