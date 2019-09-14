typedef struct Employee{
	char name[30];
	int id;
	float salary;
}Employee;

Employee getEmployee(){
	Employee e;

	printf("Enter the name   : ");
	scanf("%[^\n]",e.name);
	printf("Enter the id     : ");
	scanf("%d",&e.id);
	printf("Enter the salary : ");
	scanf("%f",&e.salary);
	getchar();
	printf("\n");
	return e;
}

void putEmployee(const Employee e){
	printf("Name     : %s\n",e.name);
	printf("ID       : %d\n",e.id);
	printf("Salary   : %.2f\n",e.salary);
}



