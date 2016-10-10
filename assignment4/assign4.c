#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isUpperCase(char c);
int isLowerCase(char c);
int isAlphabet(char c);
int valid(char c);
int code_count(char str[], FILE *fp);
int main(void) {

	int f_count = 0;
	int c_count = 0;
	char sentinel[20] = "STOP";
	char filename[100];
	char func_name[100] = { 0 };
	char str[200];
	char str2[200];
	char func_start[20]= "BEGIN_FCN";
	FILE *fp = 0;
	int stop = 0;

	while (1) {
		printf("Counting SLOCs\nEnter file name to process: \n");
		gets(filename, 99);
		stop = strcmp(sentinel, filename);
		if (stop == 0) {
			printf("Exiting Program...");
			exit(EXIT_SUCCESS);
		}
		fp = fopen(filename, "r");
		if (fp == 0){
			printf("File %s failed to open\n\n", filename);
		}
		else {
				int done = 0;
				printf("\nFile Counting Summary Table\n\n");
				printf("Filename:   %s\n", filename);      //make sure to prep each source file for delimitng using #define BEGIN_FUNC as { and END_FUNC as }

			while(done==0){

				int found_type = 0;
				int found_func = 0;
				int emptystring = 0;
				char i = 0;
				char j = 0;
				int flag = 0;
				char *pointer1 = 0;
				
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
						for (i = 0; i < 100; i++) {
							func_name[i] = 0;
						}
						i = 0;
						j = 0;
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
							printf("%s			", func_name);
							f_count++;
							c_count = code_count(str, fp);
							printf("%d\n", c_count);
						}
						else {
							break; 
						}
					}
					else {
						if (f_count == 0) {
							printf("Filename %s does not contain any functions\n\n", filename);
							done = 1;
							fclose(fp);
						}
						else {
							printf("\n\nTotal Functions: %d\n", f_count);
							printf("Total Lines of Code: %d\n", c_count);
							done = 1;
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
		fgets(str, 199, fp);
		i = 0;
		line_end = 0;
		pt = strstr(str, func_end);;
		if (pt != 0) {
			end = 1;
		}
		else {
			while (line_end == 0){
			if (str[i] == '/') {
				if (str[i + 1] == '*') {
					i = i + 2;
					while (flag == 0) {
						switch (str[i]) {
						case 0:
							fgets(str, 199, fp);
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
				if (str[i] == '/') {
					fgets(str, 199, fp);
					i = 0;
				}
			}
			if (str[i] == 0) {
				line_end = 1;
			}
			if (str[i] == ';') {
				c_count++;
				i++;
			}
			else {
				i++;
			}
		}
		}
	}
	return c_count;
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