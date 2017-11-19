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


//Implementation for the Node class
Node::Node(string data) {
	this->data = data;
	next = NULL;
}

void Node::print() {
	cout << data << endl;
	
	if(next != NULL) {
		next->print();
	}
}


//Implementation for the Stack Linked List class
StackLL::StackLL() {
	head = NULL;
}

void StackLL::push(string data) {
	if(head == NULL) {
		head = new Node(data);
		return;
	}
	
	Node* temp = new Node(data);
	temp->next = head;
	
	head = temp;
}

Node* StackLL::pop() {
	Node* temp = head;
	
	head = head->next;
	
	return temp;
}

void StackLL::print() {
	head->print();
}


int main() {
	ifstream file;
	string fileName = "";
	
	do {
		cout << "Please enter a local file name: ";
		cin >> fileName;
		
		if(fileName == "EXIT") {
			cout << "Sad to see you go buddy!" << endl;
			return 0;
		}
		
		file.open(fileName);
		
		if(!file) {
			cout << "Invalid file! Try again or type EXIT to exit." << endl;
		}
	} while(!file);
	
	cout << "Successfully loaded " << fileName << endl;
	
	StackLL* keywords = new StackLL;
	
	keywords->push("Tits");
	
	keywords->push("Ball");
	
	keywords->push("Ass");
	keywords->print();
	
	string popped = keywords->pop()->data;
	keywords->print();
	
	cout << "P: " << popped << endl;
}
