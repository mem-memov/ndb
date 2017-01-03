#include "Database.h"
#include "File.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Database * Database_construct(char * path, char unitSizeInBytes)
{
	struct Database * database = malloc(sizeof(struct Database));

	database->file = File_construct(path, unitSizeInBytes);

	return database;
}

void Database_destruct(struct Database * database)
{
    File_destruct(database->file);
    free(database);
}

void Database_createNode(struct Database * database)
{
    File_open(database->file);
    struct Node * node = Node_create(database->file);
    printf("%ld", Node_id(node));
    Node_destruct(node);
    File_close(database->file);
}

void Database_readNode(struct Database * database, long int nodeId)
{
    File_open(database->file);
    struct Node * node = Node_read(database->file, nodeId);
    long int externalNodeCount = Node_count(node);
    long int i;
    for (i = 0; i < externalNodeCount; i++) {
        printf("%ld ", Node_ids(node, i));
    }
    Node_destruct(node);
    File_close(database->file);
}

void Database_connectNodes(struct Database * database, long int fromNodeId, long int toNodeId)
{
    File_open(database->file);
    struct Node * fromNode = Node_read(database->file, fromNodeId);
    Node_connect(fromNode, database->file, toNodeId);
    Node_destruct(fromNode);
    File_close(database->file);
}
