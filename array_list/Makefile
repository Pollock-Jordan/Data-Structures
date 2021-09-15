#makefile

array_list : array_list.o ../../CI/objects/array_list/arrayM.o
	gcc --std=c18 array_list.o ../../CI/objects/array_list/arrayM.o -o array_list

array_list.o : array_list.c array_list.h
	gcc --std=c18 -c array_list.c


clean :
	rm -f array_list array_list.o

