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
#include <climits>


//Implementation for the Node class
Node::Node(string data) {
	this->data = data;
	next = NULL;
}

void Node::print() {
	cout << data << " ";
	
	if(next != NULL) {
		next->print();
	} else {
		cout << endl;
	}
}

bool Node::contains(string posData) {
	if(data == posData) {
		return true;
	} else if(next != NULL) {
		return next->contains(posData);
	} else {
		return false;
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
	if(head == NULL) {
		return NULL;
	}
	
	Node* temp = head;
	
	head = head->next;
	
	return temp;
}

void StackLL::print() {
	if(head != NULL) {
		head->print();
	}
}

bool StackLL::contains(string posData) {
	if(head != NULL) {
		return head->contains(posData);
	} else {
		return false;
	}
}

bool StackLL::isEmpty() {
	return head == NULL;
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
	
	cout << endl << "Successfully loaded " << fileName << endl << endl;
	
	StackLL* keywords = new StackLL;
	StackLL* identifiers = new StackLL;
	StackLL* constants = new StackLL;
	StackLL* operators = new StackLL;
	StackLL* delimiters = new StackLL;
	StackLL* syntax = new StackLL;
	
	const string KEYWORDS[] = {"BEGIN", "END", "FOR"};
	const string OPERATORS[] = {"+", "-", "*", "/", "=", "%"};
	
	string input = "";
	while (file >> input) {
		
		int startIndex = 0;
		//int endIndex = 0;
		
		for(int i = 0; i < input.length(); i++) {
			//Test if the string of text is either a keyword or idetifier
			if(isalpha(input[i])) {
				startIndex = i++;
				
				while(isalpha(input[i])) {
					i++;
				}
				
				string newString = input.substr(startIndex, i-startIndex);
				
				if(isupper(newString[0])) {
					keywords->push(newString);
				} else {
					identifiers->push(newString);
				}
			}
			
			//Test if the string of text is a constant
			if(isdigit(input[i])) {
				startIndex = i++;
				
				while(isdigit(input[i])) {
					i++;
				}
				
				constants->push(input.substr(startIndex, i-startIndex));
			}
			
			//Test if the string of text is a delimiter
			if(input[i] == ',' || input[i] == ';') {
				delimiters->push(input.substr(i, 1));
			}
			
			//Test if the string of text is an operator
			if(find(begin(OPERATORS), end(OPERATORS), input.substr(i, 1)) != end(OPERATORS)) {
				if(input[i+1] == '+' || input[i+1] == '-' || input[i+1] == '=') {
					operators->push(input.substr(i++, 2));
				} else {
					operators->push(input.substr(i, 1));
				}
			}
			
			//Test if the string of text is a ( or )
			if(input[i] == '(' || input[i] == ')') {
				syntax->push(input.substr(i, 1));
			}
		}
	}
	
	StackLL* cleanKeywords = new StackLL;
	StackLL* cleanIdentifiers = new StackLL;
	StackLL* cleanConstants = new StackLL;
	StackLL* cleanOperators = new StackLL;
	StackLL* cleanDelimiters = new StackLL;
	StackLL* cleanSyntax = new StackLL;
	int depth = 0;
	
	string tempKeyword = "";
	int beginCounter = 0;
	int endCounter = 0;
	int forCounter = 0;
	while(!keywords->isEmpty()) {
		tempKeyword = keywords->pop()->data;
		
		if(tempKeyword == "FOR") {
			forCounter++;
		} else if(tempKeyword == "BEGIN") {
			beginCounter++;
		} else if(tempKeyword == "END") {
			endCounter++;
		} else {
			if(tempKeyword[0] == 'F') {
				forCounter++;
			} else if(tempKeyword[0] == 'B') {
				beginCounter++;
			} else if(tempKeyword[0] == 'E') {
				endCounter++;
			}
			
			cleanSyntax->push(tempKeyword);
			continue;
		}
		
		if(!cleanKeywords->contains(tempKeyword)) {
			cleanKeywords->push(tempKeyword);
		}
	}
	
	if(beginCounter < endCounter || beginCounter < endCounter) {
		cleanSyntax->push("BEGIN");
	}
	
	if(endCounter < beginCounter || endCounter < forCounter) {
		cleanSyntax->push("END");
	}
	
	if(forCounter < beginCounter || forCounter < endCounter) {
		cleanSyntax->push("FOR");
	}
	
	string tempIdentifier = "";
	while(!identifiers->isEmpty()) {
		tempIdentifier = identifiers->pop()->data;
		
		if(!cleanIdentifiers->contains(tempIdentifier)) {
			cleanIdentifiers->push(tempIdentifier);
		}
	}
	
	string tempConstant = "";
	while(!constants->isEmpty()) {
		tempConstant = constants->pop()->data;
		
		if(!cleanConstants->contains(tempConstant)) {
			cleanConstants->push(tempConstant);
		}
	}
	
	string tempOperator = "";
	while(!operators->isEmpty()) {
		tempOperator = operators->pop()->data;
		
		if(!cleanOperators->contains(tempOperator)) {
			cleanOperators->push(tempOperator);
		}
	}
	
	string tempDelimiter = "";
	while(!delimiters->isEmpty()) {
		tempDelimiter = delimiters->pop()->data;
		
		if(!delimiters->contains(tempDelimiter)) {
			cleanDelimiters->push(tempDelimiter);
		}
	}
	
	string tempSyntax = "";
	int leftCounter = 0;
	int rightCounter = 0;
	while(!syntax->isEmpty()) {
		tempSyntax = syntax->pop()->data;
		
		if(tempSyntax == ")") {
			rightCounter++;
		} else {
			leftCounter++;
		}
	}
	
	if(rightCounter > leftCounter) {
		cleanSyntax->push(")");
	} else if(leftCounter > rightCounter) {
		cleanSyntax->push("(");
	}
		
	if(cleanSyntax->isEmpty()) {
		cleanSyntax->push("NA");
	}
	
	depth = --forCounter;
	
	cout << "The depth of nested loop(s) is " << depth << endl << endl;
	
	cout << "Keywords: ";
	cleanKeywords->print();
	
	cout << "Identifiers: ";
	cleanIdentifiers->print();
	
	cout << "Constants: ";
	cleanConstants->print();
	
	cout << "Operators: ";
	cleanOperators->print();
	
	cout << "Delimiters: ";
	cleanDelimiters->print();
	
	cout << endl << "Syntax Error(s): ";
	cleanSyntax->print();
}
