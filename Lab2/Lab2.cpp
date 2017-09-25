//
//  Lab2.cpp
//  
//
//  Created by Nicholas Ionata on 9/21/17.
//
//

#include <iostream>


//Ex1
/*
#define WIDTH 5 
#define HEIGHT 3

int main () {
	int jimmy [HEIGHT][WIDTH];
	int n,m;
	
	for (n=0; n<HEIGHT; n++) {
		for (m=0; m<WIDTH; m++) {
			int number = (n+1)*(m+1);
			jimmy[n][m]=(n+1)*(m+1);
			std::cout << number <<"\t";
		}
		
		std::cout << "\n";
	}
	
	std::cout <<jimmy[0][0];
}*/

//Ex2
/*
int main() {
	int ufid, sum = 0;
	std::cin >> ufid;
	int ufidArr [8] = {};
	
	for(int i = 7; i >= 0; i--) {
		ufidArr[i] = ufid %10;
		ufid /= 10;
	}
	
	for(int i = 1; i < 8; i++) {
		if(ufidArr[0] < ufidArr[i]) {
			std::cout << ufidArr[i] << ",";
		} else {
			sum += ufidArr[i];
		}
	}
	
	std::cout << " are greater than the first digit " << ufidArr[0] << std::endl << "Sum of other digits is " << sum << std::endl;
}*/

//Ex3
int main() {
	int arr[] = {2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
	int v;
	std::cout << "Search for: ";
	std::cin >> v;
	
	for(int i = 0; i < 10; i++) {
		if(arr[i] == v) {
			for(int n = i; n < 9; n++) {
				arr[n] = arr[n + 1];
			}
			
			arr[9] = 0;
		}
		
		std::cout << arr[i] << "\t";
	}
	
	
	
}
