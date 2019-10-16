typedef	struct Vertex{
	char v;
	char adj[10];
	int dist[10];
}Vertex;

typedef Vertex Graph[10];

char * spaces(char str[]){
	static char word[15];
	strcpy(word,"");
	for(int i = 0 ; i < 14 ; i++)
		if(i < strlen(str))
			word[i] = str[i];
		word[i] = ' ';
	word[14] = 0;

	return word;
}

Vertex getVertex(){
	Vertex tmp;
	printf(" Enter the vertex: ");
	scanf("%c",&tmp.v);
	getchar();
	printf(" Enter the adjacent vertices: ");
	scanf("%[^\n]",tmp.adj);
	getchar();
	if(tmp.adj[0] != '-'){
		printf(" Enter the distance to vertices: ");
		for(int i = 0 ; i < strlen(tmp.adj) ; i++)
			scanf("%d",&tmp.dist[i]);
		getchar();
	}
	//tmp.visited = 0;

	return tmp;
}

void adjList(Graph g,const int size){
	printf(" +--------+----------------+\n");
	printf(" | Vertex | Adjacency List |\n");
	printf(" +--------+----------------+\n");
	for(int i = 0 ; i < size ; i++)
		printf(" |   %c    | %s |\n",g[i].v,spaces(g[i].adj));
	printf(" +--------+----------------+\n");

}