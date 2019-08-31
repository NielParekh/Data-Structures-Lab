#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SearchTree.h"
#include "Functions.h"

int main(){
	Tree t = createEmptyTree();
	int n;
	Data d;

	printf("Enter the number of elements: ");
	scanf("%d",&n);
	getchar();
	for(int i = 0 ; i < n ; i++){
		printf("Enter the name: ");
		scanf("%[^\n]",d);
		getchar();
		t = insert(t,d);
	}

	inorder(t);

	printf("\nEnter the name to find grand parent: ");
	scanf("%[^\n]",d);
	getchar();
	findGrandParent(t,d);

	printf("\nEnter the name to find grand parent: ");
	scanf("%[^\n]",d);
	getchar();
	findGrandParent(t,d);

	printf("\nEnter the name to find grand children: ");
	scanf("%[^\n]",d);
	getchar();
	findGrandChildren(t,d);


	printf("Enter the name to find sibling: ");
	scanf("%[^\n]",d);
	getchar();
	findSibling(t,d);


	printf("Enter the name to find sibling: ");
	scanf("%[^\n]",d);
	getchar();
	findSibling(t,d);


	printf("Enter the name to delete: ");
	scanf("%[^\n]",d);
	getchar();
	delete(t,d);
	inorder(t);
}