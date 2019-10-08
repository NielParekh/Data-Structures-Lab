#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "class_date.h"
#include "class_room.h"
#include "class_customer.h"
#include "class_login.h"
#include "AVLTree.h"
#include "MaxHeap.h"

void Pause(){
	printf("\nPress any key to continue.........\n");
	getchar();
}

void main(){
	struct login x = {"","",0};
	int choice;
	FILE *id;
	char user[10],password[25];


	do{
		system("clear");
		printf("\n1. Administrator\n2. Customer\n3. Exit\nEnter your choice: ");
		scanf("%d",&choice);
		getchar();

		if(choice==1){
			
			if(!x.verified){
				printf("Enter the username : ");
				scanf("%s",user);
				getchar();
			
				strcpy(password,getpass("Enter the password: "));
			
				id=fopen("id.bin","rb");
				fread(&x,1,sizeof(x),id);
				fclose(id);

				if(strcmp(x.username,user)==0 && strcmp(x.pass,password)==0){
					printf("\nAccess Granted\n");
					x.verified = 1;
					Pause();
				}
				else{
					printf("\nWrong password or username\n");
					Pause();
					continue;
				}
			}
			
			do{
				system("clear");
				printf("\n1. List of available rooms\n2. Bill generator\n");
				printf("3. History of a room\n4. Rooms to vacate today\n");
				printf("5. Date wise History\n6. Logout\nEnter your choice: ");
				scanf("%d",&choice);
				getchar();

				system("clear");
				float amount;
				switch(choice){
					case 1 : DisplayAvailableRooms(getRoomNo());    Pause(); break;
					case 2 : amount = CheckOut();
					         if(amount != -1) 
					         	printf("\nAmount to be paid: %.2f\n",amount);
					         	                                    Pause(); break;
					case 3 : Room_History();						Pause(); break;
					case 4 : getCheckOut();							Pause(); break; 
					case 5 : Date_History();						Pause(); break;
					case 6 : printf("\nLogged out successfully!\n");
							 x.verified = 0;						Pause(); break;
					default: printf("\nInvalid Input!Try again!\n");Pause(); break;
				}

			}while(choice!=6);
			choice  = -1;
		}



		else if(choice==2){

			system("clear");
			printf("WELCOME TO HOTEL CALIFORNIA \n");
			printf("\n1. Check in\n2. Check out\n3. Check availabile rooms\nEnter your choice: ");
			scanf("%d",&choice);
			getchar();

			system("clear");
			switch(choice){
				case 1 : CheckIn();							  Pause();  break;
				case 2 : printf("Contact Admin!\n");  	  	  Pause();  break;
				case 3 : DisplayAvailableRooms(getRoomNo());  Pause();  break;
				default: printf("\nInvalid Input!Try again!\n");Pause();break;
			}
			choice = -1;
		}

		else if(choice==3){
			printf("\nExiting............................................\n");
		}
		else{
			printf("\nPlease enter a valid option\nPress any key to continue\n");
			getchar();
		}
	}while(choice!=3);	
}
		
		
