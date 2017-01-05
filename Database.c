#include "Database.h"
#include "File.h"
#include "Node.h"
#include "Ids.h"
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

long int Database_createNode(struct Database * database)
{
    File_open(database->file);
    struct Node * node = Node_create(database->file);
    long int nodeId = Node_id(node);
    Node_destruct(node);
    File_close(database->file);

    return nodeId;
}

struct Ids * Database_readNode(struct Database * database, long int nodeId)
{
    File_open(database->file);
    struct Node * node = Node_read(database->file, nodeId);
    long int nodeCount = Node_count(node);
    struct Ids * ids = Ids_construct(nodeCount);
    Node_ids(node, ids);
    Node_destruct(node);
    File_close(database->file);

    return ids;
}

void Database_connectNodes(struct Database * database, long int fromNodeId, long int toNodeId)
{
    File_open(database->file);
    struct Node * fromNode = Node_read(database->file, fromNodeId);
    Node_connect(fromNode, database->file, toNodeId);
    Node_destruct(fromNode);
    File_close(database->file);
}

struct Ids * Database_intersectNodes(struct Database * database, long int nodeIds, long int length)
{
    File_open(database->file);

    struct Node * thisNode = Node_read(database->file, nodeIds[0]);
    long int thisNodeCount = Node_count(thisNode);
    struct Ids * theseIds = Ids_construct(thisNodeCount);
    Node_ids(thisNode, theseIds);

    struct Ids * resultIds;

    long int i;
    for (i = 1; i < length; i++)
    {
        struct Node * thatNode = Node_read(database->file, nodeIds[i]);
        long int thatNodeCount = Node_count(thatNode);
        struct Ids * thoseIds = Ids_construct(thatNodeCount);
        Node_ids(thatNode, thoseIds);

        Ids_intersect(theseIds, thoseIds);
    }

    File_close(database->file);

    return resultIds;
}
