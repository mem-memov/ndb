struct Node {
	struct Entry * head;
};

struct Node * Node_construct();

void Node_destruct(struct Node * node);

struct Node * Node_create(char unitSizeInBytes, char * path);

long int Node_id(struct Node * node);
