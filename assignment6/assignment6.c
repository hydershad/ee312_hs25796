/*
CODE WRITTEN BY: HYDER SHAD
UT EID: hs25796
10/30/2016
TA: NOLAN CORCORAN
FALL 2016 EE 312, PROF. BARBER
ASSIGNMENT 6: KNUTH HEAP FUNCTIONS
*/

#include <stdlib.h>
#include <stdio.h>

//Initialize the starting point of the array
void init_heap(char heap[]){
	int metadata = 2496;							//available word space for data
	int *bytes_to_int = (int *)heap;
	*bytes_to_int = metadata;
	bytes_to_int = bytes_to_int + (metadata+2);		//jump to second to last word of heap
	*bytes_to_int = metadata;
}

//Allocate requested memory
char *my_malloc(char heap[], int numbytes) {
  printf("My malloc called\n");
  char i = 0;
  char *pointer = 0;
  int prev_metadata = 0;
  int empty_block = 0;
  int *p_int = (int *)heap;									//typecast integer pointer to navigate easily by word length
  int *q_int = p_int;
  int *heap_start = p_int;
  int words = 0;
  int check = 0;
  int remainder = 0;
  words = numbytes / 4;
  remainder = numbytes % 4;
  if (remainder != 0) { words++; }							//round up to nearest word length to accomodate requeted number of bytes
  p_int = p_int + 2498;										//second to last word in heap which contains metatadata used to find contiguous memory block to allocate
  while ((empty_block == 0) && (p_int > heap_start)) {		//while empty block not found and beginning of heap not reached.....
	  if (*p_int < 0) {										//if metadata is negative....
		  p_int = p_int + (*p_int - 4);						//subtract (here we add since value is negative to begin with) number of allocated words for data and additional 4 words to get past current meta data and reach new metadata just above it
	}
	  if (*p_int > 0) {
		  if ((*p_int == words) || ((*p_int) >= (words - 3))) {	//assures metadata blocks are either entirely overwritten or enough space to add new metadata blocks that have free space, no lingering one word or two word chunks of unusable data space.]
			  if (*p_int == words) { 
				  check = 1;								//alter process if exactly equal to requested # of words to avoidmaking extra metadata piece
			  }			
			  prev_metadata = *p_int;						//collect previous metadata stating available space
			  q_int = p_int - (prev_metadata + 2);			//find the other corresponding metadata piece
			  *q_int = prev_metadata - (words + 4);			//subtract from original free space allocated space plus 4 bytes to make new metadata values
			  *p_int = (-1)*words;							//store new metadata of how many words used									
			  q_int = p_int - (words + 2);					//make new metadata of how many words allocated
			  *q_int = (-1)*words;
			  if (check == 0) {								//if condition met...
			  q_int = q_int - 2;
			  *q_int = prev_metadata - (words + 4);			//make new metadata for how many words are remaining  words that are free
			  }
			  empty_block = 1;
		  }
		  else {
			  p_int = p_int - (*p_int + 4);					//subtract number of allocated words for data and additional 4 words to get past the top meta data and reach new metadata just above it
		  }
	  }
  }
  if ((empty_block == 0)||(p_int<=heap_start)) {
	  printf("Sorry nothing is available!\n");
	  return NULL;
  }
  pointer = (char*)p_int;
  pointer = pointer -1;										//returns a pointer to first byte right above lower metadata
  return pointer;
}

//Deallocate requested memory
void my_free(char heap[], char *p) {
	char*q = p;
	q = p + 1;
	int metadata = 0;
	int *pointer = (int*)q;
	int *above = 0;											//pointer to metadata above block to be freed
	int *below = 0;											//pointer to the metadata block below block to be freed
	int upvalue = 0;										//metadata value above block to be freed
	int downvalue = 0;										//metadata value below block to be freed
	metadata = *pointer;									//sizeof block to be freed
	above = (pointer + (metadata)) - 4;
	below = pointer + 2;
	upvalue = *above;
	downvalue = *below;
	if ((upvalue > 0) && (downvalue > 0)) {
		above = above - (upvalue + 2);
		below = below + (downvalue + 2);
		*above = (((-1)*metadata) + downvalue + upvalue) + 8;				//total space to be freed + the four metadata blocks in the middle (8 words)
		*below = (((-1)*metadata) + downvalue + upvalue) + 8;
	}
	if ((upvalue < 0) && (downvalue > 0)) {
		below = below + (downvalue + 2);
		*below = (downvalue - metadata) + 4;						//total space of current plus down and 2 metadata blocks in middle (4 words)
		pointer = (pointer + metadata) - 2;
		*pointer = (downvalue - metadata) + 4;
	}
	if ((upvalue > 0) && (downvalue < 0)) {
		above = above - (upvalue + 2);
		*above = (upvalue - metadata) + 4;						//total space of current plus down and 2 metadata blocks in middle (4 words)
		*pointer = (upvalue - metadata) + 4;
	}
	else {
		*pointer = (-1)*metadata;
		pointer = pointer + (metadata - 2);
		*pointer = (-1)*metadata;
	}
	p = NULL;												//set pointers to NULL, no dangling pointers
}
