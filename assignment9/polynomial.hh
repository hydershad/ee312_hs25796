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
	int getLength(Node *p);
	void print();
	void append(double v);
	Poly();		//constructor
	~Poly();	//deconstructor

	int initialize;
	int length;
	Node *listHead;
};
