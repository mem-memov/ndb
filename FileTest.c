#include "File.c"
#include <assert.h>
#include <stdio.h>

static void it_constructs_file_structure()
{
    char unitSizeInBytes = 6;
    char * path = "data";

	struct File * file = File_construct(path, unitSizeInBytes);
	assert(unitSizeInBytes == file->unitSizeInBytes && "a constructed file has unit size in bytes");
}

static void it_destructs_file_structure()
{
    char unitSizeInBytes = 6;
    char * path = "data";

	struct File * file = File_construct(path, unitSizeInBytes);
	File_destruct(file);
	assert(1 && "it_destructs_file_structure");
}

int main()
{
	it_constructs_file_structure();
	it_destructs_file_structure();
	return 0;
}
