#define MAX_ROOMS 3

extern Record* search(AVLTree t,int rno);


void CreateRoom(Room * Rptr){
	Rptr->rno = 0;
	CreateDate(&(Rptr->Check_In) );
	CreateDate(&(Rptr->Check_Out) );
	Rptr->isOccupied = 0;
	Rptr->cust_id = 0
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


int * const getRoomNo(AVLTree t){
	static int arr[MAX_ROOMS];
	for(int i = 0 ; i < MAX_ROOMS ; i++)
		arr[i] = 0;
    int c = -1;


    Room * tmp = 0;
    for(int i = 1 ; i <= MAX_ROOMS ; i++){
        tmp = search(t,i);
        if(tmp)                       //Room exists
            if(tmp -> isOccupied == 0) //Room available
                arr[++c] = tmp -> rno;
    }
	if(c != -1) //Some rooms available
		return arr;
return 0;
}

Room* Book_Room(AVLTree t){
	Room * tmp = 0;

	const Date Current_Date = getCurrentDate();

	int rno , found = 0;

	int * available_rno = getRoomNo(t);

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

	tmp = search(t,rno);

	tmp -> isOccupied = 1;


	do{
		getDate("Check In" , &(tmp -> Check_In)  , Current_Date);
		getDate("Check Out", &(tmp -> Check_Out) , Current_Date);

		if(datecmp( (tmp -> Check_In),(tmp -> Check_Out) )  == 1 ||
		   datecmp( (tmp -> Check_In),Current_Date ) == -1)
			printf("Invalid Check In Check Out Dates!Try again!\n\n");

	}while(datecmp( (tmp -> Check_In),(tmp -> Check_Out) ) == 1 ||
		   datecmp( (tmp -> Check_In),Current_Date ) == -1);

	return tmp;
}

