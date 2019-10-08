#define MAX_ROOMS 3

typedef struct{
	int rno;
	Date Check_In , Check_Out;
	unsigned isOccupied : 1;
	unsigned int cust_id;
} Room;

void CreateRoom(Room * Rptr){
	Rptr->rno = 0;
	CreateDate(&(Rptr->Check_In) );
	CreateDate(&(Rptr->Check_Out) );
	Rptr->isOccupied = 0;
}


void DisplayAvailableRooms(int * arr){

	if(arr == 0){
		printf("No rooms available!\n");
		return;
	}

	printf("The available rooms are: \n");
	for(int i = 0 ; i < MAX_ROOMS && arr[i] ; i++){
		printf("%-3d ",arr[i]);
		if( (i+1)%10 == 0)
			printf("\n");
	}

}



int* const getRoomNo(){
	
	static int arr[MAX_ROOMS];
	for(int i = 0 ; i < MAX_ROOMS ; i++)
		arr[i] = 0;
	
	FILE * fp = fopen("Rooms.dat","rb");
	
	int c = -1;
	Room tmp;
	fread(&tmp,1,sizeof(Room),fp);
	while(!feof(fp) && c < MAX_ROOMS){
		if( !tmp.isOccupied)
			arr[++c] = tmp.rno;
		
		fread(&tmp,1,sizeof(Room),fp);
	}
		
		
	fclose(fp);
	
	if(c != -1) //Some rooms available
		return arr;
return 0;
}

Room Book_Room(){
	Room tmp;
	CreateRoom(&tmp);

	const Date Current_Date = getCurrentDate();
	
	int rno , found = 0;

	int * available_rno = getRoomNo();
	
	if(available_rno == 0)
		return tmp;
	
	DisplayAvailableRooms(available_rno);

	printf("\n");
	
	do{
		printf("Enter a rno from the above list: ");
		scanf("%d",&rno);
		getchar();

		for(int i = 0 ; i < MAX_ROOMS && available_rno[i]; i++)
			if(rno == available_rno[i]){
				found = 1;
				break;
			}
		if(!found)
			printf("Enter another room number!\n");

	}while(!found);
			
	tmp.rno = rno;
	tmp.isOccupied = 1;

	
	do{
		getDate("Check In" , &(tmp.Check_In)  , Current_Date);
		getDate("Check Out", &(tmp.Check_Out) , Current_Date);

		if(date_diff( (tmp.Check_In),(tmp.Check_Out) ) > 0 ||
		   date_diff( (tmp.Check_In),Current_Date ) != 0)
			printf("Invalid Check In Check Out Dates!Try again!\n\n");

	}while(date_diff( (tmp.Check_In),(tmp.Check_Out) ) > 0 ||
		   date_diff( (tmp.Check_In),Current_Date ) != 0);
	
	return tmp;
}

