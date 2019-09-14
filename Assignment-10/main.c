#include <stdio.h>
#include <stdlib.h>

#include "Employee.h"
#include "MaxHeap.h"

int main(void){
	PQueue q = createPQueue(10);

	for(int i = 0 ; i < 5 ; i++){
		enqueue(q,getEmployee());
		printf("Queue after adding: \n");
		display(q);
		printf("------------------------\n");
	}
	

	printf("De-Queued Element\n");
	putEmployee(dequeue(q));

}