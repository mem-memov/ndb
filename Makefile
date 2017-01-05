ndb: main.o ndb.o Address.o Database.o Entry.o Error.o File.o Ids.o Link.o Node.o
	gcc main.o ndb.o Address.o Database.o Entry.o Error.o File.o Ids.o Link.o Node.o -o ndb

main.o: main.c ndb.h
	gcc -c main.c

ndb.o: ndb.c Database.h Ids.h
	gcc -c ndb.c

Address.o: Address.c Address.h Error.h
	gcc -c Address.c

Database.o: Database.c Database.h File.h Node.h Ids.h
	gcc -c Database.c

Entry.o: Entry.c Entry.h Link.h File.h Ids.h Error.h
	gcc -c Entry.c

Error.o: Error.c Error.h
	gcc -c Error.c

File.o: File.c File.h Address.h Error.h
	gcc -c File.c

Ids.o: Ids.c Ids.h Error.h
	gcc -c Ids.c

Link.o: Link.c Link.h File.h
	gcc -c Link.c

Node.o: Node.c Node.h Entry.h File.h Ids.h Error.h
	gcc -c Node.c

clean:
	rm --force *.o ndb libndb.a

install:
	rm --force main.o && ar -rcs libndb.a *.o && cp libndb.a /usr/local/lib/libndb.a && cp ndb.h /usr/local/include/ndb.h

uninstall:
	rm --force /usr/local/lib/libndb.a /usr/local/include/ndb.h
