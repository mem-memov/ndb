#ifndef DATABASE_HEADER
#define DATABASE_HEADER

#include "File.h"

struct Database {
    struct File * file;
};

struct Database * Database_construct(char * path, char unitSizeInBytes);

void Database_destruct(struct Database * database);

void Database_createNode(struct Database * database);

void Database_readNode(struct Database * database, long int nodeId);

void Database_connectNodes(struct Database * database, long int fromNodeId, long int toNodeId);

#endif
