#include "matrixReshaper.hpp"

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include <cstdint>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>


using namespace std;

enum varTypeVar {
	BOOL,
	CHAR,
	LONG_LONG,
	LONG_LONG_DOUBLE,
	CSTRING,
	INT_FAST64_T,
	UINT_FAST64_T,
	INT64_T,
	UINT64_T,
	INTMAX_T,
	UINTMAX_T,
	BOOST__MULTIPRECISION__INT1024_T,
	BOOST__MULTIPRECISION__UINT1024_T
};

using REWRITEME = int_fast64_t;

REWRITEME ** makeSpiralUniversal(REWRITEME ** inputMatrix, uint_fast64_t ySize, uint_fast64_t xSize) {

	int_fast64_t midOneDID = 0;
	REWRITEME * midSingleDimArray = new REWRITEME[ySize * xSize];


	int_fast64_t top = 0;
	int_fast64_t bottom = ySize - 1;
	int_fast64_t left = 0;
	int_fast64_t right = xSize - 1;
	while (true) {
		//If overwriting, end function
		if (left > right)
			break;


		// Write top row to single dim array
		for (int i = left; i <= right; i++) {
			midSingleDimArray[midOneDID] = inputMatrix[top][i];
		}
		cout << endl;
		top++;

		//If overwriting, end function
		if (top > bottom){
			break;
		}
		// print right column
		for (int i = top; i <= bottom; i++) {
			cout << inputMatrix[i][right] << " ";
		}
		cout << endl;
		right--;

		if (left > right) {
			break;
		}
		// print bottom row
		for (int i = right; i >= left; i--) {
			cout << inputMatrix[bottom][i] << " ";
		}
		cout << endl;
		bottom--;

		if (top > bottom) {
			break;
		}
		// print left column
		for (int i = bottom; i >= top; i--){
			cout << inputMatrix[i][left] << " ";
		}
		cout << endl;
		left++;
	}

	REWRITEME ** finalArr = new REWRITEME * [ySize];
	for (uint_fast64_t yLoc = 0; yLoc < ySize; yLoc++) {
		finalArr[yLoc] = new REWRITEME [xSize];
		for (uint_fast64_t xLoc = 0; xLoc < xSize; xLoc++) {
			finalArr[yLoc][xLoc] = midSingleDimArray[(yLoc * ySize) + xLoc];
		}
	}

	delete[] midSingleDimArray;
	return finalArr;
}



int main (){
	int_fast64_t xySize = 3;

	int_fast64_t ** ogMatrix = new int_fast64_t * [xySize];
	int_fast64_t pos = 1;
	for (int_fast64_t y = 0; y < xySize; y++) {
		ogMatrix[y] = new int_fast64_t [xySize];
		for (int_fast64_t x = 0; x < xySize; x++) {
			ogMatrix[y][x] = pos;
			pos++;
			cout << ogMatrix[y][x] << "  ";
		}
		cout << endl;
	}


	makeSpiralBOOL(ogMatrix, xySize, xySize);

	cout << "about to end" << endl;
	for (int_fast16_t i = 0; i < xySize; i++) {
		delete[] ogMatrix[i];
	}
	delete[] ogMatrix;
	cout << "Program Ending" << endl;
	cin.ignore();
	//EXIT_SUCCESS
	return 0;
}
