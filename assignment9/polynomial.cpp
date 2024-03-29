/*
CODE WRITTEN BY: HYDER SHAD
UT EID: hs25796
12/4/2016
TA: NOLAN CORCORAN
FALL 2016 EE 312, PROF. BARBER
ASSIGNMENT 9: C++ Polynomials
*/
#include "polynomial.hh"
#include <stdio.h>

Node::Node(double v, Node* n){
//don't have to use
}

Node* Poly::getHead(){
	return listHead;
}

void Poly::append(double v){
	if (listHead == nullptr) {				//if list empty, create new listhead
		listHead = new Node;
		listHead->value = v;
		listHead->next = nullptr;
		length++;
		return;
	}

	Node * p = listHead;
	Node * q = p;

	while (p != nullptr) {					//traverse list until last node found
		q = p;
		p = q->next;
	}
	p = new Node;							//create new node and attatch to end of list
	q->next = p;
	p->value = v;
	p->next = nullptr;
	length++;
	return;
}
int Poly::getLength(Node *p) {
	int i = 0;
	while (p!=nullptr){
		p = p->next;
		i++;
	}
	return i;
}
void Poly::print(){
	Node* temp = getHead();
	while(temp!=0){
		printf("%.2f", temp->value);
		temp = temp->next;
	}
}
Node::Node() {		//constructor

}
Node::~Node() {		//deconstructor

}
Poly::Poly() {		//constructor
	listHead = nullptr;
	length = 0;
}
Poly::~Poly() {		//deconstructor

}