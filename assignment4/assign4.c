#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void function_name(char str[], char func_name[], FILE *fp);
int isUpperCase(char c);
int isLowerCase(char c);
int isAlphabet(char c);
int valid(char c);
int main(void) {

	
	int function = 0; //indicates if in function or not
	int f_count = 0;
	int c_count = 0;
	char sentinel[20] = "STOP";
	char filename[100];
	char func_name[100] = { 0 };
	char str[200];
	char str2[200];
	char func_start[20]= "BEGIN_FCN";
	char func_end[20] = "END_FCN";
	FILE *fp = 0;
	int stop = 0;
	while (1) {
		printf("Assignment 4: Counting SLOCs\nEnter file name to process: \n");
		gets(filename, 99);
		stop = strcmp(sentinel, filename);
		if (stop == 0) {
			printf("Exiting Program...");
			exit(EXIT_SUCCESS);
		}
		fp = fopen(filename, "r");
		if (fp == 0) {
			printf("File %s failed to open\n\n", filename);
		}
		else {
			printf("\nFile Counting Summary Table\n\n");
			printf("Filename:   %s\n", filename);      //make sure to prep each source file for delimitng using #define BEGIN_FUNC as { and END_FUNC as }
			int found_type = 0;
			int found_func = 0;
			int emptystring = 0;
			char i = 0;
			char j = 0;
			int flag = 0;
			char *pointer1 = 0;
			char *pointer2 = 0;
			fgets(str, 199, fp);	//find function start/name
			while (!feof(fp) && found_func == 0) {
				fgets(str2, 199, fp);
				pointer1 = strstr(str2, func_start);
				if (pointer1 == 0) {
					strcpy(str, str2);
				}
				else {
					found_func = 1;
				}
			}
			if (!feof(fp)) {
				i = 0;
				j = 0;
				printf("%s", str);
				if (isAlphabet(str[i]) == 0 && (str[i] != '_')) {
					while (isAlphabet(str[i]) == 0 && (str[i] != '_') && str[i] != 0) {
						i++;
					}
				}
				while ((isAlphabet(str[i]) || (str[i] == '_')) && str[i] != 0) {
					i++;
				}
				while (isAlphabet(str[i]) == 0 && (str[i] != '_') && str[i] != 0) {
					i++;
				}
				while (valid(str[i]) && str[i] != 0) {
					func_name[j] = str[i];
					i++;
					j++;
				}
				emptystring = strlen(func_name);
				if (emptystring > 0) {
					printf("%s", func_name);
					f_count++;
				}
				getchar();
			}
			else {
				printf("Filename %s does not contain any functions\n\n", filename);
				fclose(fp);
			}
		}
		}
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
/*
while (found_type == 0) {
	if (str[i] == '/') {
		i++;
		if (str[i] == '*') {
			i++;
			while (flag == 0) {
				switch (str[i]) {
				case 0:
					fgets(str, 199, fp);
					i = 0;
					if (feof(fp)) {
						eof_detect = 1;
						flag = 1;
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

		if (str[i] == '/') {
			fgets(str, 199, fp);
			i = 0;
		}
	}
	if (str[i] == '_' || (isAlphabet(str[i])) == 1) {
		while (str[i] == '_' || (isAlphabet(str[i])) == 1) {
			i++;
		}
		found_type = 1;
	}
	if (str[i] == 0) {
		fgets(str, 199, fp);
		i = 0;
		if (feof(fp)) {
			eof_detect = 1;
		}
	}
	else {
		i++;
	}
}
flag = 0;
while (found_func == 0) {
	if (str[i] == '/') {
		i++;
		if (str[i] == '*') {
			i++;
			while (flag == 0) {
				switch (str[i]) {
				case 0:
					fgets(str, 199, fp);
					i = 0;
					if (feof(fp)) {
						eof_detect = 1;
						flag = 1;
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

		if (str[i] == '/') {
			fgets(str, 199, fp);
			i = 0;
		}
	}
	if (str[i] == '_' || (isAlphabet(str[i])) == 1) {
		while (str[i] == '_' || (isAlphabet(str[i])) == 1) {
			func_name[j] = str[i];
			i++;
			j++;
		}
		found_func = 1;
	}
	if (str[i] == 0) {
		fgets(str, 199, fp);
		i = 0;
		if (feof(fp)) {
			eof_detect = 1;
		}
	}
	else {
		i++;
	}
}*/