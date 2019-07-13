void SelectionSort(int arr[] , const int size){
	int min_pos,tmp;
	for(int i = 0 ; i < size ; i++ ){
		min_pos = i;
		for(int j = i + 1 ; j < size ; j++)
			if( arr[j] < arr[min_pos])
				min_pos = j;
		//Swapping minimum with arr[i]
		tmp = arr[i];
		arr[i] = arr[min_pos];
		arr[min_pos] = tmp;
	}
}