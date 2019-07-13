#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FunctionPrototypes.h"
#include "struct_student.h"

int main(void){
	int size,
		stop = 0,
		opt = -1,
		regno;
	char name[30];

	printf("Enter the size of the list: ");
	scanf("%d",&size);

	List * L = createList(size);

	while(!stop){
		system("clear");
		printf("1 - Add at end\n2 - Add at start\n3 - Add after regno\n4 - Search by name\n5 - Delete a given record\n");
		printf("6 - Display all elements\n7 - Previous and next\n8 - exit\nEnter your choice: ");
		scanf("%d",&opt);
		getchar();

		switch(opt){
			case 1: addEnd(L,getStudent());	  			break;

			case 2: addStart(L,getStudent()); 			break;

			case 3: printf("Enter the register number to search: ");
					scanf("%d",&regno);
					getchar();

					addRegno(L,getStudent(),regno);		break;

			case 4: printf("Enter the name to search: ");
					scanf("%[^\n]",name);
					getchar();
					searchName(L,name);					break;

			case 5: printf("Enter the register number to search: ");
					scanf("%d",&regno);
					getchar();

					deleteRecord(L,regno);				break;


			case 6: putList(L);							break;

			case 7: printf("Enter the register number to search: ");
					scanf("%d",&regno);
					getchar();

					putPrevNext(L,regno);				break;

			case 8: stop = 1;							break;

			default:printf("Invalid Input!\n");			break;
		}
        printf("Press any key to continue......");
        getchar();
	}

	free(L -> array);
	free(L);
	return 0;
}
