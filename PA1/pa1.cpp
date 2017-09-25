//
//  pa1.cpp
//  
//
//  Created by Nicholas Ionata on 9/25/17.
//
//

#include <iostream>
#include <cmath>

class MagicSquare {
private:
	const int N; //Size of matrix
	const int id; //Which square it is,
	int ** square;
	int ** mirrorSquare;
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
				//Flip sq over h1
				break;
			case 5:
				//Flip sq over h2
				break;
		}
	}
	void flipH() {
		int mid = N/2;
		
		for(int i = 0; i < mid; i++) {
			int swapIndex = N - 1 -i;
			
			mirrorSquare[i] = square[swapIndex];
			mirrorSquare[swapIndex] = square[i];
			
			square = mirrorSquare;
			
			/*int swapIndex = N - 1 - i;
			
			row1 = square[i];
			row2 = square[swapIndex];
			
			//std::cout << swapIndex << "\n" << row1[0] << "\n";
			
			square[i] = row2;
			square[swapIndex] = row1;
			
			//std::cout << square[swapIndex][0] << "\n" << row1[0] << "\n";
			*/
		}
	}
	void flipV() {
		/*int mid = N/2;
		
		for(int i = 0; i < mid; i++) {
			int swapIndex = N - 1 - i;
			
			int row1[] = square[i];
			int row2[N] = square[swapIndex];
			
			square[i] = row2;
			square[swapIndex] = row1;
		}*/
	}
public:
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
	void fill() {
		int row = 0;
		int col = N/2;
		
		for(int i = 1; i <= (N * N); i++) {
			int tempRow = row, tempCol = col;
			square[row][col] = i;
			
			row--;
			col++;
			
			//Check if it is over te top
			if(row < 0) {
				row = N - 1;
			}
			
			//Check if it is off to the right
			if(col >= N) {
				col = 0;
			}
			
			if(square[row][col] != 0) {
				//Go back to original square
				row = tempRow;
				col = tempCol;
				
				//Place below original square
				row++;
			}
		}
		
		mirrorSquare = square;
		transform();
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				std::cout << square[i][j] << "\t";
			}
			
			std::cout << "\n";
		}
	}
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
	void end() {
		for (int i = 0; i < N; ++i) {
			delete[] square[i];
			delete[] mirrorSquare[i];
		}
		
		delete[] square;
		delete[] mirrorSquare;
		
		std::cout << "\n";
	}
};

int main() {
	int N;
	
	std::cout << "Enter the size of a magic square: ";
	std::cin >> N;
	
	for(int i = 1; i <= 5; i++) {
		MagicSquare square(N, i);
		square.fill();
		square.check();
		square.end();
	}
	
	return 0;
}

