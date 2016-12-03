class Node{
	
public:
	double value;
	Node* next;
	Node(double v, Node* n);
	Node();
	~Node();
};

class Poly{

public:
	Node *getHead();
	void print();
	void append(double v);
	Poly();	//constructor
	~Poly();	//deconstructor
private:
	int initialize;
	int length;
	Node *listHead;
};
