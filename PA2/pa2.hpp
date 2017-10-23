//
//  pa2.hpp
//  
//
//  Created by Nicholas Ionata.
//
//

#ifndef pa2_hpp
#define pa2_hpp

#include <stdio.h>
#include <string>

class Node {
	private:
		std::string name;
		int mem;
		Node * next;
	public:
		Node(std::string value, int mem);
		void insert(std::string value);
		void print(int page);
		void addWorst(std::string name, int mem, int counter);
		void addBest(std::string name, int mem, int counter);
		void kill(std::string, int counter);
		void fragmentation(int counter);
		int check(std::string name);
};

class LinkedList {
	private:
		Node* head;
		Node* tail;
	public:
		LinkedList();
		void insert(std::string value);
		void print();
		void fragmentation();
		void add(std::string name, int mem, std::string algo);
		void kill(std::string);
};

#endif /* pa2_hpp */
