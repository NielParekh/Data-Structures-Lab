#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AVLTree.h"


int main(void){
	AVLTree t = NULL; 
	int n = 0;
	Record r;
	printf("Enter the number of records: ");
	scanf("%d",&n);
	getchar();

	for(int i = 0 ; i < n ; i++){
		system("clear");
		printf("Enter the word           : ");
		scanf("%[^\n]",r.word);
		getchar();
		printf("Enter the tamil meaning  : ");
		scanf("%[^\n]",r.tamil);
		getchar();
		printf("Enter the hindi meaning  : ");
		scanf("%[^\n]",r.hindi);
		getchar();
		t = insert(r,t);

		printf("Tree after insertion: \n");
		inorder(t);
		printf("\n");

		printf("Press any key to continue......");
		getchar();

	}

	int stop = 0;

	char word[50];
	while(!stop){
		system("clear");
		
		printf("Enter the word to search : ");
		scanf("%s",word);
		search(t,word);

		printf("Do you want to stop 1/0: ");
		scanf("%d",&stop);
		

	}
}