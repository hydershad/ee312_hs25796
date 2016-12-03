#include "polynomial.hh"
#include <stdio.h>

Node::Node(double v, Node* n){
	/*Your code goes here */
}

Node* Poly::getHead(){
	if (initialize != 1) {						//initialize variables if not already done
		listHead = NULL;
		length = 0;
		initialize = 1;
	}
	return listHead;
}

void Poly::append(double v){
	if (initialize != 1) {						//initialize variables if not already done so
		listHead = NULL;
		length = 0;
		initialize = 1;
	}
	if (listHead == nullptr) {					//if list empty, create new listhead
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

void Poly::print(){
	Node* temp = getHead();
	while(temp!=0){
		printf("%.2f", temp->value);
		temp = temp->next;
	}
}
Node::Node() {

}
Node::~Node() {

}
Poly::Poly() {		//constructor

}
Poly::~Poly() {		//deconstructor

}