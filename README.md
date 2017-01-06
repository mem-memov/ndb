# ndb

NDB stands for Node Database. The database is capable of creating, connecting and reading ids of some graph nodes. It doesn't allow deleteng nodes or connections between them. All data is stored in form of a single binary file. If a number in the file equals its position then the number is a node id. Otherwise it is a linked connection.

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

All operations on nodes are available in command line. Run the database in any directory in you Ubuntu system. If run without arguments it will display a help test with option list.

```
Node Database commands:
 ndb create
 ndb read my_id
 ndb connect my_from_id my_to_id
 ndb intersect my_id_1 my_id_2 ...
 ndb union my_id_1 my_id_2 ...
 ndb difference my_id_1 my_id_2 ...
 ndb insiders my_container_id my_id_1 my_id_2 ...
 ndb outsiders my_container_id my_id_1 my_id_2 ...
To view the file:
 xxd -b data | more
Source code: https://github.com/mem-memov/ndb
```

After installation you can utilize the **ndb** library in your **C** code.

```
#include <ndb.h>
```

You can maniputate the graph data from any programming language that supports sockets in Linux if you install the [ndb-server](https://github.com/mem-memov/ndb-server).
