#include <stdlib.h>
#include <stdio.h>

//Initialize the starting point of the array
void init_heap(char heap[]){
	int metadata = 2496;
	int *bytes_to_int = (int *)heap;
	*bytes_to_int = metadata;
	bytes_to_int = bytes_to_int + (metadata+2);
	*bytes_to_int = metadata;
}

//Allocate requested memory
char *my_malloc(char heap[], int numbytes) {
  printf("My malloc called\n");
  char i = 0;
  int temp = 0;
  int prev_metadata = 0;
  int empty_block = 0;
  int *p_int = (int *)heap;									//typecast integer pointer to navigate easily by word length
  int *q_int = p_int;
  int words = 0;
  int remainder = 0;
  words = numbytes / 4;
  remainder = numbytes % 4;
  if (remainder != 0) { words++; }							//round up to nearest word length to accomodate requeted number of bytes
  p_int = p_int + 2498;										//second to last word in heap which contains metatadata used to find contiguous memory block to allocate
  while ((empty_block == 0) && (p_int != (&(int)heap))) {	//while empty block not found and beginning of heap not reached.....
	  if (*p_int < 0) {										//if metadata is negative....
		  p_int = p_int + (*p_int - 4);						//subtract number of alloocated words for data and additional 4 words to get past current meta data and reach new metadata just above it
	}
	  if (*p_int > 0) {
		  if((*p_int == words)||(*p_int>=(words-3))){		//assures metadata blocks are either entirely overwritten or enough space to add new metadata blocks that have free space, no lingering one word or two word chunks of unusable data space.]
			  prev_metadata = *p_int;
			  temp = (*p_int) - (words);					//takes how many words are free, subtracts from requested #words, so that it can create/modify new meta data;
			  q_int = p_int - (prev_metadata + 2);
			  *q_int = prev_metadata - (words + 4);			//subtract from original free space allocated space plus 4 bytes to make new
		  }
	  }
  }
  /*****************************

	YOUR CODE GOES HERE

  *****************************/
  printf("Sorry nothing is available!\n");
  return NULL;
}

//Deallocate requested memory
void my_free(char slab[], char *p) {

  /*****************************

	YOUR CODE GOES HERE

  *****************************/

}
