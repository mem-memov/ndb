ndb: main.o ndb.o Database.o File.o Address.o Node.o Entry.o Link.o Ids.o Error.o 
	gcc main.o ndb.o Database.o File.o Address.o Node.o Entry.o Link.o Ids.o Error.o -o ndb

main.o: main.c ndb.h
	gcc -c main.c

ndb.o: ndb.c Database.h Ids.h
	gcc -c ndb.c

Database.o: Database.c Database.h File.h Node.h Ids.h
	gcc -c Database.c

File.o: File.c File.h Address.h Error.h
	gcc -c File.c

Address.o: Address.c Address.h Error.h
	gcc -c Address.c

Node.o: Node.c Node.h Entry.h File.h Error.h
	gcc -c Node.c

Entry.o: Entry.c Entry.h Link.h File.h Error.h
	gcc -c Entry.c

Link.o: Link.c Link.h File.h
	gcc -c Link.c

Ids.o: Ids.c Ids.h Error.h
	gcc -c Ids.c

Error.o: Error.c Error.h
	gcc -c Error.c

clean:
	rm --force *.o ndb libndb.a

install:
	rm --force main.o && ar -rcs libndb.a *.o && cp libndb.a /usr/local/lib/libndb.a && cp ndb.h /usr/local/include/ndb.h

uninstall:
	rm --force /usr/local/lib/libndb.a /usr/local/include/ndb.h
