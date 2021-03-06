#ifndef NDB_HEADER
#define NDB_HEADER

long int ndb_create();

long int ndb_read(long int id, long int * buffer, int length);

void ndb_connect(long int from, long int to);

long int ndb_intersect(long int * ids, int idsLength, long int * buffer, int bufferLength);

long int ndb_union(long int * ids, int idsLength, long int * buffer, int bufferLength);

long int ndb_difference(long int * ids, int idsLength, long int * buffer, int bufferLength);

long int ndb_insiders(long int id, long int * ids, int idsLength, long int * buffer, int bufferLength);

long int ndb_outsiders(long int id, long int * ids, int idsLength, long int * buffer, int bufferLength);

#endif
