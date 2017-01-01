#include "Node.h"
#include "Entry.h"
#include "File.h"
#include <stdlib.h>

struct Node * Node_construct()
{
	struct Node * node = malloc(sizeof(struct Node));

	node->headEntry = NULL;

	return node;
}

void Node_destruct(struct Node * node)
{
	if (NULL != node->headEntry) {
		Entry_destruct(node->headEntry);
	}
	free(node);
}

struct Node * Node_create(struct File * file)
{
	struct Node * node = Node_construct();

    long int id = File_newPosition(file);
	node->headEntry = Entry_create(file, id);

	return node;
}

long int Node_id(struct Node * node)
{
    return Entry_outside(node->headEntry);
}

struct Node * Node_read(struct File * file, long int id)
{
    File_checkNodeId(file, id);

    struct Node * node = Node_construct();

    node->headEntry = Entry_read(file, id);

    return node;
}

long int Node_count(struct Node * node)
{
    return Entry_count(node->headEntry) - 1;
}

long int Node_ids(struct Node * node, long int index)
{
    return Entry_outsides(node->headEntry, index + 1);
}

void Node_connect(struct Node * fromNode, struct File * file, long int toNodeId)
{
    if (Node_id(fromNode) == toNodeId) {
        // error: node self-referencing
        exit(1);
    }

    if (1 == Entry_hasOutside(fromNode->headEntry, toNodeId)) {
        // already connected
        return;
    }

    File_checkNodeId(file, toNodeId);

    struct Entry * newEntry = Entry_create(file, toNodeId);
    struct Entry * lastEntry = Entry_tail(fromNode->headEntry);

    Entry_update(lastEntry, file, Entry_position(newEntry));
}
