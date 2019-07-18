
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Prototypes.h"
#include "Definitions.h"

int main(){
	Node * head = createEmptyList(),
		 * tail = head -> next;

	int opt = 0;
	char name[30];


	while(opt != 7){
		system("clear");
		printf("1 - Add First\n2 - Add last\n3 - Add after Record\n4 - Display List\n");
		printf("5 - Display in alphabetical order\n6 - Delete Record\n7 - Stop\n");
		printf("Enter your choice: ");
		scanf("%d",&opt);
		getchar();

		switch(opt){
			case 1: addFirst(head,tail,getStudent());	break;
			case 2: addLast(head,tail,getStudent());    break;
			case 3: printf("Enter the name to search: ");
					scanf("%[^\n]",name);
					addName(findRecord(head,tail,name),getStudent());
					break;

			case 4: putList(head,tail);		     		break;
			case 5: putListSorted(head,tail);           break;

			case 6: printf("Enter the name to search: ");
					scanf("%[^\n]",name);
					getchar();
					deleteRecord(findRecord(head,tail,name));
					break;
			case 7: 									break;
			default: printf("Invalid input!\n");        break; 
		}
		printf("Press any key to continue.......");
		getchar();
	}

	return 0;
}