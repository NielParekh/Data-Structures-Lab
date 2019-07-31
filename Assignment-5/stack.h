typedef struct Node{
	char data;
	struct Node * next;
}Node;

typedef Node* Stack;

Stack createEmptyStack(){
	return 0;
}

int isEmpty(Stack top){
	return top == 0;
}

void push(Stack * top,int data){
	Node * tmp = (Node*)malloc(sizeof(Node));
	tmp -> data = data;
	tmp -> next = 0;
	if(!isEmpty(top))
		*top -> next = tmp;
	*top = tmp;
}

char pop(Stack * top){

	if(isEmpty(top)){
		printf("Stack underflow!");
		return 0;
	}
	char rval = *top -> data;
	Node * tmp = *top;
	*top = *top -> next;
	free(tmp);
	return rval;

}







