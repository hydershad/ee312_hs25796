/*
ASSIGNMENT #3
Lab3.c written by HYDER SHAD
UT EID: hs25796
FALL 2016 EE 312 - BARBER
TA: NOLAN CORCORAN
9/24/2016
*/

#include <stdio.h>

/*
* return 1 if the ASCII interpretation of
* c is an upper case letter.
* return 0 otherwise
*/
int isUpperCase(char c) {
	if (c >= 'A' && c <= 'Z') {
		return 1;
	}
	else {
		return 0;
	}
}

/*
* return 1 if the ASCII interpretation of
* c is a lower case letter.
* return 0 otherwise
*/
int isLowerCase(char c) {
	if (c >= 'a' && c <= 'z') {
		return 1;
	}
	else {
		return 0;
	}
}

/*
* return 1 c is an Alphabet.
* return 0 otherwise
*/
int isAlphabet(char c) {
	return isUpperCase(c) || isLowerCase(c);
}

/*
* if the ASCII interpretation of c is a letter, then
* return a number between 0 and 25 indicating which letter of
* the alphabet c represents.  For example, if c is the ASCII
* encoding for 'A', then we should return 0.  If c is the
* ASCII encoding for 'e', then we should return 4.
* if the ASCII interpretation of c is not a letter, then
* return -1.
*/
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

/*
* assumes i is between 0 and 25 inclusive
*/
char int2UpperCase(int i) {
	char c = 'A' + i;
	return c;
}

/*
* assumes i is between 0 and 25 inclusive
*/
char int2LowerCase(int i) {
	char c = 'a' + i;
	return c;
}

/*
* This function takes in a message and computes the frequencies of all the alphabets
*/
void buildHistogram(char message[], int messageLength, int histogram[], int histogramLength) {
	int his_pos = 0;		//these variable are used to ensure if more than one letter is the most frequent, the one which appears first in
	int mes_pos = 0;		//the message sequence is considered the most frequent
	int mes_value = 0;
	int max_index = 0;
	int max_val = 0;
	int flag = 0;
	
	int i = 0;
	int index = 0;
	for (i = 0; i < messageLength; i++) {
		if (isAlphabet(message[i]) == 1) {		//if message character is alphabet, add 1 to its count tally
			index = ASCII2Int(message[i]);
			histogram[index] +=1;
		}
	}
	for (his_pos = 0; his_pos < histogramLength; his_pos++) {
		if (histogram[his_pos] > max_val) {
				max_val = histogram[his_pos];
				max_index = his_pos;
			}

			if (histogram[his_pos] == max_val) {	//in event of tie, find out which letter appears in message first
				flag = 0;
				mes_pos = 0;
				while ((mes_pos < messageLength) && (flag == 0)) {	//cycle through message to see which of the two letters appears first
	
					if ((isAlphabet(message[mes_pos])) == 1) {
						mes_value = ASCII2Int(message[mes_pos]);
						if (mes_value == max_index) {
							flag = 1;
						}
						if (mes_value == his_pos) {
							max_index = his_pos;
							flag = 1;
						}
					}
					mes_pos++;
				}
			}
		}
	histogram[max_index] = histogram[max_index] + 1; //ensures the letter which appears most frequently, whether out right 
													 //or by order in which it appears, is the designated most frequent
}

/*
* This function computes the maximum value in an array and returns the index location\
* for which the maximum value occured
*/

int maxIndex(int myArray[], int arrayLength) {
	int max_val = 0;
	int max_index = 0;
	int i = 0;
	for (i = 0; i < arrayLength; i++) {
		if (myArray[i] > max_val) {			//finds maximum value from histogram, buildHistogram function ensures no ties for largest array value
			max_val = myArray[i];
			max_index = i;
		}
	}
	return max_index;
}

/*
* Encrypt the string s using the rotation cypher
* Each letter in s should be shifted "shift" letters to the
* right.  For example, if "shift" is 2, then "a zebra" should be
* changed to "c bgdtc".  Note that when shifting past the end
* of the alphabet, we wrap around again to a.
*
* Only change the letters in s.  Do not change spaces, punctuation
* or numbers in s.
* For full credit, you should keep upper case letters as
* upper case, and leave lower case letters as lower case.  So, if
* s had been the string "a ZeBra", you should change s to be
* "c BgDtc".
*/
void encrypt(char message[], int messageLength, int shift) {
	int i = 0; //counter

	for (i = 0; i < messageLength; i++) {

		if (isLowerCase(message[i]) == 1) {
			message[i] = int2LowerCase((ASCII2Int(message[i]) + shift) % 26);	//converts alphabet charactr into 0-26, adds shift using modulus for wrap 
																				//around, converts back to alphabet
		}
		if (isUpperCase(message[i]) == 1) {
			message[i] = int2UpperCase((ASCII2Int(message[i]) + shift) % 26);
		}
}		
	return;
}

/*
* return a number between 0 and 25 indicating which letter
* of the alphabet is most common in the string s
*/
int mostFrequentLetter(char message[], int messageLength) {
	/*
	* Build the histogram and get the index of most frequent alphabet
	*/
	int frequent = 0;
	int histogram[26] = { 0 };		//histogram keeps track of letter occurences
	buildHistogram(message, messageLength, histogram, 26);
	frequent = maxIndex(histogram, 26);		//finds maximum value from histogram, buildHistogram function ensures no ties for largest array value
	return frequent;
}

void decrypt(char cypher[], int cypherLength, int common) {

	int crypt_frequent = 0;
	int decrypt_shift = 0;
	crypt_frequent = mostFrequentLetter(cypher, cypherLength);	//finds most frequent letter in encrypted message by calling buildHistogram and maxIndex functions
	decrypt_shift = ((common - crypt_frequent)+26)%26;	//shift required to decrypt the message based on original and encrypted most common letters
	encrypt(cypher, cypherLength, decrypt_shift);		//decrypt message using the same encryption algorithim by providing the decryption shift to arrive at original message
}
