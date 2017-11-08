//
//  pa3.cpp
//  
//
//  Created by Nicholas Ionata on 11/8/17.
//
//

#include "pa3.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Stack::Stack() {
	top = -1;
}

void Stack::push(int x) {
	if(top > 10) {
		cout << "Stack Overflow";
		return;
	} else {
		a[++top] = x;
	}
}

int Stack::pop() {
	if(top < 0) {
		cout << "Stack underflow";
		return 0;
	} else {
		return a[top--];
	}
}

bool Stack::isEmpty() {
	return top < 0;
}

int Stack::getTopIndex() {
	return top;
}

int Stack::getValue(int i) {
	return a[i];
}

int main() {
	//Testing stack
	Stack * s = new Stack();
	
	s->push(5);
	
	cout << s->getTopIndex();
	cout << s->getValue(0);
	
	if(s->isEmpty()) {
		cout << "S is empty asf" << endl;
	} else {
		cout << "S is full asf" << endl;
	}
	
	//Testing files
	ifstream myFile("hworld.txt");
	string x, y = "";
	myFile >> x >> y;

	cout << x << y;
}
