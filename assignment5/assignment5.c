/*
 * assignment5.c
 * SpellCheck
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
#include <stdlib.h>

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helfpul. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I strongly encourage you to avoid big functions
 * (while there are always exceptions, a good rule of thumb is about 15 lines in a function).
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */

//TODO:
int ASCII2Int(char c);
int isUpperCase(char c);
int isLowerCase(char c);
int isAlphabet(char c);
int valid(char c);
void spellCheck(char article[], char dictionary[]) {
	char word[50] = { 0 };
	int word_index = 0;		//indexes for arrays
	int dict_index = 0;
	int art_index = 0;
	int done = 0;
	int i = 0;
	int match = 0;
	int match_count = 0;
	//how the fuck do i track outputs?????**************************
	//	probs just make linked list/ sequential(array) through memory allocation on heap, read up on this during bus trip
	
	while (1) {
		while ((isAlphabet(article[art_index]) && isAlphabet(article[art_index+1])) == 0 && (article[art_index] != 0)) { //will break if two letters found sequentially or if end or artile detected
			art_index++;
		}
		if (article[art_index] == 0) {		//see if end of article reached (null value)
			getchar();
			return;
		}
		word_index = 0;
		for (i = 0;  i< 50; i++){
			word[i] = 0;
		}
		while ((valid(article[art_index]) == 1)) {				//store characters from word into array for dict. comparison process
			word[word_index] = ASCII2Int(article[art_index]);	//convert letters to alphabet indexes for non-case sensitive comparison with dictionary
			word_index++;
			art_index++;
		}														//break when no more alpha characters
		word[word_index] = '\n';								//stick newline at end of word to make dictionary comparison easier to match up and to print result if not in dictionary
		match_count = word_index;
		word_index = 0;
		dict_index = 0;
		while ((dict_index != 0) && (match == 0)) {
			
			if (ASCII2Int(dictionary[dict_index])!= word[word_index]){
				for (; dictionary[dict_index] != '\n'; dict_index++) {}
				dict_index++;
			}
		}
	}
	getchar();
}
int valid(char c) {
	if (isAlphabet(c) == 1) {
		return 1;
	}
	if (c == 0x27) {			//apostrophe (')
		return 1;
	}
	if (c == 0x2D) {
		return 1;
	}
	else {
		return 0;
	}
}
int isUpperCase(char c) {
	if (c >= 'A' && c <= 'Z') {
		return 1;
	}
	else {
		return 0;
	}
}
int isLowerCase(char c) {
	if (c >= 'a' && c <= 'z') {
		return 1;
	}
	else {
		return 0;
	}
}
int isAlphabet(char c) {
	return isUpperCase(c) || isLowerCase(c);
}
int ASCII2Int(char c) {
	if (isUpperCase(c)) {
		return c - 'A';
	}
	else if (isLowerCase(c)) {
		return c - 'a';
	}
	else {
		return -1;
	}
}



