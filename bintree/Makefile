#makefile for bintree

all: bfs dfs search

bfs : search.o ../../CI/objects/search/bfsM.o
	gcc --std=c18 search.o ../../CI/objects/search/bfsM.o -o bfs

dfs : search.o ../../CI/objects/search/dfsM.o
	gcc --std=c18 search.o ../../CI/objects/search/dfsM.o -o dfs

search : search.o ../../CI/objects/search/searchM.o
	gcc --std=c18 search.o ../../CI/objects/search/searchM.o -o search

search.o : bintree.c bintree.h
	gcc --std=c18 -c bintree.c

clean :
	rm -f search.o bfs dfs search 
