#include <stdio.h>
void parentheses(int n, int current, int left, int right, int i);

void generateAllMatchedParens(int n){
	int i = 0;							//intitialization variable to reset parenArr when the function is called the first time
	int current = 0;					//can hold up to n=100 matched parentheses, used to keep track of position and also print out permutations
	int left = 0;						//keeps track of left parentheses
	int right = 0;						//keeps track of right parentheses
	if (n <= 0) {						//if n is zero, nothing to print, return
		return;
	}
	else {
		parentheses(n, current, left, right, i);	//call recursive function to print out matched parentheses permutations
	}
	return;
	
	//First attempt to try without reursion, only prints cobinations not permutations
	/*int left = 0;
	int right = 0;
	int alt = 0;
	int i = 0;
	int j = n;
	if (n == 0) {
	return;
	}
	else {
	for (i = 0; i < n; i++) {
	for (left = 1; left < j; left++) {
	printf("(");
	}
	for (alt = i; alt >= 0; alt--) {
	printf("()");
	}
	for (right = 1; right < j; right++) {
	printf(")");
	}
	j--;
	printf("\n");
	}
	return;
	}*/
}
void parentheses(int n, int current, int left, int right, int i) {		//subfunction tht is recursively called to print matched pair parentheses permutations
	static char parenArr[200];											//static array to hold up to n=100 matched parentheses
	if (i == 0) {														//if called the first time reset the static parenArr to print out new n matched parenthess permutations
		for (i = 0; i < 200; i++) {
			parenArr[i] = 0;
		}
	}
	if(right!=n){														//first try to print left parentheses, then try to match right parenthesis
		if (left > right){
			parenArr[current] = ')';									//update array
			parentheses(n, current+1, left, right+1, i);				//call function with updated values
		}		
		if (left < n){
			parenArr[current] = '(';
			parentheses(n, current+1, left+1, right, i);				//call function with updated values
		}
	}
	else {																//base case: when right parentheses is equal to n, no more parentheses to print out, print paren char array
		printf("%s \n", parenArr);										//if base case reached print completed array of matched parentheses
		return;															//return back through recursive function path
	}
}
void generateAllPalindromicDecompositions(char str[]){
	//opted not to do this function, had a test to study for sorry :(
	return;
}