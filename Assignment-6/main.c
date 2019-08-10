#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main(){
	Queue f1 = 0,
	      f2 = 0,
	      r1 = 0 ,
	      r2 = 0;

	Node tmp;
	int stop = 0,
		time1 = 0,
		time2 = 0;

	while(!stop){
		printf("Enter the Job details: ");
		scanf("%s",tmp.jno);
		scanf("%d",&tmp.bt);

		time1 = getWaitTime(f1,r1);
		time2 = getWaitTime(f2,r2);

		if(time1 <= time2)
			enqueue(&f1,&r1,tmp.jno,tmp.bt);
		else
			enqueue(&f2,&r2,tmp.jno,tmp.bt);

		printf("Do you want to stop 1/0? ");
		scanf("%d",&stop);
	}

	printf("Queue1:\n");
	displayQueue(f1,r1);
	printf("\nAverage Waiting Time in Q1 : %f\n",getAvgWaitTime(f1,r1));
	printf("--------------------------\n");
	printf("Queue2:\n");
	displayQueue(f2,r2);
	printf("\nAverage Waiting Time in Q2 : %f\n",getAvgWaitTime(f2,r2));

}