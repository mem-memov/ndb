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

long int ndb_read(long int id, long int * buffer, int length, int offset)
{
    struct Database * database = Database_construct(path, unitSizeInBytes);
    struct Ids * ids = Database_readNode(database, id);

    long int total = Ids_copy(ids, buffer, length, offset);

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
