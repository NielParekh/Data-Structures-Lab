#include <stdio.h> 
#include <stdlib.h> 
#include "SeparateChaining.h"

int main(){
	struct Record *hash_table[MAX]; 
	int count, key, option,id;

	for(count = 0; count <= MAX - 1; count++)
	{		hash_table[count] = NULL;	}
	while(1){	
		printf("\n");
		printf("1. Insert a Record in Hash Table\n"); 
		printf("2. Search for a Record\n"); 
		printf("3. Delete a Record\n");
		printf("4. Show Hash Table\n"); 
		printf("5. Quit\n"); printf("Enter your option: "); 
		scanf("%d",&option); 
		switch(option)
		{
			case 1: {
				printf("Enter the number: "); 
				scanf("%d", &id);
				insert(id, hash_table);
			} break;
			case 2: {
				printf("Enter the element to search: ");
				scanf("%d", &key);
				count = search_element(key, hash_table); 
				if(count == -1)
					printf("Element Not Found\n");				
				else
					printf("Element Found in Chain with Key : %d\n", count); 
			} break; 
			case 3: {
				printf("Enter the element to delete: "); 
				scanf("%d", &key);
				remove_record(key, hash_table); 
			} break;
			case 4:	show(hash_table); break;
			case 5:	exit(1);
			default : printf("Wronf option.");
		}
	}
return 0;
}


/*
OUTPUT:
(base) avinash@avinash-HP:~/Desktop/C$ gcc Ex13.c -o a
(base) avinash@avinash-HP:~/Desktop/C$ ./a

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 1
Enter the number: 5

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 1
Enter the number: 6

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 4

[  0]  5  
[  1]  6  
[  2]
[  3]
[  4]

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 1
Enter the number: 4

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 1
Enter the number: 3

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 1
Enter the number: 2

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 1
Enter the number: 1

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 4

[  0]  5  
[  1]  1    6  
[  2]  2  
[  3]  3  
[  4]  4  

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 3
Enter the element to delete: 1

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 4

[  0]  5  
[  1]  6  
[  2]  2  
[  3]  3  
[  4]  4  

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 
2
Enter the element to search: 3
Element Found in Chain with Key :	3

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 5
*/

//2.
/*
OUTPUT:
(base) avinash@avinash-HP:~/Desktop/C$ gcc Ex13.c -o a
(base) avinash@avinash-HP:~/Desktop/C$ ./a

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 1
Enter the string:	abcdef

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 4

[ 38]  abcdef  

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 1
Enter the string:	bcdefa

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 1
Enter the string:	cdefab

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 1
Enter the string:	defabc

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 4

[ 11]  defabc  
[ 14]  cdefab  
[ 23]  bcdefa  
[ 38]  abcdef  

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 2
Enter the element to search:	abcdef
Element Found in Chain:	38

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 3
Enter the element to delete:	axyz
Key axyz Not Found

1. Insert a Record in Hash Table
2. Search for a Record
3. Delete a Record
4. Show Hash Table
5. Quit
Enter your option: 5
*/