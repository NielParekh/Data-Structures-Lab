typedef struct Node{
	int data;
	struct Node * next;
}

Node* createEmptyStack(){
	return 0;
}

int isEmpty(Node * top){
	return top == 0;
}

void push(Node ** top,int data){
	Node * tmp = (Node*)malloc(sizeof(Node));
	tmp -> data = data;
	tmp -> next = 0;
	if(!isEmpty(top))
		*top -> next = tmp;
	*top = tmp;
}

int pop(Node ** top){

	if(isEmpty(top)){
		printf("Stack underflow!");
		return 0;
	}

	Node * tmp = *top;
	*top = *top -> next;
	free(tmp);
}







