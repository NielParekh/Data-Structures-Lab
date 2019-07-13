#include <stdio.h>
#include "binary_search.h"
#include "linear_search.h"
#include "bubble_sort.h"
#include "selection_sort.h"

void Display(const int[],const int);

int main(void){
	int arr[50],n,tmp,stop = 0,opt,index;

	while(stop == 0){
		printf("Enter the number of elements in the array: ");
		scanf("%d", &n);

		printf("Enter all the elements: ");

		for(int i = 0 ; i < n ; i++)
			scanf("%d",&arr[i]);

		printf("1 - Selection Sort\n2 - Bubble Sort\n3 - Linear Search\n4 - Binary Search\nEnter your choice: ");
		scanf("%d",&opt);

		switch(opt){
			case 1: SelectionSort(arr,n);
					Display(arr,n);
					break;
			case 2: BubbleSort(arr,n);
					Display(arr,n);
					break;
			case 3: index = LinearSearch(arr,n);
					if(index != -1)
						printf("Element found at index: %d\n",index);
					else
						printf("Element not found!\n");
					break;
			case 4: index = BinarySearch(arr,n);
					if(index != -1)
						printf("Element found at index: %d\n",index);
					else
						printf("Element not found!\n");
					break;
			
			default:printf("Invalid Input!Try again!\n");
		}

		printf("Do you want to stop 1/0: ");
		scanf("%d",&stop);
	}
}


void Display(const int arr[],const int size){
	printf("Contents of array: ");
	for(int i = 0 ; i < size ; i++)
		printf("%-3d  ",arr[i]);
	printf("\n\n\n");
}