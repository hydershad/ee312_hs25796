#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isUpperCase(char c);
int isLowerCase(char c);
int isAlphabet(char c);
int valid(char c);					//subfunction 1
int code_count(char str[], FILE *fp);	//subfunction 2

int main(void) {

	int f_count = 0;
	int c_count = 0;
	int total_c = 0;
	char sentinel[20] = "STOP";
	char filename[100] = { 0 };
	char func_name[100] = { 0 };
	char str[300] = { 0 };
	char str2[300] = { 0 };
	char func_start[20]= "BEGIN_FCN";
	FILE *fp = 0;
	int stop = 0;

	while (1) {
		printf("Counting SLOCs\nEnter file name to process: \n");				//prompt user for filename
		gets(filename, 99);
		stop = strcmp(sentinel, filename);			//check for sentinel
		if (stop == 0) {						//if stop sentnel detected exits program
			printf("Exiting Program...");
			exit(EXIT_SUCCESS);
		}
		fp = fopen(filename, "r");
		if (fp == 0){							//if file was unable to be opened
			printf("File %s failed to open\n\n", filename);
		}
		else {
				int done = 0;
				printf("\nFile Counting Summary Table\n\n");			//print SLOC table
				printf("Filename:   %s\n\n", filename);      //make sure to prep each source file for delimitng using #define BEGIN_FUNC as { and END_FUNC as }
				printf("Function Name          #Lines of Code\n\n");
			while(done==0){

				int found_type = 0;
				int found_func = 0;
				int emptystring = 0;
				char i = 0;
				char j = 0;
				int flag = 0;
				char *pointer1 = 0;
				
					fgets(str, 299, fp);	//find function start/name
					while (!feof(fp) && found_func == 0) {
						fgets(str2, 299, fp);
						pointer1 = strstr(str2, func_start);
						if (pointer1 == 0) {
							strcpy(str, str2);
						}
						else {
							found_func = 1;
						}
					}		
					if (!feof(fp)) {
						for (i = 0; i < 100; i++) {
							func_name[i] = 0;
						}
						i = 0;
						j = 0;
						if (isAlphabet(str[i]) == 0 && (str[i] != '_')) {		
							while (isAlphabet(str[i]) == 0 && (str[i] != '_') && str[i] != 0) {		//ignores spaces/extra junk
								i++;
							}
						}
						while ((isAlphabet(str[i]) || (str[i] == '_')) && str[i] != 0) {			//ignores function type declaration
							i++;
						}
						while (isAlphabet(str[i]) == 0 && (str[i] != '_') && str[i] != 0) {		//ignores more junk/spaces
							i++;
						}
						while (valid(str[i]) && str[i] != 0) {					//gets function name while characters are valid
							func_name[j] = str[i];
							i++;
							j++;
						}
						emptystring = strlen(func_name);
						if (emptystring > 0) {							//checks to make sure function name was actually captured
							printf("%s		       ", func_name);		//prints function name
							f_count++;
							c_count = code_count(str, fp);				//calls code count function
							if (c_count == -1) {						//check mismatch case
								printf("\n\nERROR:\nFunction and End Function Mismatch\n");
							}
							else{
								total_c = total_c + c_count;			//adds code count from currnt function to total code count
								printf("%d\n", c_count);				// prints lines of code for the function
							}
						}
						else {
							break; 
						}
					}
					else {
						if (f_count == 0) {
							printf("Filename %s does not contain any functions\n\n", filename);		//if no function names detected, print file contains no functions
							done = 1;
							fclose(fp);
						}
						else {
							if (c_count != -1) {
								printf("\nTotal Functions: %d\n", f_count);			//print out total function and code line count
								printf("Total Lines of Code: %d\n\n", total_c);
								done = 1;											//exit loop for current file, prompts for new file
							}
						}
					}
				}
		}
		}
	}

int code_count(char str[], FILE *fp) {
	char *pt = 0;
	int line_end = 0;
	int end = 0;
	int flag = 0;
	int i = 0;
	int c_count = 0;
	char func_end[20] = "END_FCN";
	while (end == 0) {					
		fgets(str, 299, fp);
		i = 0;
		line_end = 0;
		pt = strstr(str, func_end);		//check every line to see if end of function
		if (pt == 0 && feof(fp)) {	//check to see if END_FCN not encountered before eof for mismatch error
			return -1;
		}
		if (pt != 0) {		//end code count if END_FCN encountered
			end = 1;
		}
		else {
			while (line_end == 0){				//find every semicolon not in comments or in quotes for strings
			if (str[i] == '/') {
				if (str[i + 1] == '*') {
					i = i + 2;
					flag = 0;
					while (flag == 0) {
						switch (str[i]) {
						case 0:
							fgets(str, 299, fp);
							i = 0;
							if (feof(fp)) {
								flag = 1;
								end = 1;
							}
							break;
						case '*':
							if (str[i + 1] == '/') {
								i = i + 2;
								flag = 1;
							}
							else {
								i++;
							}
							break;
						default:
							i++;
							break;
						}
					}
				}
				if (str[i + 1] == '/') {
					line_end = 0;
				}
				else {}
			}
			if (str[i] == 0) {
				line_end = 1;
			}
			if (str[i] == ';') {
				c_count++;
				i++;
			}
			if (str[i] == '"') {
				i++;
				while (str[i] != '"') {
					i++;
				}
				i++;
				if (str[i] == 0) {
					line_end = 1;
				}
			}
			else {
				i++;
			}
		}
		}
	}
	return c_count;							//return code line count
}

int valid(char c) {
	if ((48 <=c) && (c <= 57)) {
		return 1;
	}
	if (isAlphabet(c) == 1) {
		return 1;
	}
	if (c == '_') {
		return 1;
	}
	return 0;
}


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