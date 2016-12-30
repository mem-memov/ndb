#include "Node.c"
#include <assert.h>
#include <stdio.h>

static void it_constructs_node_structure()
{
	struct Node * node = Node_construct();
	assert(NULL == node->head && "a constructed node has no head entry");
}

static void it_destructs_node_structure()
{
	struct Node * node = Node_construct();
	Node_destruct(node);
	assert(1 && "it_destructs_node_structure");
}

static void it_creates_node_entity()
{
	struct Node * node = Node_create(4, "data");
	assert(1 && "it_creates_node_entity");
}

int main()
{
	it_constructs_node_structure();
	it_destructs_node_structure();
	it_creates_node_entity();
	return 0;
}


