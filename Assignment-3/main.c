#include <stdio.h>
#include <stdlib.h>

#include "Prototypes.h"
#include "StructureDefinition.h"

int main(){
	Node * p1 ,
		 * p2 ,
		 * sum,
		 * prod;

	int e,c,n,stop = 0,opt;
	while(!stop){
		system("clear");

		printf("1 - Add Polynomials\n2 - Multiply\n3 - Exit\nEnter your choice: ");
		scanf("%d",&opt);
		
		if(opt == 3)
			break;
		p1 = createEmptyList();
		p2 = createEmptyList();
		printf("Enter the size of first polynomial: ");
		scanf("%d",&n);
		for(int i = 0 ; i < n ; i++){
			printf("Enter the coefficient & exponent: ");
			scanf("%d %d",&c,&e);
			insert(p1,c,e);
		}

		printf("\nEnter the size second polynomial: ");
		scanf("%d",&n);
		for(int i = 0 ; i < n ; i++){
			printf("Enter the coefficient & exponent: ");
			scanf("%d %d",&c,&e);
			insert(p2,c,e);
		}
		getchar();
		switch(opt){
			case 1: sum = addPolynomials(p1,p2);
					printf("\nThe sum is: ");
					putList(sum);
					deleteList(sum);
					break;
			case 2: printf("\nThe product is: ");
					prod = product(p1,p2);
					putList(prod);
					deleteList(prod);
					break;
			default:printf("Invalid Input!\n");
		}
		printf("Press any key to continue......");
		getchar();
		deleteList(p1);
		deleteList(p2);
	}
}
