#include <stdio.h>
#include "LinkedList.h"

void LinkedList::addToListAtPosition(int position, int value){
	if (initialize != 1) {
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	if ((position < 0) || (position > length)){
		return;
	}
	if (listHead == NULL){
		listHead = new node;
		listHead->value = value;
		listHead->next = NULL;
		length++;
		return;
	}
	int i = 0;
	node * p = listHead;
	node * q = p;
	while (q!=NULL){
		if (i == position){
			p->next = new node;
			(p->next)->value = value;
			(p->next)->next = q;
			length++;
			return;
		}
		p = q;
		q = p->next;
		i++;
	}
	if (i == position){
		p->next = new node;
		(p->next)->value = value;
		(p->next)->next = q;
		length++;
		return;
	}
}

int LinkedList::getListLength(void){
	if (initialize != 1) {
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	return length;
}

void LinkedList::addToHead(int value){
	if (initialize != 1) {
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	node *p = listHead;
	listHead = new node;
	listHead->next = p;
	listHead->value = value;
	length++;
	return;
}

node * LinkedList::getHead(void){				//sends listHead
	if (initialize != 1) {
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	return listHead;
}

bool LinkedList::find(int value){
	if (initialize != 1) {
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	node * p = listHead;
	int match = 0;
	while (p != NULL) {
		match = p->value;
		if (match == value) {
			return true;
		}
		else {
			p = p->next;
		}
	}
	return false;
}

void LinkedList::appendToList(int value){
	if (initialize != 1) {
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	node * p = listHead;
	node * q = p;
	if (listHead = NULL) {
		listHead = new node;
		listHead->value = value;
		listHead->next = NULL;
		length++;
		return;
	}
	while (q != NULL) {
		p = q;
		q = p->next;
	}
	q = new node;
	p->next = q;
	q->value = value;
	q->next = NULL;
	length++;
	return;
}

void LinkedList::removeFromListAtPosition(int position){
	if (initialize != 1) {
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
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
	if (initialize != 1) {
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

void LinkedList::removeFromEnd(void){
	if (initialize != 1) {
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
	node *p = listHead;
	node *q = p;
	if (listHead == NULL) {
		return;
	}
	if ((listHead->next) == NULL) {
		listHead = NULL;
		delete q;
		length--;
		return;
	}
	while (1) {
		q = p->next;
		if((q->next) == NULL) {
			p->next = NULL;
			delete q;
			length--;
			return;
		}
		p = q;
	}

}

void LinkedList::reverseList(void){
	if (initialize != 1) {
		listHead = NULL;
		length = 0;
		i = 0;
		initialize = 1;
	}
}
