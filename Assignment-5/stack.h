typedef enum {
	Operand,Operator
}DataType;

typedef struct{
	DataType dt;
	void * ptr;
}Data;

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

void push(Stack * top,DataType dt,void * ptr){
	Node * tmp = (Node*)malloc(sizeof(Node));
	tmp -> d.dt = dt;

	if(dt == Operand){
		int * x = (int*)malloc(sizeof(int));
		*x = *((int*)ptr);
		tmp -> d.ptr = (void*)x;
	}
	else{
		char * c = (char*)malloc(sizeof(char));
		*c = *((char*)ptr);
		tmp -> d.ptr = (void*)c;
	}
	
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
		if(tmp -> d.dt == Operand)
			printf("%d ",*((int*)tmp -> d.ptr) );
		else
			printf("%c ",*((char*)tmp -> d.ptr) );
		tmp = tmp -> next;

	}
	printf("\n");
}

void display(Stack top){
	if(isEmpty(top))
		return;
	if(top -> next)
		display(top -> next);
	if(top -> d.dt == Operand)
		printf("%d ",*((int*)top -> d.ptr) );
	else
		printf("%c ",*((char*)top -> d.ptr) );

}