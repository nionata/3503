//
//  pa1.cpp
//  
//
//  Created by Nicholas Ionata on 9/25/17.
//
//

#include <iostream>

class MagicSquare {
private:
	const int N; //Size of matrix
	const int id; //Which square it is,
	int ** square; //2D array that is our square
	//Switch through which sqare this is and pick what transformation will happen
	void transform() {
		switch(id) {
			case 1:
				break;
			case 2:
				flipH();
				break;
			case 3:
				flipV();
				break;
			case 4:
				flipHV();
				break;
			case 5:
				flipDD();
				break;
		}
	}
	//Flip the current square over the middle row
	void flipH() {
		int mid = N/2;
		
		for(int i = 0; i < mid; i++) {
			int swapIndex = N - 1 -i;
			
			for(int j = 0; j < N; j++) {
				int temp = square[i][j];
				
				square[i][j] = square[swapIndex][j];
				square[swapIndex][j] = temp;
			}
		}
	}
	//Flip the current square over the middle column
	void flipV() {
		int mid = N/2;
		
		for(int i = 0; i < mid; i++) {
			int swapIndex = N - 1 -i;
			
			for(int j = 0; j < N; j++) {
				int temp = square[j][i];
				
				square[j][i] = square[j][swapIndex];
				square[j][swapIndex] = temp;
			}
		}
	}
	//Flip the current square over the middle row and column
	void flipHV() {
		flipH();
		flipV();
	}
	//Flip the current square over the upward diagonal
	void flipDD() {
		for(int i = 0; i < N; i++) {
			int temp = square[0][i];
			
			square[0][i] = square[i][0];
			square[i][0] = temp;
		}
	}
public:
	//Initialize the object and fill the square arr
	MagicSquare(int N, int id):N(N), id(id) {
		square = new int*[N];
		
		for (int i = 0 ; i < N; i++) {
			square[i] = new int[N];
			
			for(int a = 0; a < N; a++) {
				square[i][a] = 0;
			}
		}
		
		std::cout << "\n" << "Magic square #" << id << " is:\n";
	}
	//Find the fill the current magic square
	void fill() {
		int row = 0;
		int col = N/2;
		
		for(int i = 1; i <= (N * N); i++) {
			//Save temp values of the original index
			int tempRow = row, tempCol = col;
			square[row][col] = i;
			
			row--;
			col++;
			
			//Check if index is over the top
			if(row < 0) {
				row = N - 1;
			}
			
			//Check if index is off to the right
			if(col >= N) {
				col = 0;
			}
			
			if(square[row][col] != 0) {
				//Go back to original index w/ temp vals
				row = tempRow;
				col = tempCol;
				
				//Place below original index
				row++;
			}
		}
		
		//Possibly transform the array to find a new version of the magic square
		transform();
		
		//Print the square out
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				std::cout << square[i][j] << "\t";
			}
			
			std::cout << "\n";
		}
	}
	//Check the sums of the square to confirm it adds up correctly
	void check() {
		std::cout << "Checking the sum of every row: ";
		for(int i = 0; i < N; i++) {
			int rowSum = 0;
			
			for(int j = 0; j < N; j++) {
				rowSum += square[i][j];
			}
			
			std::cout << rowSum << " ";
		}
		
		std::cout << std::endl << "Checking the sum of every column: ";
		for(int i = 0; i < N; i++) {
			int colSum = 0;
			
			for(int j = 0; j < N; j++) {
				colSum += square[j][i];
			}
			
			std::cout << colSum << " ";
		}
		
		int diag1 = 0, diag2 = 0;
		int diag1Counter = 0, diag2Counter = N - 1;
		std::cout << std::endl << "Checking the sum of every diagonal: ";
		for(int i = 0; i < N; i++) {
			diag1 += square[i][diag1Counter];
			diag2 += square[i][diag2Counter];
			
			diag1Counter++;
			diag2Counter--;
		}
		std::cout << diag1 << " " << diag2;
	}
	//Deletes the pointers and frees up the memory
	void end() {
		for (int i = 0; i < N; ++i) {
			delete[] square[i];
		}
		
		delete[] square;
		
		std::cout << "\n";
	}
};

int main() {
	int N;
	
	std::cout << "Enter the size of a magic square: ";
	std::cin >> N;
	
	if(N < 3 || N > 15 || (N % 2) == 0) {
		std::cout << "Wrong input! Please try again by picking an odd number between 3 and 15. \n";
		return 0;
	}
	
	for(int i = 1; i <= 5; i++) {
		MagicSquare square(N, i);
		square.fill();
		square.check();
		square.end();
	}
	
	return 0;
}

