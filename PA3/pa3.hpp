//
//  pa3.hpp
//  
//
//  Created by Nicholas Ionata on 11/8/17.
//
//

#ifndef pa3_hpp
#define pa3_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Node {
public:
	Node(string data);
	string data;
	Node* next;
	void print();
	bool contains(string posData);
};

class StackLL {
private:
	Node* head;
public:
	StackLL();
	void push(string data);
	Node* pop();
	void print();
	bool contains(string posData);
	bool isEmpty();
};

#endif /* pa3_hpp */
