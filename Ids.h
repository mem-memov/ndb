#ifndef IDS_HEADER
#define IDS_HEADER

struct Ids {
	long int * items;
	long int length;
};

struct Ids * Ids_construct();

void Ids_destruct(struct Ids * ids);

long int Ids_length(struct Ids * ids);

long int Ids_get(struct Ids * ids, long int offset);

void Ids_set(struct Ids * ids, long int offset, long int id);

long int Ids_copy(struct Ids * ids, long int * buffer, int length, int offset);

#endif
