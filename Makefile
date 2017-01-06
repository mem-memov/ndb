ndb: main.o ndb.o Address.o Database.o Differ.o Entry.o Error.o File.o Ids.o Intersector.o Link.o Node.o Sorter.o Uniter.o
	gcc main.o ndb.o Address.o Database.o Differ.o Entry.o Error.o File.o Ids.o Intersector.o Link.o Node.o Sorter.o Uniter.o -o ndb

main.o: main.c ndb.h
	gcc -c main.c

ndb.o: ndb.c Database.h Ids.h
	gcc -c ndb.c

Address.o: Address.c Address.h Error.h
	gcc -c Address.c

Differ.o: Differ.c Differ.h
	gcc -c Differ.c

Database.o: Database.c Database.h File.h Ids.h Node.h
	gcc -c Database.c

Entry.o: Entry.c Entry.h Error.h File.h Ids.h Link.h
	gcc -c Entry.c

Error.o: Error.c Error.h
	gcc -c Error.c

File.o: File.c File.h Address.h Error.h
	gcc -c File.c

Ids.o: Ids.c Ids.h Error.h Differ.h Intersector.h Sorter.h Uniter.h
	gcc -c Ids.c

Intersector.o: Intersector.c Intersector.h
	gcc -c Intersector.c

Link.o: Link.c Link.h File.h
	gcc -c Link.c

Node.o: Node.c Node.h Entry.h Error.h File.h Ids.h
	gcc -c Node.c

Sorter.o: Sorter.c Sorter.h
	gcc -c Sorter.c

Uniter.o: Uniter.c Uniter.h
	gcc -c Uniter.c

clean:
	rm --force *.o ndb libndb.a

install:
	install ndb /usr/local/bin/ndb && rm --force main.o && ar -rcs libndb.a *.o && cp libndb.a /usr/local/lib/libndb.a && cp ndb.h /usr/local/include/ndb.h

uninstall:
	rm --force ndb-server /usr/local/bin/ndb /usr/local/lib/libndb.a /usr/local/include/ndb.h
