#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Vertex.h"
#include "Dijkstras.h"

int main(void){
	int size;
	Graph g;

	printf(" Enter the number of vertices: ");
	scanf("%d",&size);
	getchar();

	for(int i = 0 ; i < size ; i++)
		g[i] = getVertex();

	adjList(g,size);
	printf("DIJKSTRA'S TABLE\n\n");
	dijkstra(g,size,g[0].v);

}