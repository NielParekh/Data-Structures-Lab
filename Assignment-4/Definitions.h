struct Student{
	int regno;
	char name[30];
	int marks[3];
};

struct Node{
	Student s;
	struct Node * next;
	struct Node * prev;
};

Student getStudent(){
	Student s;
	printf("Enter the regno   : ");
	scanf("%d",&s.regno);
	getchar();
	printf("Enter the name    : ");
	scanf("%[^\n]",s.name);
	printf("Enter the marks   : ");
	for(int i = 0 ; i < 3 ; i++)
		scanf("%d",&s.marks[i]);
}

void putStudent(const Student s){
	printf("Regno     : %d\n",s.regno);
	printf("Name      : %s\n",s.name);
	printf("Marks     : ");
	for(int i = 0 ; i < 3 ; i++)
		printf("%d",s.marks[i]);
	printf("\n");
}

int isEmpty(Node * head,Node * tail){
	return head -> next == tail;
}

Node*  createEmptyList(){
	Node * head = (Node*)malloc(sizeof(Node)),
		 * tail = (Node*)malloc(sizeof(Node));

	head -> prev = 0;
	head -> next = tail;
	tail -> prev = head;
	tail -> next = 0;
	return head;
}


void addFirst(Node * head,Node * tail,const Student S){
	Node * temp = (Node*)malloc(sizeof(Node));
	temp -> s = S;
	temp -> next = head ->next;
	temp -> prev = head;
	head -> next -> prev = temp;
	head -> next  = temp;
}

void addLast(Node * head , Node * tail,const Student S){
	Node * temp = (Node*)malloc(sizeof(Node));
	temp -> s = S;
	temp -> next = tail;
	temp -> prev = tail -> prev;
	tail -> prev -> next = temp;
	tail -> prev = temp;
}

Node* findRecord(Node * head,Node * tail,char * const str){
	if(isEmpty(head,tail))
		return 0;

	Node * temp = head -> next;
	while(temp -> next){
		if( strcmp(temp->s.name,str) == 0 )
			return temp;
		temp = temp -> next;
	}
	return 0;	
}

void addName(Node * pos,const Student S){
	Node * temp = (Node*)malloc(sizeof(Node));
	temp -> s = S;
	temp -> prev = pos;
	temp -> next = pos -> next;
	pos -> next -> prev = temp;
	pos -> next = temp;
}

void putList(Node * head,Node * tail){
	if(isEmpty(head,tail)){
		printf("Empty List!\n");
		return;
	}

	Node * temp = head -> next;
	while(temp -> next){
		putStudent(temp -> s);
		temp = temp -> next;
	}
}

void putListSorted(Node * head,Node * tail){

}

void deleteRecord(Node * pos){
	pos -> prev -> next = pos -> next;
	pos -> next -> prev = pos -> prev;
}

