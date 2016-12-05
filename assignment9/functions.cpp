#include "functions.hh"
#include <stdio.h>

Poly addPolynomials(Poly p1, Poly p2){
	int i = 0;
	double result = 0;
	Poly p;
	Node *point1 = p1.listHead;
	Node *point2 = p2.listHead;
	if (p1.length>=p2.length) {
		i = p1.length;
		while (i > p2.length) {
			p.append(point1->value);
			point1 = point1->next;
			i--;
		}
		while ((i > 0)&&(point1 != nullptr)&&(point2!=nullptr)) {
			result = (point1->value) + (point2->value);
			p.append(result);
			point1 = point1->next;
			point2 = point2->next;
			i--;
		}
	}
	if (p1.length < p2.length) {
		i = p2.length;
		while (i > p1.length) {
			p.append(point2->value);
			point2 = point2->next;
			i--;
		}
		while ((i > 0) && (point1 != nullptr) && (point2 != nullptr)) {
			result = (point1->value) + (point2->value);
			p.append(result);
			point1 = point1->next;
			point2 = point2->next;
			i--;
		}
	}
	return p;
}

Poly subtractPolynomials(Poly p1, Poly p2){
	int i = 0;
	double result = 0;
	Poly p;
	Node *point1 = p1.listHead;
	Node *point2 = p2.listHead;

	if (p1.length >= p2.length) {
		i = p1.length;
		while (i > p2.length) {
			p.append(point1->value);
			point1 = point1->next;
			i--;
		}
		while ((i > 0) && (point1 != nullptr) && (point2 != nullptr)) {
			result = (point1->value) - (point2->value);
			p.append(result);
			point1 = point1->next;
			point2 = point2->next;
			i--;
		}
		return p;
	}
	if (p1.length < p2.length) {
		i = p2.length;
		while (i > p1.length) {
			p.append((point2->value)*(-1));
			point2 = point2->next;
			i--;
		}
		while ((i > 0) && (point1 != nullptr) && (point2 != nullptr)) {
			result = (point1->value) - (point2->value);
			p.append(result);
			point1 = point1->next;
			point2 = point2->next;
			i--;
		}
		return p;
	}
	return p;
}

Poly multiplyPolynomials(Poly p1, Poly p2){
	/* Change code below */
	Poly p;
	return p;
}
