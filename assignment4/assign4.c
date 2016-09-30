#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char filename[80];
	char str[80];
	FILE *fp = 0;
	printf("Assignment 4: Counting SLOCs\nEnter file name to process: \n");
	//figure out what the hell goes here to get string, gets does not work???
	if (fp == NULL) {
		printf("\nFile %s failed to open. Exiting program...", filename);
		getchar();
		exit(EXIT_FAILURE);
	}
}