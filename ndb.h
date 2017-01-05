#ifndef NDB_HEADER
#define NDB_HEADER

long int ndb_create();

long int ndb_read(long int id, long int * buffer, int length);

void ndb_connect(long int from, long int to);

#endif
