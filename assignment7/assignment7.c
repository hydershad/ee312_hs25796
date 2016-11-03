#include <stdio.h>

void generateAllMatchedParens(int n){
	int left = 0;
	int right = 0;
	int alt = 0;
	int i = 0;
	int j = n;

	if(n==0){
		return;
	}
	else {
		for (i = 0; i < n; i++) {
			for (left = 1; left < j; left++) {
				printf("(");
			}
			for (alt = i; alt >=0 ; alt--) {
				printf("()");
			}
			for (right = 1; right < j; right++) {
				printf(")");
			}
			j--;
			printf("\n");
		}
		return;
	}
	
	//Function needs to generate all matched parens as described in the assignment
}

void generateAllPalindromicDecompositions(char str[]){
	
}