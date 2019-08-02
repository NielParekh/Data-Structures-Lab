int isOperator(const char c){
	if( c == '+' || c == '-' || c == '*' || c == '/' )
		return 1;

	return 0;
}

int isOpenBracket(const char c){
	if(c == '{' || c == '(' || c == '[')
		return 1;

	return 0;
}

int isClosingBracket(const char c){
	if(c == ')' || c == ']' || c == '}')
		return 1;

	return 0;
}

int getPriority(const char c){
	int rval = -1;
	switch(c){
		case '(' : rval = 0;  break;
		case '-' : 
		case '+' : rval = 1;  break;
		case '*' : 
		case '/' : rval = 2;  break;
		/*case '-' : rval = 1;  break;
		case '-' : rval = 1;  break;
		case '-' : rval = 1;  break;
		case '-' : rval = 1;  break;
		*/	
	}

	return rval;
}