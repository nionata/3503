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

class Stack {
private:
	int top;
	int a[10];
public:
	Stack();
	void push(int x);
	int pop();
	bool isEmpty();
	int getTopIndex();
	int getValue(int i);
};

#endif /* pa3_hpp */
