#stack makefile

stack : stack.o ../../CI/objects/stack/stackM.o ../array_list/array_list.o
	gcc --std=c18 stack.o ../array_list/array_list.o ../../CI/objects/stack/stackM.o -o stack

stack.o : stack.c stack.h ../array_list/array_list.h
	gcc --std=c18 -c stack.c

clean :
	rm -f stack stack.o
