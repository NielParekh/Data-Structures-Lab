typedef float Data;

typedef struct Node{
	Data d;
	struct Node * next;
}Node;

typedef Node* Stack;

Stack createEmptyStack(){
	return 0;
}

int isEmpty(Stack top){
	return top == 0;
}

void push(Stack * top,Data d){
	Node * tmp = (Node*)malloc(sizeof(Node));
	tmp -> d = d;
	tmp -> next = 0;
	if(!isEmpty(*top))
		tmp -> next = (*top);
	(*top) = tmp;
}

Data pop(Stack * top){
	Data rval = (*top) -> d;
	Node * tmp = *top;
	*top = (*top) -> next;
	free(tmp);
	return rval;
}

Data peek(Stack top){
	return top -> d; 
}


void displayStack(Stack top){
	Node * tmp = top;
	if(isEmpty(top)){
		printf("Empty Stack!");
		return;
	}
	while(tmp){
		printf("%c ",(char)(tmp -> d) );
		tmp = tmp -> next;
	}
	printf("\n");
}
