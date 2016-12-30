struct Entry {
	struct Link * outside;
	struct Link * inside;
};

struct Entry * Entry_construct();

void Entry_destruct(struct Entry * entry);

struct Entry * Entry_create(char unitSizeInBytes, char * path);

long int Entry_outside(struct Entry * entry);
