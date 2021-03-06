#include "ndb.h"
#include "Database.h"
#include "Ids.h"

static char unitSizeInBytes = 6;
static char * path = "data";

long int ndb_create()
{
    struct Database * database = Database_construct(path, unitSizeInBytes);
    long int nodeId = Database_createNode(database);
    Database_destruct(database);

    return nodeId;
}

long int ndb_read(long int id, long int * buffer, int length)
{
    struct Database * database = Database_construct(path, unitSizeInBytes);
    struct Ids * ids = Database_readNode(database, id);
    long int total = Ids_copy(ids, buffer, length);
    Ids_destruct(ids);
    Database_destruct(database);

    return total;
}

void ndb_connect(long int from, long int to)
{
    struct Database * database = Database_construct(path, unitSizeInBytes);
    Database_connectNodes(database, from, to);
    Database_destruct(database);
}

long int ndb_intersect(long int * ids, int idsLength, long int * buffer, int bufferLength)
{
    struct Database * database = Database_construct(path, unitSizeInBytes);
    struct Ids * resultIds = Database_intersectNodes(database, ids, idsLength);
    long int total = Ids_copy(resultIds, buffer, bufferLength);
    Ids_destruct(resultIds);
    Database_destruct(database);

    return total;
}

long int ndb_union(long int * ids, int idsLength, long int * buffer, int bufferLength)
{
    struct Database * database = Database_construct(path, unitSizeInBytes);
    struct Ids * resultIds = Database_unionNodes(database, ids, idsLength);
    long int total = Ids_copy(resultIds, buffer, bufferLength);
    Ids_destruct(resultIds);
    Database_destruct(database);

    return total;
}

long int ndb_difference(long int * ids, int idsLength, long int * buffer, int bufferLength)
{
    struct Database * database = Database_construct(path, unitSizeInBytes);
    struct Ids * resultIds = Database_differenceNodes(database, ids, idsLength);
    long int total = Ids_copy(resultIds, buffer, bufferLength);
    Ids_destruct(resultIds);
    Database_destruct(database);

    return total;
}

long int ndb_insiders(long int id, long int * ids, int idsLength, long int * buffer, int bufferLength)
{
    struct Database * database = Database_construct(path, unitSizeInBytes);
    struct Ids * resultIds = Database_insiders(database, id, ids, idsLength);
    long int total = Ids_copy(resultIds, buffer, bufferLength);
    Ids_destruct(resultIds);
    Database_destruct(database);

    return total;
}

long int ndb_outsiders(long int id, long int * ids, int idsLength, long int * buffer, int bufferLength)
{
    struct Database * database = Database_construct(path, unitSizeInBytes);
    struct Ids * resultIds = Database_outsiders(database, id, ids, idsLength);
    long int total = Ids_copy(resultIds, buffer, bufferLength);
    Ids_destruct(resultIds);
    Database_destruct(database);

    return total;
}
