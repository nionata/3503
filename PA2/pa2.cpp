//
//  pa2.cpp
//  
//
//  Created by Nicholas Ionata.
//
//

#include "pa2.hpp"
#include <iostream>
#include <string>


//Implementation for the LinkedList class
LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	
	for(int i = 0; i < 32; i++) {
		insert("Free");
	}
}

void LinkedList::insert(std::string value) {
	if(head == NULL) {
		head = new Node(value, 0);
		return;
	}
	head->insert(value);
}

void LinkedList::print() {
	head->print(1);
}

void LinkedList::fragmentation() {
	
}

void LinkedList::add(std::string name, int mem, std::string algo) {
	if(algo == "worst") {
		head->addWorst(name, mem, 0);
	} else {
		head->addBest(name, mem, 0);
	}
}

void LinkedList::kill(std::string name) {
	head->kill(name, 0);
}


//Implementation for the Node class
Node::Node(std::string name, int mem) {
	this->name = name;
	this->mem = mem;
	next = NULL;
}

void Node::print(int page) {
	std::cout << name << " " << mem << " ";
	
	if(next == NULL) {
		return;
	}
	
	if(page % 8 == 0) {
		std::cout << "\n";
	}
	
	next->print(page + 1);
}

void Node::insert(std::string value) {
	if(next == NULL) {
		next = new Node(value, 0);
		return;
	}
	next->insert(value);
}

void Node::addWorst(std::string name, int mem, int counter) {
	Node * temp = this;
	Node * tail = this;
	
	while(temp->next != NULL) {
		if (temp->name != "Free" and temp->next->name == "Free") {
			tail = temp->next;
			//std::cout << "Tail at " <<name;
		}
		temp = temp->next;
	}
	
	tail->name = name;
	counter += 1;
	if(mem > 4) {
		addWorst(name, mem - 4, counter);
		tail->mem = 4;
	} else {
		tail->mem = mem;
		std::cout << "Program " << name << " added successfully: " << counter << " page(s) used.";
	}
	return;
}

void Node::addBest(std::string name, int mem, int counter) {
	if(this->name == "Free") {
		this->name = name;
		counter += 1;
		if(mem > 4) {
			addBest(name, mem - 4, counter);
			this->mem = 4;
		} else {
			this->mem = mem;
			std::cout << "Program " << name << " added successfully: " << counter << " page(s) used.";
		}
		return;
	}
	next->addBest(name, mem, counter);
}

void Node::kill(std::string name, int counter) {
	if(this->name == name) {
		this->name = "Free";
		this->mem = 0;
		counter += 1;
	}
	
	if(next == NULL) {
		std::cout << "Programm " << name << " successfully killed, " << counter << " page(s) reclaimed.";
		return;
	} else {
		next->kill(name, counter);
	}
}


//Main method
int main(int argc, char* argv[]) {
	//Creating variables
	LinkedList * bob = new LinkedList();
	std::string algo = "best";
	int choice = 0;
	
	//Decide which algo to use
	if(argc == 2) {
		if(std::strncmp(argv[1],"worst", 5) == 0) {
			std::cout << "Using worst fit algorithm. \n";
			algo = "worst";
		} else if(std::strncmp(argv[1],"best", 4) == 0) {
			std::cout << "Using best fit algorithm. \n";
		} else {
			std::cout << "Invalid or missing arguments. Using best fit algorithm. \n";
		}
	} else {
		std::cout << "Invalid or missing arguments. Using best fit algorithm. \n";
	}
	
	//Print menu
	std::cout << "\t 1. Add program \n";
	std::cout << "\t 2. Kill program \n";
	std::cout << "\t 3. Fragmentation \n";
	std::cout << "\t 4. Print memory \n";
	std::cout << "\t 5. Exit \n";
	
	//Handle choices
	while(choice != 5) {
		std::cout << "Choice - ";
		std::cin >> choice;
		
		if(choice == 1) {
			std::string name = "";
			int mem = 0;
			std::cout << "Program name - ";
			std::cin >> name;
			std::cout << "Program size (KB) - ";
			std::cin >> mem;
			std::cout << "\n";
			bob->add(name, mem, algo);
		} else if(choice == 2) {
			std::string name = "";
			std::cout << "Program name - ";
			std::cin >> name;
			std::cout << "\n";
			bob->kill(name);
		} else if(choice == 3) {
			bob->fragmentation();
		} else if(choice == 4) {
			std::cout <<"\n";
			bob->print();
		} else if(choice != 5) {
			std::cout << "Invalid option. Try again.";
		}
		
		std::cout << "\n\n";
	}
	
	
	return 0;
}
