struct Node {
	struct Entry * head;
};

struct Node * Node_construct();

void Node_destruct(struct Node * node);

struct Node * Node_create(char unitSizeInBytes, char * path);

long int Node_id(struct Node * node);

struct Node * Node_read(char unitSizeInBytes, char * path, long int id);

long int Node_count(struct Node * node);

long int Node_ids(struct Node * node, long int index);
