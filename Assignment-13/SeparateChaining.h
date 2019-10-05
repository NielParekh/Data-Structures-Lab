#define MAX 5

struct Record{
	int data;
	struct Record *link;
};

int hash_function(int key){	
	return (key % MAX);	
}


int search_element(int key, struct Record *hash_table[]){
	int h;
	struct Record *ptr;
	h = hash_function(key); 
	ptr = hash_table[h]; 
	while(ptr != NULL){
		if(ptr->data == key)
			return h;
	
		ptr = ptr->link;
	}
	return -1;
}


void insert(int id, struct Record *hash_table[]){
	int key, h;
	struct Record *temp; 
	key = id;
	if(search_element(key, hash_table) != -1) {
		printf("Duplicate Key\n"); return;
	}
	h = hash_function(key);
	temp = malloc(sizeof(struct Record)); 
	temp->data = id;
	temp->link = hash_table[h]; 
	hash_table[h] = temp;
}

void show(struct Record *hash_table[]){	
	int count;
	struct Record *ptr;
	for(count = 0; count < MAX; count++){
		printf("\n[%3d]", count);
		if(hash_table[count] != NULL){
			ptr = hash_table[count]; 
			while(ptr != NULL){	
				printf("  %d  ", ptr->data); 
				ptr=ptr->link;
			}
		}
	}
	printf("\n");
}


void remove_record(int key, struct Record *hash_table[]){
	int h;
	struct Record *temp, *ptr; h = hash_function(key); 

	if(hash_table[h]==NULL){
		printf("Key %d Not Found\n", key); 
		return;
	}
	
	if(hash_table[h]->data == key){	
		temp = hash_table[h]; 
		hash_table[h] = hash_table[h]->link; 
		free(temp);
		return;
	}
	ptr = hash_table[h]; 
	while(ptr->link != NULL){
		if(ptr->link->data == key){
			temp = ptr->link;
			ptr->link = temp->link; free(temp);
			return;
		}
		ptr = ptr->link;
	}
	printf("Key %d Not Found\n", key);
}

