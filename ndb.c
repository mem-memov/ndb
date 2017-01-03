#include "ndb.h"
#include "Database.h"

static char unitSizeInBytes = 6;
static char * path = "data";
static struct Database * database;

long int ndb_create()
{
    database = Database_construct(path, unitSizeInBytes);
    Database_createNode(database);
    Database_destruct(database);
}

void ndb_read(long int id)
{
    database = Database_construct(path, unitSizeInBytes);
    Database_readNode(database, id);
    Database_destruct(database);
}

void ndb_connect(long int from, long int to)
{
    database = Database_construct(path, unitSizeInBytes);
    Database_connectNodes(database, from, to);
    Database_destruct(database);
}
