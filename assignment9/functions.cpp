#include "functions.hh"
#include <stdio.h>

Poly addPolynomials(Poly p1, Poly p2){
	int i = 0;														//counter used to track the current degree of the polynomials being added
	double result = 0;
	Poly p;															//resultant polynomial to be returned
	Node *point1 = p1.listHead;										//pointers to access polynomial linked list nodes
	Node *point2 = p2.listHead;										
	if (p1.length>=p2.length) {										//if polynomial 1 is of higher or equal degree, append p1 coefficients directly until same degree as polynomial #2 is reached
		i = p1.length;
		while (i > p2.length) {
			p.append(point1->value);								//append coefficient to the result polynomial
			point1 = point1->next;
			i--;
		}
		while ((i > 0)&&(point1 != nullptr)&&(point2 != nullptr)) {	//add coefficients of p1 and p2 until end of polynomials reached
			result = (point1->value) + (point2->value);
			p.append(result);
			point1 = point1->next;
			point2 = point2->next;
			i--;
		}
		return p;													//return new polynomial
	}
	if (p1.length < p2.length) {									//if polynomial 2 is of higher degree, append p2 coefficients directly until same degree as polynomial #1 is reached
		i = p2.length;
		while (i > p1.length) {
			p.append(point2->value);
			point2 = point2->next;
			i--;
		}
		while ((i > 0)&&(point1 != nullptr)&&(point2 != nullptr)) {	//add coefficients of p1 and p2 until end of polynomials reached
			result = (point1->value) + (point2->value);
			p.append(result);
			point1 = point1->next;
			point2 = point2->next;
			i--;
		}
		return p;													//return new polynomial
	}
	return p;
}

Poly subtractPolynomials(Poly p1, Poly p2){						    //same behavior as the addPolynomials function, just subtracts coefficients instead of adding them (p1-p2)
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
	Node *point1 = p1.listHead;											//created pointers to access linked list nodes for polynomials
	Node *point2 = p2.listHead;
	int  max_index = (p1.length + p2.length) - 2;						//position of largest degree polynomial member after multiplication will always be (length1+length2) - 2
	double result = 0;													//end result of multiplication
	double arr[50] = { 0 };												//array to store results of multiplication of polynomial members, resultant polynomial cannot be larger than degree 49
	Poly p;																//resultant polynomial to return
	int i = p1.length;													//for loop counters for array indexing and multiplications
	int j = p2.length;
	for (i = p1.length; i > 0; i--) {
		point2 = p2.listHead;											//reset pointer #2
		for (j = p2.length; j > 0; j--) {
			result = (point1->value)*(point2->value);					//multiply coefficients
			arr[i + j -2] += result;									//store result at appropriate array location
			point2 = point2->next;										//update pointer2 for next multiplication
		}
		point1 = point1->next;											//update pointer1 for next round of multiplications
	}
	while (max_index >= 0) {
		p.append(arr[max_index]);										//store resulting coefficients from multiplied polynomials into a new polynomial
		max_index--;
	}
	return p;															//return the product polynomial
}
