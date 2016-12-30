ndb: main.o Node.o Entry.o Link.o Unit.o
	gcc main.o Node.o -o ndb

main.o: main.c Node.h
	gcc -c main.c

Node.o: Node.c Node.h Entry.h
	gcc -c Node.c

Entry.o: Entry.c Entry.h Link.h
	gcc -c Entry.c

Link.o: Link.c Link.h Unit.h
	gcc -c Link.c

Unit.o: Unit.c Unit.h
	gcc -c Unit.c

clean:
	rm *.o ndb

test:	Node.o Entry.o Link.o Unit.o
	gcc NodeTest.c -o NodeTest && ./NodeTest
	gcc EntryTest.c -o EntryTest && ./EntryTest
	gcc LinkTest.c -o LinkTest && ./LinkTest
	gcc UnitTest.c -o UnitTest && ./UnitTest
	rm *Test
