typedef struct Node{
	char jno[10];
	int bt;
	struct Node * next ;
}Node;


typedef Node * Queue;

int isEmpty(Queue front,Queue rear){
	if(front == 0 || rear == 0)
		return 1;
	return 0;
}

void enqueue(Queue *front,Queue *rear,char * const jno,const int bt){
	
	Node * tmp = (Node*)malloc(sizeof(Node));
	strcpy(tmp->jno,jno);
	tmp->bt = bt;

	if(isEmpty(*front,*rear))
		(*front) = (*rear) = tmp;
	else{
		(*rear) -> next = tmp;
		(*rear) = tmp;
	}

}

Node dequeue(Queue * front,Queue * rear){
	Node rval;
	Node * tmp;

	if(isEmpty(*front,*rear)){
		printf("Queue Empty!\n");
		return rval;
	}

	rval = *(*front);
	tmp = (*front);

	if( (*front) == (*rear) )
		(*front) = (*rear) = 0;
	else
		(*front) = (*front) -> next;
	
	
	free(tmp);
	return rval;
}


int getWaitTime(Queue front,Queue rear){
	if(isEmpty(front,rear))
		return -1;
	Node * tmp = front;
	int time = 0;
	while(tmp){
		time += tmp -> bt;
		tmp = tmp -> next;
	}

	return time;
}

float getAvgWaitTime(Queue front,Queue rear){
	if(isEmpty(front,rear))
		return -1.0;
	Node * tmp = front;
	float count = 0 , time = 0;
	while(tmp){
		time += tmp -> bt;
		count++;
		tmp = tmp -> next;
	}

	return (time/count);
}

void displayQueue(Queue front,Queue rear){
	if(isEmpty(front,rear))
		printf("Empty Queue!\n");
	else{
		Queue tmp = front;
		while(tmp){
			printf("Job No: %s\nBurst time: %d\n\n",tmp->jno,tmp->bt);
			tmp = tmp -> next;
		}
	}
}