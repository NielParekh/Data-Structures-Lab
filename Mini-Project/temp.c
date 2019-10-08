#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "class_date.h"
#include "class_room.h"
#include "class_customer.h"
#include "class_login.h"
#define MAX_ROOMS 3
int main(){
	
	Room tmp;
	CreateRoom(&tmp);
	CreateDate(&(tmp.Check_In));
	CreateDate(&(tmp.Check_Out));
	
	FILE * f = fopen("Rooms.dat","wb");
	for(int i = 0 ; i < MAX_ROOMS ; i++){
		tmp.rno = i + 1;
		fwrite(&tmp,1,sizeof(Room),f);
	}
	fclose(f);
	/*
	FILE * f = fopen("Rooms.dat","rb");
	fread(&tmp,1,sizeof(Room),f);
	while(!feof(f)){
		printf("RNO :%d\nIS OCU:%d\nCUST ID: %d",tmp.rno,tmp.isOccupied,tmp.cust_id);
		putDate("Check In : ",tmp.Check_In);
		putDate("Check out: ",tmp.Check_Out);
		fread(&tmp,1,sizeof(Room),f);
	}
	fclose(f);
	*/

	DisplayAvailableRooms(getRoomNo());
	
}
