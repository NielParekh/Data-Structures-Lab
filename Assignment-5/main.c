#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "stack.h"
#include "Functions.h"

int main(){
	char infix[50] = {0},
		 postfix[50] = {0},
		 buffer[20];

	Stack opStack = createEmptyStack();

	int val;

	printf("Enter the infix expression: ");
	scanf("%[^\n]",infix);

	for(int i = 0 ; infix[i]; i++){

		if(isdigit( infix[i]) ){
			postfix[strlen(postfix)] = infix[i];
			for(int j = i + 1 ; isdigit(infix[j]) && infix[j] ; j++){
				i = j;
				postfix[strlen(postfix)] = infix[j];
			}
			postfix[strlen(postfix)] = ' ';
		}
		
		else if(isOpenBracket(infix[i])) 
			push(&opStack,(float)infix[i] );
		
		else if(isOperator(infix[i])){
			if(isEmpty(opStack))
				push(&opStack,(float)infix[i] );
			else{
				Data tmp = peek(opStack);
				while(getPriority( (char)tmp ) >= getPriority(infix[i]) ){
					postfix[strlen(postfix)] = (char)tmp;
					postfix[strlen(postfix)] = ' ';
					pop(&opStack);
					if(!isEmpty(opStack))
						tmp = peek(opStack);
					else 
						break;
				}

				push(&opStack,(float)infix[i] );
			}
		}
		
		else if(isClosingBracket(infix[i]) ){
			if(isEmpty(opStack)){
				printf("Error in expression: Unbalanced brackets!\n");
				return 1;
			}
			Data tmp = peek(opStack);
			while(!isOpenBracket( (char)tmp ) ){
				postfix[strlen(postfix)] = (char)tmp;
				postfix[strlen(postfix)] = ' ';
					
				pop(&opStack);
				
				if(isEmpty(opStack)){
					printf("Error in expression: Unbalanced brackets!\n");
					return 1;
				}

				tmp = peek(opStack);
			}
			pop(&opStack);
		}
		else continue; //It is a whitespace character			
	}

	//If the Operator Stack isn't empty, append all operators to postfix
	while(!isEmpty(opStack)){
		Data tmp = pop(&opStack);
		if(isOpenBracket( (char)tmp) ){
			printf("Error in expression: Unbalanced brackets!\n");
			return 1;
		}
		postfix[strlen(postfix)] = (char)tmp;
		postfix[strlen(postfix)] = ' ';		
	}


	printf("Postfix Expression: %s\n",postfix);
		
	
	Stack eval = createEmptyStack();
	Data tmp;

	for(int i = 0  ; postfix[i] ; i++){
		tmp = 0;
		if(isdigit(postfix[i])){
			tmp = (float)(postfix[i] - '0');
			for(int j = i + 1 ; isdigit(postfix[j]) && postfix[j];j++){
				tmp = (tmp * 10) + (float)(postfix[j] - '0');
				i = j; 
			}
			push(&eval,tmp);
		}
		else if(isOperator( postfix[i]) ){
			Data v2 = pop(&eval),
				 v1 = pop(&eval);
			float res;

			char c = postfix[i];
			switch(c){
				case '+': res = v1 + v2; break;
				case '-': res = v1 - v2; break;
				case '*': res = v1 * v2; break;
				case '/': res = v1 / v2; break;
			}
			push(&eval,res);
		}
		else continue;//Whitespace Character
	}

	printf("Final value : %.3f\n",eval->d);
	
	printf("\n");
}
