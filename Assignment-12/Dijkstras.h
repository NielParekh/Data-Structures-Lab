#define INF 999

typedef struct Record{
	unsigned known:1;
	char vertex;
	char previous;
	int distance;
}Record;

typedef Record Table[10];

Record*  initialise(Graph g, const int size,const char source){
	static Table t;
	for(int i = 0 ; i < size ; i++){
		t[i].vertex = g[i].v;
		t[i].known = 0;
		t[i].previous = 0;
		t[i].distance = INF;
	
		if(g[i].v == source){
			t[i].distance = 0;
			t[i].previous = source;
		}
		
	}

	return t;
}



int findGraph(Graph g,const int size,char tmp){
	for(int i = 0 ; i < size ; i++ )
		if(g[i].v == tmp)
			return i;
	return -1;
}

int findTable(Table t,const int size,const char tmp){
	for(int i = 0 ; i < size ; i++ )
		if(t[i].vertex == tmp)
			return i;
	return -1;	
}

int loopcondition(Table t,const int size){
	int min = -1;
	int mindist = INF;
	for(int i = 0 ; i < size ; i++)
		if(t[i].known == 0 && t[i].distance < mindist){
			min = i;
			mindist = t[i].distance;
		}

	return min;
}

void putTable(Table t,const int size){
	printf(" +--------+----------+----------+\n");
	printf(" | Vertex | Distance | Previous |\n");
	printf(" +--------+----------+----------+\n");
	for(int i = 0 ; i < size ; i++)
		printf(" |   %c    | %8d |    %c     |\n",t[i].vertex,t[i].distance,t[i].previous);
	printf(" +--------+----------+----------+\n");
}

void dijkstra(Graph g,const int size,char source){
	Record * t = initialise(g,size,source);

	Record tmp,r;
	Vertex temp;
	char * adj;
	int  * dist;
	int index;
	int k;
	while(loopcondition(t,size) != -1){
		index = loopcondition(t,size);
		temp = g[findGraph(g,size,t[index].vertex)];
		adj = temp.adj;
		dist= temp.dist;

		t[index].known = 1;
		if(adj[0] == '-')
			continue;

		for(int i = 0 ; i < strlen(adj) ; i++ ){
			k = findTable(t,size,adj[i]);
			if(t[index].distance + dist[i] < t[k].distance){
				t[k].distance = t[index].distance + dist[i];
				t[k].previous = t[index].vertex;
			}
		}

	}

	putTable(t,size);

}