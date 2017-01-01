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

    File_open(file);

    long int id = File_newPosition(file);
	node->headEntry = Entry_create(file, id);

    File_close(file);

	return node;
}

long int Node_id(struct Node * node)
{
    return Entry_outside(node->headEntry);
}

struct Node * Node_read(struct File * file, long int id)
{
    File_open(file);

    if (File_read(file, id) != id) {
        // error: not node id
        exit(1);
    }

    struct Node * node = Node_construct();

    node->headEntry = Entry_read(file, id);

    File_close(file);

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
    File_open(file);

    if (File_read(file, toNodeId) != toNodeId) {
        // error: not node id
        exit(1);
    }

    struct Entry * newEntry = Entry_create(file, toNodeId);
    struct Entry * lastEntry = Entry_tail(fromNode->headEntry);


    Entry_update(lastEntry, file, Entry_position(newEntry));

    File_close(file);
}
