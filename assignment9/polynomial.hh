/*
CODE WRITTEN BY: HYDER SHAD
UT EID: hs25796
12/4/2016
TA: NOLAN CORCORAN
FALL 2016 EE 312, PROF. BARBER
ASSIGNMENT 9: C++ Polynomials
*/
#ifndef polynomial_h		//guards for polynomial header file
#define polynomial_h
class Node{
	
public:
	double value;
	Node* next;
	Node(double v, Node* n);
	Node();		//constructor
	~Node();	//deconstructor
};

class Poly{

public:
	Node *getHead();
	int getLength(Node *p);		//funtions to get length of polynomial linked lists
	void print();				//print function
	void append(double v);		//adds coefficients/nodes to polynomial linked lists
	Poly();		//constructor
	~Poly();	//deconstructor
	int length;		 //length of linked list
	Node *listHead;  //head of polynomial linked list
};
#endif