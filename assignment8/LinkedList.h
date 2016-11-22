#include <stdio.h>
#ifndef LinkedList_h		//guards for linkedlist header file
#define LinkedList_h
struct node {
	int value;
	node *next;
};
class LinkedList {
public:
	void addToListAtPosition(int, int);
	int getListLength(void);
	void addToHead(int);
	node * getHead(void);
	bool find(int);
	void appendToList(int);
	void removeFromListAtPosition(int);
	void removeFromHead(void);
	void removeFromEnd(void);
	void reverseList(void);
private:
	int initialize;
	int i;
	int length;
	node *listHead;
};
#endif