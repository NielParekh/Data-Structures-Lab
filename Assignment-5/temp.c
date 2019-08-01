#include <stdio.h>
#include <stdlib.h>


#include "stack.h"
#include "Functions.h"

int main(){
	Stack s = createEmptyStack();
	int x = 10,y = 20;
	push(&s,Operand,(void*)&x);
	push(&s,Operand,(void*)&y);

	displayStack(s);
}