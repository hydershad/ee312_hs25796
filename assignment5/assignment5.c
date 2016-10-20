/*HYDER SHAD
UT EID: hs25796
TA: NOLAN CORCORAN
FALL 2016 EE312 - BARBER
F 3-4 RECITATION
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

//TO DO:
int ASCII2Int(char c);
int isUpperCase(char c);
int isLowerCase(char c);
int isAlphabet(char c);

void spellCheck(char article[], char dictionary[]) {
	char word[50] = { 0 };			//holds alphabet index (ASCII2Int) value of word alphabets (eliminates cases matching problems)
	char printword[50] = { 0 };		//duplicate array to print original word if not in dictionary
	int word_index = 0;				//indexes for arrays
	int dict_index = 0;				//moves through dictionary array
	int art_index = 0;				//moves through article			
	int i = 0;						//junk index for for loops, helps to reset word arrays
	int match = 0;
	//probs just make linked list/ sequential(array) through memory allocation on heap, read up on this during bus trip
	
	while (1) {
		while (((isAlphabet(article[art_index]) && isAlphabet(article[art_index+1])) == 0) && (article[art_index] != 0)) { //will break if two letters found sequentially (if a word is found) or if end or artile detected
			art_index++;
		}
		if (article[art_index] == 0) {	 //see if end of article reached (null value)
			//insert getchar(); here for debugging or to see output easily
			return;		//return to caller program
		}
		word_index = 0;
		for (i = 0;  i< 50; i++) {		//resets word/printword arrays for new word
			word[i] = 0;
			printword[i] = 0;
		}
		while ((isAlphabet(article[art_index]) == 1)) {				//store characters from word into array for dict. comparison process
			word[word_index] = ASCII2Int(article[art_index]);	//convert letters to alphabet indexes for non-case sensitive comparison with dictionary
			printword[word_index] = article[art_index];
			word_index++;
			art_index++;
		}														//break when no more alpha characters
		word[word_index] = '\n';								//stick newline at end of word to make dictionary comparison easier to match up and to print result if not in dictionary
		printword[word_index] = '\n';
		word_index = 0;											//reset indexes for comparison
		dict_index = 0;
		match = 0;
		while ((dictionary[dict_index] != 0) && (match == 0)) {
			if (ASCII2Int(dictionary[dict_index])!= word[word_index]) {	//skips to next word if mismatch
				for (; dictionary[dict_index] != '\n'; dict_index++) {
					if (dictionary[dict_index] == 0) { break; }
				}
				dict_index++;											//moves past newline character
			}
			if (ASCII2Int(dictionary[dict_index]) == word[word_index]) {
				while (ASCII2Int(dictionary[dict_index]) == word[word_index]) {		//whle dictionary and captured word match
					dict_index++;
					word_index++;
				}
				if ((dictionary[dict_index] == '\n') && (printword[word_index] == '\n')) {	 //if they match perfectly then set match = 1 and exit, do nothing
					match = 1;
				}
				else { word_index = 0; }	//if not a match, reset word index and try with mext word in dictionary until a match found or end of dictionary reached
			}
		}
		if ((dictionary[dict_index] == 0) && (match == 0)) {	//if end of dictioanry reached and no matches print out the word
			printf("%s", printword);
		}
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
	if (isLowerCase(c)) {
		return c - 'a';
	}
	if (c == 0x2D) {
		return 0x2D;
	}
	if (c == 0x27) {
		return 0x27;
	}
	else {
		return -1;
	}
}