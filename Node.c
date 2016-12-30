#include "Node.h"
#include "Entry.c"
#include <stdlib.h>

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
