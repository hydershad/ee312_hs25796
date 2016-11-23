/*CODE WRITTEN BY HYDER SHAD, UT EID: hs25796
ASSIGNMENT 8 - EE312 SOFTWARE DESIGN FALL 2016
PROFESSOR BARBER, TA: NOLAN CORCORAN
11/22/2016
*/
#include <stdio.h>
#include "LinkedList.h"

void LinkedList::addToListAtPosition(int position, int value){
	if (initialize != 1) {								//initialize variables if not already done
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	if ((position < 0) || (position > length)) {		//if desired position is out of bounds, do nothing, return
		return;
	}
	if (listHead == NULL) {								//if list head does not exist and position is zero, create list head node
		if (position == 0) {
			listHead = new node;						//create new node struct
			listHead->value = value;					//store desired/given value
			listHead->next = NULL;						//set next to null, only one node in list
			length++;
			return;
		}
	}
	int i = 0;											//else if listhead exist and desired position within bounds, find position and insert new node, pushing existing nodes back
	node * p = listHead;
	node * q = p;
	while (q != NULL) {
		if (i == position) {
			p->next = new node;							//create new node and push existing node back one position in list
			(p->next)->value = value;
			(p->next)->next = q;
			length++;									//update length
			return;										//return
		}
		p = q;											//until desired position is found keep moving through list 
		q = p->next;
		i++;
	}
	if (i == position) {								//handles edge case with position being last in the list
		p->next = new node;
		(p->next)->value = value;
		(p->next)->next = q;
		length++;
		return;
	}
}

int LinkedList::getListLength(void){		
	if (initialize != 1) {					//initialize variables if not already done
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	return length;							//return the calculated length of the linked list
}

void LinkedList::addToHead(int value){
	if (initialize != 1) {					//initialize variables if not already done
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	node *p = listHead;						//insert a new node at the head of the list, pushing existing list head back one index
	listHead = new node;
	listHead->next = p;
	listHead->value = value;
	length++;
	return;
}

node * LinkedList::getHead(void){				//sends listHead
	if (initialize != 1) {						//initialize variables if not already done
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	return listHead;							//returns pointer to list head, returns null pointer if list not created
}

bool LinkedList::find(int value){
	if (initialize != 1) {						//initialize variables if not already done
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	node * p = listHead;
	int match = 0;
	while (p != NULL) {						//traverse list until end reached and if desired value is in linked list return true
		match = p->value;
		if (match == value) {
			return true;
		}
		else {								//moves through list
			p = p->next;
		}
	}
	return false;							//if end of list reached means vvalue is not in list, return false
}

void LinkedList::appendToList(int value){
	if (initialize != 1){					//initialize variables if not already done
		listHead = NULL;						
		length = 0;
		i = 0;
		initialize = 1;
	}
	if (listHead == NULL) {					//if list empty, ccreate new listhead
		listHead = new node;
		listHead->value = value;
		listHead->next = NULL;
		length++;
		return;
	}

	node * p = listHead;
	node * q = p;
	
	while (p != NULL){						//traverse list until last node found
		q = p;
		p = q->next;
	}
	p = new node;							//create new node and attatch to end of list
	q->next = p;
	p->value = value;
	p->next = NULL;
	length++;
	return;
}

void LinkedList::removeFromListAtPosition(int position) {
	if (initialize != 1) {								//initialize variables if not already done
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	if ((position < 0) || (position > length + 1)) {	//check to see if desired position is within the list, if not, do nothing
		return;
	}
	if (position == 0) {								//if list is empty, do nothing
		if (listHead == NULL) {
			return;
		}
		if (listHead->next == NULL) {					//deletes list head, makes list head null pointer
			delete listHead;
			length--;
			listHead = NULL;
			return;
		}
		if (listHead->next != NULL) {					//deletes list head and makes the next node the new list head
			node *p = listHead;
			listHead = listHead->next;
			delete p;
			length--;
			return;
		}
	}
	int i = 0;
	node * p = listHead;								//traverse list until desired position/node found
	node * q = p;
	while (q != NULL) {
		if (i == position) {
			p->next = q->next;							//append previous node to connect to next node
			delete q;									//delete desired node
			length--;
			return;
		}
		p = q;
		q = p->next;
		i++;
	}
	return;							//position not found, nothing to delete
}

void LinkedList::removeFromHead(void) {
	if (initialize != 1) {					//initialize variables if not already done
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	node * p = listHead;
	listHead = listHead->next;
	delete p;
	length--;
	return;
}

void LinkedList::removeFromEnd(void) {
	if (initialize != 1) {					//initialize variables if not already done
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	node *p = listHead;
	node *q = p;
	if (listHead == NULL) {					//if list does not exist, do nothing, return
		return;
	}
	if ((listHead->next) == NULL) {			//if list head points to null, delete list head and set to null
		listHead = NULL;
		delete q;
		length--;
		return;
	}
	while (1) {								//traverse list until end found (null pointer), and delete that node, making previous node now point to null
		q = p->next;
		if ((q->next) == NULL) {
			p->next = NULL;
			delete q;
			length--;
			return;
		}
		p = q;
	}
}

void LinkedList::reverseList(void) {
	if (initialize != 1) {					//initialize variables if not already done
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	node * previous = NULL;				//pointers to hold current, next, and the previous node locations to revverse list order
	node * current = listHead;
	node * next = NULL;
	while (current != NULL){			//until end of list reached, change the "next" pointers of each node to point to the previous as you traverse the list
		next = current->next;			
		current->next = previous;
		previous = current;
		current = next;
	}
	listHead = previous;				//finally once end of list reached make the list head equal to the last node, which is now the first
	return;
}
