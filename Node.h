#ifndef NODE_HEADER
#define NODE_HEADER

#include "File.h"

struct Node {
	struct Entry * headEntry;
};

struct Node * Node_construct();

void Node_destruct(struct Node * node);

struct Node * Node_create(struct File * file);

long int Node_id(struct Node * node);

struct Node * Node_read(struct File * file, long int id);

long int Node_count(struct Node * node);

long int Node_ids(struct Node * node, long int index);

void Node_connect(struct Node * fromNode, struct File * file, long int toNodeId);

#endif
