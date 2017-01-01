ndb: main.o File.o Address.o Node.o Entry.o Link.o
	gcc main.o File.o Address.o Node.o Entry.o Link.o -o ndb

main.o: main.c Node.h File.h
	gcc -c main.c

File.o: File.c File.h Address.h
	gcc -c File.c

Address.o: Address.c Address.h
	gcc -c Address.c

Node.o: Node.c Node.h Entry.h File.h
	gcc -c Node.c

Entry.o: Entry.c Entry.h Link.h File.h
	gcc -c Entry.c

Link.o: Link.c Link.h File.h
	gcc -c Link.c

clean:
	rm *.o ndb

