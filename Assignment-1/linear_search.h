int LinearSearch(const int arr[],const int size){
	int x;
	printf("Enter the number to search for: ");
	scanf("%d",&x);

	int rVal = -1; 	//Return Value

	for(int i = 0 ; i < size ; i++)
		if(arr[i] == x){
			rVal = i;
			break;
		}

	return rVal;
}

