#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "Vertex.h"
#include "Queue.h"
#include "Stack.h"
#include "GraphTraversal.h"


int main(void){
	Graph g;
	int size;
	Vertex start;

	printf("Enter the number of vertices: ");
	scanf("%d",&size);
	getchar();

	for(int i = 0 ; i < size; i++){
		g[i] = getVertex();
		
		if(i == 0)
			start = g[i];
	}

	/*
	printf("BFS OUTPUT:\n");
	BFS(g,size,start);
	*/

	printf("DFS OUTPUT:\n");
	DFS(g,size,start);
	return 0;
}

