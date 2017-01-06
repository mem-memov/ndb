#ifndef IDS_HEADER
#define IDS_HEADER

struct Ids {
	long int * items;
	long int length;
	long int offset;
};

struct Ids * Ids_construct();

void Ids_destruct(struct Ids * ids);

long int Ids_length(struct Ids * ids);

void Ids_append(struct Ids * ids, long int id);

long int Ids_copy(struct Ids * ids, long int * buffer, int length);

struct Ids * Ids_intersect(struct Ids * theseIds, struct Ids * thoseIds);

struct Ids * Ids_union(struct Ids * theseIds, struct Ids * thoseIds);

struct Ids * Ids_difference(struct Ids * theseIds, struct Ids * thoseIds);

#endif
