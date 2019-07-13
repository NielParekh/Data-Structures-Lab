extern void SelectionSort(int[],const int);
extern void Display(const int[],const int);

int BinarySearch(int arr[],const int size){
	int x;
	printf("Enter the number to search for: ");
	scanf("%d",&x);

	int rVal = -1; 	//Return Value

	//Sorting before binary search
	SelectionSort(arr,size);
	Display(arr,size);

	int left = 0 , right = size - 1,middle;

	while(left<=right){
		middle = (left + right)/2;
		
		if(arr[middle] == x){
			rVal = middle;
			break;
		}

		else if(x>arr[middle])
			left = middle + 1;
		else
			right  = middle - 1;
	}

	return rVal;
}	
