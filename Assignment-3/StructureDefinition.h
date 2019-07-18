typedef struct Node{
	int c,e;
	struct Node * next;
} Node;

int isEmpty(Node * head){
	return head -> next == 0;
}

Node* createEmptyList(){
	Node * tmp = (Node*)malloc(sizeof(Node));
	if(!tmp){
		printf("Fatal Error!\n");
		exit(0);
	}

	tmp->next = 0;
	return tmp;
}

void insert(Node * head,const int c,const int e){
	Node * tmp = (Node*)malloc(sizeof(Node)),
		 * ptr ;
	if(!tmp){
		printf("Fatal Error!\n");
		exit(0);
	}
	tmp -> c = c;
	tmp -> e = e;
	tmp -> next = 0;
	if(isEmpty(head))
		head -> next = tmp;
	else{
		ptr = head -> next;
		while(ptr -> next)
			ptr = ptr -> next;
		ptr -> next = tmp;
	}
}

void insertMiddle(Node * prev,int c, int e){
	Node * tmp = (Node*)malloc(sizeof(Node));
	tmp -> c = c;
	tmp -> e = e;
	tmp -> next  = prev -> next;
	prev -> next = tmp; 
}

void deleteList(Node * head){
	if(isEmpty(head))
		return;

	Node * tmp;
	while(head -> next!= 0){
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void putList(Node * head){
	if(!isEmpty(head)){
		Node * tmp = head -> next;
		while(tmp){
			printf("%+dx^%d ",tmp -> c,tmp -> e);
			tmp = tmp -> next;
		}
		printf("\n");
	}
	else
		printf("Empty List!\n");	
}

Node* addPolynomials(Node * head1,Node * head2){
	//Check if either list is empty
	if(isEmpty(head1)){
		if(!isEmpty(head2))
			return head2;
	}
	else{
		if(isEmpty(head2))
			return head1;
	}

	Node * head = createEmptyList(),
		 * p1 = head1 -> next,
		 * p2 = head2 -> next;

	while(p1 && p2){
		Node * tmp = (Node*)malloc(sizeof(Node));
		if(p1->e == p2->e){ 
			if(p1->c + p2->c)
				insert(head,p1->c+p2->c,p1->e);
			else
				free(tmp);
			p1 = p1 -> next;
			p2 = p2 -> next;
		}
		else if(p1->e > p2->e){
			insert(head,p1->c,p1->e);
			p1 = p1 -> next;
		}
		else {
			insert(head,p2->c,p2->e);
			p2 = p2 -> next;
		}
	}

	if(p1)
		while(p1){
			insert(head,p1->c,p1->e);
			p1 = p1 -> next;
		}
	if(p2)
		while(p2){
			insert(head,p2->c,p2->e);
			p2 = p2 -> next;
		}
	return head;
}

Node * findPrevious(Node * head,int e){
	if(isEmpty(head))
		return 0;

	Node * tmp = head;
	while(tmp->next){
		if(tmp ->next->e == e)
			return tmp;
		tmp = tmp -> next; 
	}

	return 0;
}

Node * product(Node * head1,Node * head2){
	
	if( isEmpty(head1) || isEmpty(head2) )
		return 0;

	Node * head = createEmptyList(),
		 * p1 = head1 -> next,
		 * p2 = head2 -> next;

	int c,e;

	while(p1){
		p2 = head2 -> next;
		while(p2){
			c = p1 -> c * p2 -> c;
			e = p1 -> e + p2 -> e;
			Node * prev = findPrevious(head,e);
			if(prev)
				prev -> next -> c += c;
			else
				insert(head,c,e);
			p2 = p2 -> next;

		}
		p1 = p1 -> next;
	}

	return head;
}

	
	
	
	