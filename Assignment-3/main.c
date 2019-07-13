#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "Prototypes.h"
#include "StructureDefinition.h"

int main(){
	Node * p1 = createEmptyList(),
		 * p2 = createEmptyList(),
		 * sum,
		 * prod;

	int e,c,stop = 0;

	printf("Enter the first polynomial\n");
	while(!stop){
		printf("Enter the coefficient & exponent: ");
		scanf("%d %d",&c,&e);
		insert(p1,c,e);
		printf("Do you want to stop? 1/0: ");
		scanf("%d",&stop);
	}

	printf("\nEnter the second polynomial\n");
	
	stop = 0;
	while(!stop){
		printf("Enter the coefficient & exponent: ");
		scanf("%d %d",&c,&e);
		insert(p2,c,e);
		printf("Do you want to stop? 1/0: ");
		scanf("%d",&stop);
	}
	
	printf("\n");
	printf("The first polynomial is: ");
	putList(p1);
	printf("The second polynomial is : ");
	putList(p2);
	sum = addPolynomials(p1,p2);
	printf("\nThe sum is: ");
	putList(sum);
	printf("\nThe product is: ");
	prod = product(p1,p2);
	putList(prod);
}