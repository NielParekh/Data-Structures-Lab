typedef struct record{
	char word[50];
	char hindi[50];
	char tamil[50];
}Record;

typedef struct avlnode{
	Record r;
	struct avlnode * left , * right;
	short int height;
}AVLTreeNode;

typedef AVLTreeNode * AVLTree;

static int height(AVLTree t){
	if(t == NULL)
		return -1;

	return t -> height;
}
int max(int a,int b){
	return ((a > b)? a : b);
}
static AVLTree singlerotatewithleft(AVLTree k2){
	AVLTree k1;
	k1 = k2 -> left;
	k2 -> left = k1 -> right;
	k1 -> right = k2;

	k2 -> height = max(height(k2 -> left),height(k2 -> right)) + 1;
	k1 -> height = max(height(k1 -> left),k2 -> height) + 1;

	return k1;
}

static AVLTree singlerotatewithright(AVLTree k2){
	AVLTree k1;
	k1 = k2 -> right;
	k2 -> right = k1 -> left;
	k1 -> left = k2;
	
	k2 -> height = max(height(k2 -> left),height(k2 -> right)) + 1;
	k1 -> height = max(height(k1 -> left),k2 -> height) + 1;

	return k1;
}

static AVLTree doublerotatewithleft(AVLTree k3){
	k3 -> left = singlerotatewithright(k3 -> left);

	return singlerotatewithleft(k3);
}

static AVLTree doublerotatewithright(AVLTree k3){
	k3 -> right = singlerotatewithleft(k3 -> right);

	return singlerotatewithright(k3);
}


AVLTree insert(Record r,AVLTree t){
	if(t == NULL){
		t = (AVLTree)malloc(sizeof(AVLTreeNode));
		t -> r = r;
		t -> left = t -> right = NULL;
	}
	else if(strcmp(r.word,t -> r.word) < 0){
		t -> left = insert(r,t -> left);
		if(height(t -> left) - height(t -> right) == 2)
			if(strcmp(r.word,t -> left -> r.word) < 0){
				printf("\nSingle rotate performed!\n");
				t = singlerotatewithleft(t);
			}
			else{
				printf("\nDouble rotate performed!\n");
				t = doublerotatewithleft(t);			
			}
	}

	else if(strcmp(r.word,t -> r.word) > 0){
		t -> right = insert(r,t -> right);
		if(height(t -> right) - height(t -> left) == 2)
			if(strcmp(r.word,t -> right -> r.word) > 0){
				printf("\nSingle rotate performed!\n");
				t = singlerotatewithright(t);
			}
			else{
				printf("\nDouble rotate performed!\n");
				t = doublerotatewithright(t);
			}
	}

	t -> height = max(height(t -> left),height(t -> right)) + 1;
	return t;
}

void search(AVLTree t,char * const word){
	if(t == NULL){
		printf("Not found!\n");
		return;
	}

	if(strcmp(word,t -> r.word) < 0)
		return search(t -> left,word);
	else if(strcmp(word,t -> r.word) > 0)
		return search(t -> right,word);
	else
		printf("\nWord    : %s\nHindi   : %s\nTamil   : %s\n",t -> r.word,t -> r.hindi,t -> r.tamil);
}

void inorder(AVLTree t){
	if(t == NULL)
		return;
	inorder(t -> left);
	printf("%s\t",t -> r.word);
	inorder(t -> right);
}