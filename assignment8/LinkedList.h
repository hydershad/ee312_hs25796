/*CODE WRITTEN BY HYDER SHAD, UT EID: hs25796
ASSIGNMENT 8 - EE312 SOFTWARE DESIGN FALL 2016
PROFESSOR BARBER, TA: NOLAN CORCORAN
11/22/2016
*/
#include <stdio.h>
#ifndef LinkedList_h		//guards for linkedlist header file
#define LinkedList_h
struct node {				//node structure, contains value and pointer to next node
	int value;
	node *next;
};
class LinkedList {
public:
	void addToListAtPosition(int, int);	//adds node at desired position, pushes existing node back one
	int getListLength(void);			//returns list length
	void addToHead(int);				//inserts node at list head
	node * getHead(void);				//returns list head
	bool find(int);						//returns true if value exists in list, false if not found
	void appendToList(int);				//adds node to end of list
	void removeFromListAtPosition(int); //remmoves node from desired position
	void removeFromHead(void);			//removes node from head of list
	void removeFromEnd(void);			//removes node from end of list
	void reverseList(void);				//reverses order of list
private:
	int initialize;						//variable indicating if other private variables have been initialized yet or not
	int i;								//generic counter
	int length;							//tracks list length
	node *listHead;						//node structure list head
};
#endif