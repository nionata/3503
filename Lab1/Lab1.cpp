//
//  Lab1.cpp
//  
//
//  Created by Nicholas Ionata on 9/20/17.
//
//

#include <iostream>
int main() {

	//Fib
	/*int n;
	std::cin >> n;
	int* arr = new int[n + 2];
	
	arr[0] = 0;
	arr[1] = 1;
	
	for(int i = 2; i < (n + 2); i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		std::cout << arr[i] << ", ";
	}
	
	std::cout << "\n";*/
	
	
	//GCD
	int a, b;
	std::string c;
	std::cin >> a >> c >> b;
	
	for(int i = a; i > 0; i--) {
		if((a % i) == 0 && (b % i) == 0) {
			std::cout << i << "\n";
			return 0;
		}
	}
}
