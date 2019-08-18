typedef struct NodeTree{
	char data;
	struct NodeTree *left,*right;
} NodeTree;

typedef NodeTree* Tree;

Tree exprTree(char * const postfix,int *index){

	if(*index < 0)
		return NULL;

	while(postfix[*index] == ' ')
	(*index)--;


	Tree tmp = (Tree)malloc(sizeof(NodeTree));
	tmp -> data = postfix[*index];
	tmp -> right = tmp -> left = NULL;

	if(isOperator(postfix[*index])){
		(*index) = (*index) - 1;
		tmp -> right = exprTree(postfix,index);
		(*index) = (*index) - 1;
		tmp -> left = exprTree(postfix,index);
	}
	return tmp;

}


void inorder(Tree t){
	if(t == NULL)
		return;
	inorder(t ->left);
	printf("%c ",t -> data);
	inorder(t -> right);
}

void postorder(Tree t){
	if(t == NULL)
		return;
	postorder(t -> left);
	postorder(t -> right);
	printf("%c ",t -> data);
}

void preorder(Tree t){
	if(t == NULL)
		return;
	printf("%c ",t -> data);
	preorder(t -> left);
	preorder(t -> right);

}