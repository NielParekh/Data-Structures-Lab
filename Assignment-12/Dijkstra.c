#include <stdio.h>
#include <stdlib.h>

#define notv -1
#define V1 6
#define MAX 10
#define false 0
#define true 1
#define infinity 1000

typedef int vertex;

typedef struct tableentry {
	int known;
	int dist;
	vertex path;
} tableentry;

typedef tableentry table [V1];

vertex choosevertex (table t, int x) {
	int size;
	size=V1;
	vertex min;
	for (int i=0; i<size; i++)
		if(t[i].known==false)
			min=i;
	for (int i=0; i<size; i++)
		if(t[i].known==false && t[i].dist < t[min].dist)
			min=i;

	return min;	
}

void inittable (vertex start, table t, int x)
{	int size;
	size=V1;
	
	for (int i=0; i<size; i++) {
		t[i].known= false;
		t[i].dist = infinity;
		t[i].path = notv;
	}

	t[start].dist = 0;
	t[start].path = 0;
}

int loopcondition (table t, int x) {
	
	int size;
	size=V1;
	
	for (int i=0; i<size; i++)
		if(t[i].known == false)
			return 1;
	return 0;
}


void djikstra (table t, int graph [][V1], int x ) {
	vertex v,w;
	int size;
	size=V1;
	while (loopcondition(t,x)) {
		v=choosevertex(t,x);
		t[v].known = true;
		for (w=0; w<size; w++) {
			if(graph[v][w] != 0) 
				if(t[w].known == false)
					if (t[v].dist + graph[v][w] < t[w].dist) {
						t[w].dist = t[v].dist + graph[v][w];
						t[w].path = v;
					}
		}
	}
}

void printpaths (int start, int end, table t, int path[], int *size, int *dist) {
	if (end != start)	{
		path[(*size)++] = t[end].path +1;
		*dist += t[end].dist;
		printpaths (start, t[end].path, t, path, size, dist);
	}
}

void reversepath (int path[], int size) {
	for (int i=size-1; i>=0; i--)
		printf ("%d   ", path[i]);
}

int main () {
	int n,e;
	printf("GRAPH 1\n\n");

	printf("Enter the no.of vertices of graph : ");
	scanf("%d",&n);
	printf("Enter the no.of edges of graph : ");
	scanf("%d",&e);
	int adj[n][n];

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++)
			adj[i][j] = 0;
	}

	printf("Enter  the edges of graph :\n");
	for(int i = 0; i<e; i++){
		int u,v,dist;
		scanf("%d %d %d",&u,&v,&dist);
		adj[u-1][v-1] = dist;
	}
	printf("\nAdj matrix :\n");
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}

	table t1;
	inittable(0, t1,1);
	djikstra(t1, adj,1);

	printf("\n");

	for (int i=1; i<V1; i++) {
		printf("Path from V1 to V%d:\n", i+1);
		int path[MAX];
		int size=0, dist=0;
		printpaths(0,i,t1, path, &size, &dist);
		reversepath(path, size);
		printf("%d", i+1);
		printf("\nDISTANCE: %d\n", dist);
		printf("\n"); 
	}

	/*
	printf("GRAPH 2\n");
	printf("\nEnter the no.of vertices of undirected graph : ");
	scanf("%d",&n);
	printf("Enter the no.of edges of the undirected graph : ");
	scanf("%d",&e);
	n = V1;
	int adj1[n][n];
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++)
			adj1[i][j] = 0;
	}

	printf("Enetr the edges of the undirected graph :\n");
	for(int i = 0; i<e; i++){
		int u,v,dist;
		scanf("%d %d %d",&u,&v,&dist);
		adj1[u-1][v-1] = dist;
		adj1[v-1][u-1] = dist;
	}

	table t2;
	inittable(0,t2,2);
	djikstra(t2, adj1, 2);

	printf("\nAdj matrix :\n");
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++)
			printf("%d ",adj1[i][j]);
		printf("\n");
	}

	printf("\n");

	for (int i=1; i<V2; i++) {
		printf("Path from V1 to V%d:\n", i+1);
		int path[MAX];
		int size=0, dist=0;
		printpaths(0,i,t2, path, &size, &dist);
		reversepath(path, size);
		printf("%d", i+1);
		printf("\nDISTANCE: %d\n", dist);
		printf("\n"); }
	return 0;
	*/
}
