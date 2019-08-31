void findGrandParent(Tree t,char * const name){
	if(t == NULL || (!t -> left && !t -> right) )
		return;
	if(t -> left){
		if(t -> left -> left){
			if(strcmp(t -> left -> left -> d,name) == 0){
				printf("%s is the grandparent\n",t ->d);
				return;
			}
		}
		if(t -> left -> right){
			if(strcmp(t -> left -> right -> d,name) == 0){
				printf("%s is the grandparent\n",t ->d);
				return;
			}
		}
		findGrandParent(t -> left,name);
	}
	if(t -> right){
		if(t -> right -> left){
			if(strcmp(t -> right -> left -> d,name) == 0){
				printf("%s is the grandparent\n",t ->d);
				return;
			}
		}
		if(t -> right -> right){
			if(strcmp(t -> right -> right -> d,name) == 0){
				printf("%s is the grandparent\n",t ->d);
				return;
			}
		}
		findGrandParent(t -> right,name);
	}
}

void findGrandChildren(Tree t,char * const name){
	int found = 0;
	if(t == NULL)
		return;
	if(t -> left){
		if(t -> left -> left){
			if(strcmp(t -> d,name) == 0){
				printf("%s is the grand child\n",t -> left -> left -> d);
				found = 1;
			}
		}
		if(t -> left -> right){
			if(strcmp(t -> d,name) == 0){
				printf("%s is the grand child\n",t -> left -> right -> d);
				found = 1;
			}
		}
	}
	if(t -> right){
		if(t -> right -> left){
			if(strcmp(t -> d,name) == 0){
				printf("%s is the grand child\n",t -> right -> left -> d);
				found = 1;
			}
		}
		if(t -> right -> right){
			if(strcmp(t ->  d,name) == 0){
				printf("%s is the grand child\n",t -> right -> right -> d);
				found = 1;
			}
		}
	}

	if(found)
		return;
	findGrandChildren(t -> left,name);
	findGrandChildren(t -> right,name);
}

void findSibling(Tree t,char * const name){
	if(t == NULL)
		return;
	if(t -> left && t -> right){
		if(strcmp(t -> left ->d,name) == 0){
			printf("%s is the sibling\n",t -> right -> d);
			return;
		}
		if( strcmp(t -> right ->d,name) == 0){
			printf("%s is the sibling\n",t -> left -> d);	
			return;
		}
	}
	findSibling(t -> left,name);
	findSibling(t -> right,name);
}