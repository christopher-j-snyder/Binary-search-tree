p1: main1.o nodefunctions.o insertnode.o
	gcc main1.o nodefunctions.o insertnode.o -o p1

main1.o: main1.c node.h
	gcc -c main1.c

nodefunctions.o: nodefunctions.c node.h
	gcc -c nodefunctions.c

insertnode.o: insertnode.c node.h
	gcc -c insertnode.c

clean:
	rm -f *.o core
