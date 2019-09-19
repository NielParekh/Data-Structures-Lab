typedef struct Vertex{
	char v;
	char adj[10];
	unsigned visited:1;
}Vertex;

typedef Vertex Graph[30];

Vertex getVertex(){
	Vertex vertex;
	char adj[10];
	char v; 
	vertex.visited = 0;
	
	printf("Enter the vertex: ");
	scanf("%c",&v);
	getchar();
	printf("Enter the verices adjacent to vertex: ");
	scanf("%[^\n]",adj);
	getchar();

	vertex.v = v;
	strcpy(vertex.adj,adj);

	return vertex;
}
