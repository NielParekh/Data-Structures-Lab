typedef char Data[30];

typedef struct treenode{
	Data d;
	struct treenode * left;
	struct treenode * right;
}Node;

typedef Node* Tree;

Tree createEmptyTree(){
	return 0;
}

Tree insert(Tree t,Data d){
	if(t == NULL){
		Tree tmp = (Tree)malloc(sizeof(Node));
		strcpy(tmp -> d,d);
		tmp -> right = tmp -> left = NULL;
		t = tmp;
	}
	else if(strcmp(d,t -> d) < 0)
		t -> left = insert(t -> left,d);
	else if(strcmp(d,t -> d) > 0)
		t -> right = insert(t -> right,d);
	else;//element already exists
	return t;
}

Tree findMinimum(Tree t){
	if(t == 0)
		return 0;
	Tree tmp  = t;
	while(tmp -> left)
		tmp = tmp -> left;
	return tmp;
}

Tree delete(Tree t,Data d){
	if(t == NULL){
		printf("Not Found!");
		return 0;
	}
	else if(strcmp(d,t -> d) < 0)
		t -> left = delete(t -> left,d);
	else if(strcmp(d,t -> d) > 0)
		t -> right = delete(t-> right,d);
	else{
		if(t -> left && t -> right){
			Tree tmp = findMinimum(t -> right);
			strcpy(t -> d,tmp -> d);
			delete(t -> right,tmp -> d);
		}
		else{
			Tree tmp = t;
			if(t -> left == NULL)
				t = t -> right;
			else if(t -> right == NULL)
				t = t -> left;
			free(tmp);
		}
	}
	return t;
}

void inorder(Tree t){
	if(t == NULL)
		return;
	inorder(t -> left);
	printf("%s ",t -> d);
	inorder(t -> right);
}