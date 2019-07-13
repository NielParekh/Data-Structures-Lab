void BubbleSort(int arr[],const int size){
	int tmp;
	for(int i = 0 ; i < size ; i++ )
		for(int j = i + 1 ; j < size ; j++)
			if(arr[j] < arr[i]){
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}

}

