/*
CODE WRITTEN BY: HYDER SHAD
UT EID: hs25796
12/4/2016
TA: NOLAN CORCORAN
FALL 2016 EE 312, PROF. BARBER
ASSIGNMENT 9: C++ Polynomials
*/
#include "functions.hh"
#include <stdio.h>
#include <cassert>

void test00(){
	Poly p1;
	Poly p2;
	p1.append(1);
	p1.append(2);
	p2.append(3);

	Poly result = addPolynomials(p1, p2);
	assert(result.getHead()->value ==1);
	assert(result.getHead()->next->value == 5);
}

void test01(){
	Poly p1;
	Poly p2;
	p1.append(1);
	p1.append(2);
	p2.append(3);

	Poly result = subtractPolynomials(p1, p2);
	assert(result.getHead()->value ==1);
	assert(result.getHead()->next->value == -1);
}

void test02(){
	Poly p1;
	Poly p2;
	p1.append(1);
	p1.append(2);
	p2.append(3);

	Poly result = multiplyPolynomials(p1, p2);
	assert(result.getHead()->value ==3);
	assert(result.getHead()->next->value == 6);
}

void test03(){
	Poly p1;
	Poly p2;
	p1.append(1);
	p2.append(1);
	Poly result = addPolynomials(p1, p2);
	assert(result.getHead()->value == 2);
	Poly p3;
	p3.append(2);
	result = addPolynomials(p1, p3);
	assert(result.getHead()->value == 3);
}
void test04() {
	Poly p1;
	Poly p2;
	p1.append(1);
	p1.append(1);
	p2.append(1);
	p2.append(3);
	p2.append(1);

	Poly result = multiplyPolynomials(p1, p2);
	assert(result.getHead()->value == 1);
	assert(result.getHead()->next->value == 4);
	assert(result.getHead()->next->next->value == 4);
	assert(result.getHead()->next->next->next->value == 1);
}
int main(){
	test00();
	test01();
	test02();
	test03();
	test04();
}