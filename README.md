# ndb

NDB stands for Node Database. The database is capable of creating, connecting and reading ids of some graph nodes. It doesn't allow deleteng nodes or connections between them. All data is stored in form of a single binary file. If a number in the file equals its position then the number is a node id.

The first node is number one:
```
u@upc ~/repos/ndb $ xxd -b data
0000000: 00000000 00000000 00000000 00000000 00000000 00000001  ......
0000006: 00000000 00000000 00000000 00000000 00000000 00000000  ......
```

### Install

In order to install the **ndb** library on an Ubuntu system type the following commands in your terminal:

```
cd repos/
git clone git@github.com:mem-memov/ndb.git
cd ndb
make
./ndb
```

### Use

After installation you can utilize the **ndb** library in your **C** code.

```
#include <ndb.h>

// to create a new node
long int id = ndb_create();

// to read connections of a node
long int nodeId = 1;
int bufferLength = 4096;
long int buffer[bufferLength];
long int total = ndb_read(nodeId, buffer, bufferLength);

// to connect two nodes
long int fromNodeId = 1;
long int toNodeId = 3;
ndb_connect(fromNodeId, toNodeId);

// to find intesection on connection of several nodes
long int nodeCount = 3;
long int nodeIds[nodeCount] = { 1, 3, 27 };
int bufferLength = 4096;
long int buffer[bufferLength];
long int total = ndb_intersect(nodeIds, nodeCount, buffer, bufferLength);
```

You can maniputate the graph data from any language that supports sockets in Linux if you install the **ndb-server**.
