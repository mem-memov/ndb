#include "Node.h"
#include "Entry.h"
#include "File.h"
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

struct Node * Node_create(struct File * file)
{
	struct Node * node = Node_construct();
	node->head = Entry_create(file);
	return node;
}

long int Node_id(struct Node * node)
{
    return Entry_outside(node->head);
}

struct Node * Node_read(struct File * file, long int id)
{
    struct Node * node = Node_construct();

    File_open(file);

    node->head = Entry_read(file, id);

    File_close(file);

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

void Node_connect(struct Node * fromNode, struct File * file, long int toNodeId)
{
    Entry_connect(fromNode->head, file, toNodeId);
}
