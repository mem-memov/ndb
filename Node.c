#include "Node.h"
#include "Entry.c"
#include <stdlib.h>
#include <stdio.h>

struct Node * Node_construct()
{
	struct Node * node = malloc(sizeof(struct Node));

	node->head = NULL;

	return node;
}

void Node_destruct(struct Node * node)
{
	if (NULL != node->head) {
		Entry_destruct(node->head);
	}
	free(node);
}

struct Node * Node_create(char unitSizeInBytes, char * path)
{
	struct Node * node = Node_construct();
	node->head = Entry_create(unitSizeInBytes, path);
	return node;
}

long int Node_id(struct Node * node)
{
    return Entry_outside(node->head);
}

struct Node * Node_read(char unitSizeInBytes, char * path, long int id)
{
    struct Node * node = Node_construct();

    FILE * fileResource = fopen(path, "rb");

    if (NULL == fileResource) {
        // error opening file
    }

    node->head = Entry_read(unitSizeInBytes, fileResource, id);

    fclose(fileResource);

    return node;
}

long int Node_count(struct Node * node)
{
    return Entry_count(node->head) - 1;
}

long int Node_ids(struct Node * node, long int index)
{
    return Entry_outsides(node->head, index + 1);
}
