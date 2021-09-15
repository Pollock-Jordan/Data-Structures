#makefile for queue

queue : queue.o ../../CI/objects/queue/queueM.o ../array_list/array_list.o
	gcc --std=c18 queue.o ../array_list/array_list.o ../../CI/objects/queue/queueM.o -o queue

queue.o : queue.c queue.h ../array_list/array_list.h
	gcc --std=c18 -c queue.c

clean : 
	rm -f queue queue.o
