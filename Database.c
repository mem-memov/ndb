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

struct Ids * Database_intersectNodes(struct Database * database, long int * nodeIds, long int length)
{
    File_open(database->file);

    struct Node * node;
    struct Ids * ids;
    struct Ids * temporaryIds;
    struct Ids * resultIds;
    long int nodeCount;
    long int i;
    for (i = 0; i < length; i++)
    {
        node = Node_read(database->file, nodeIds[i]);

        nodeCount = Node_count(node);
        ids = Ids_construct(nodeCount);
        Node_ids(node, ids);
        Node_destruct(node);

        if (0 == i)
        {
            resultIds = ids;
        }
        else
        {
            temporaryIds = Ids_intersect(resultIds, ids);
            Ids_destruct(resultIds);
            Ids_destruct(ids);
            resultIds = temporaryIds;
            if (0 == Ids_length(resultIds))
            {
                break;
            }
        }
    }
    File_close(database->file);

    return resultIds;
}

struct Ids * Database_unionNodes(struct Database * database, long int * nodeIds, long int length)
{
    File_open(database->file);

    struct Node * node;
    struct Ids * ids;
    struct Ids * temporaryIds;
    struct Ids * resultIds;
    long int nodeCount;
    long int i;
    for (i = 0; i < length; i++)
    {
        node = Node_read(database->file, nodeIds[i]);

        nodeCount = Node_count(node);
        ids = Ids_construct(nodeCount);
        Node_ids(node, ids);
        Node_destruct(node);

        if (0 == i)
        {
            resultIds = ids;
        }
        else
        {
            temporaryIds = Ids_union(resultIds, ids);
            Ids_destruct(resultIds);
            Ids_destruct(ids);
            resultIds = temporaryIds;
        }
    }
    File_close(database->file);

    return resultIds;
}

struct Ids * Database_differenceNodes(struct Database * database, long int * nodeIds, long int length)
{
    File_open(database->file);

    struct Node * node;
    struct Ids * ids;
    struct Ids * temporaryIds;
    struct Ids * resultIds;
    long int nodeCount;
    long int i;
    for (i = 0; i < length; i++)
    {
        node = Node_read(database->file, nodeIds[i]);

        nodeCount = Node_count(node);
        ids = Ids_construct(nodeCount);
        Node_ids(node, ids);
        Node_destruct(node);

        if (0 == i)
        {
            resultIds = ids;
        }
        else
        {
            temporaryIds = Ids_difference(resultIds, ids);
            Ids_destruct(resultIds);
            Ids_destruct(ids);
            resultIds = temporaryIds;
            if (0 == Ids_length(resultIds))
            {
                break;
            }
        }
    }
    File_close(database->file);

    return resultIds;
}

struct Ids * Database_insiders(struct Database * database, long int nodeId, long int * nodeIds, long int length)
{
    File_open(database->file);
    struct Node * node = Node_read(database->file, nodeId);
    long int nodeCount = Node_count(node);
    struct Ids * ids = Ids_construct(nodeCount);
    Node_ids(node, ids);
    struct Ids * resultIds = Ids_insiders(ids, nodeIds, length);
    Ids_destruct(ids);
    Node_destruct(node);
    File_close(database->file);

    return resultIds;
}

struct Ids * Database_outsiders(struct Database * database, long int nodeId, long int * nodeIds, long int length)
{
    File_open(database->file);
    struct Node * node = Node_read(database->file, nodeId);
    long int nodeCount = Node_count(node);
    struct Ids * ids = Ids_construct(nodeCount);
    Node_ids(node, ids);
    struct Ids * resultIds = Ids_outsiders(ids, nodeIds, length);
    Ids_destruct(ids);
    Node_destruct(node);
    File_close(database->file);

    return resultIds;
}
