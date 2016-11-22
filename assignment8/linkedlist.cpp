#include <stdio.h>
#ifndef  _POINT_HH //Point3.hh! 
#define  _POINT_HH 
struct node {
	int val;
	node *next;
};
class LinkedList {
public:
	void addToListAtPosition(int, int);
	int getListLength(void);
	void addToHead(int);
	void getHead(void);
	bool find(int);
	void appendToList(int);
	void removeFromListAtPosition(int);
	void removeFromHead(void);
	void removeFromEnd(void);
	void reverseList(void);
private:
	int i;
	int length;
	node *listHead;
};
 #endif
void LinkedList::addToListAtPosition(int position, int value){
	if ((position < 0) || (position > length)){
		return;
	}
	if (listHead == NULL){
		listHead = new node;
		listHead->val = value;
		listHead->next = NULL;
		length++;
		return;
	}
	int i = 0;
	node * p1 = listHead;
	node * p2 = p1;
	while (p2!=NULL){
		if (i == position){
			p1->next = new node;
			(p1->next)->val = value;
			(p1->next)->next = p2;
			length++;
			return;
		}
		p1 = p2;
		p2 = p1->next;
		i++;
	}
	if (i == position){
		p1->next = new node;
		(p1->next)->val = value;
		(p1->next)->next = p2;
		length++;
		return;
	}
}

int LinkedList::getListLength(void){
	return length;
}

void LinkedList::addToHead(int value){
	node *p = listHead;
	listHead = new node;
	listHead->next = p;
	listHead->val = value;
}

void LinkedList::getHead(void){				//not required function
}

bool LinkedList::find(int){
	return 0;
}

void LinkedList::appendToList(int){
}

void LinkedList::removeFromListAtPosition(int position){
		if ((position < 0) || (position > length + 1)){
			return;
		}
		if (position == 0) {
			if (listHead == NULL) {
				return;
			}
			if (listHead->next == NULL) {
				delete listHead;
				length--;
				return;
			}
			if (listHead->next != NULL) {
				node *p = listHead;
				listHead = listHead->next;
				delete p;
				length--;
				return;
			}
		}
		int i = 0;
		node * p = listHead;
		node * q = p;
		while (q != NULL){
			if (i == position){
				p->next = q->next;
				delete q;
				length--;
				return;
			}
			p = q;
			q = p->next;
			i++;
		}
		return;							//position not found, nothing to delete
	}

void LinkedList::removeFromHead(void){
	node * p = listHead;
	listHead = listHead->next;
	delete p;
	return;
}

void LinkedList::removeFromEnd(void){
}

void LinkedList::reverseList(void){
}
