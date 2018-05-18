#include "matrixPlusNone.hpp"

//#include <quadmath.h> //required for the boost float 128
//#include <gmp.h>
//#include <boost\multiprecision\gmp.hpp> //Sister to cppint, but floating, also fixes some of cppint's erros


#include <boost/multiprecision/float128.hpp> //very precision float for shading
//	boost::multiprecision::float128 variableName;
//#include <boost/multiprecision/cpp_int.hpp> //Needed for absoluly huge resolution images (This program should have no problems generating over 100x gigapixel images)
/*		boost::multiprecision::uint128_t
		boost::multiprecision::uint256_t
		boost::multiprecision::uint512_t
		boost::multiprecision::uint1024_t
		boost::multiprecision::int128_t
		boost::multiprecision::int256_t
		boost::multiprecision::int512_t
		boost::multiprecision::int1024_t*/




#include <cstdlib>
#include <cstdint>


#include <iostream>
#include <iomanip>

#include <cmath>
#include <cstring>
#include <string>

//Libraries maybe needed, possibly for debug/logging
//#include <time.h>
#include <fstream>
//#include <ctime>

using namespace std;

/*
void createSpiral (CHANGEMEVARIABLE * inputData, CHANGEMEVARIABLE ** spiralMatrix, arraySizeAndForLoopVariableType ySize, arraySizeAndForLoopVariableType xSize) {
	arraySizeAndForLoopVariableType top = 0;
	arraySizeAndForLoopVariableType bottom = ySize - 1;
	arraySizeAndForLoopVariableType left = 0;
	arraySizeAndForLoopVariableType right = xSize - 1;
	arraySizeAndForLoopVariableType index = 0;

	while (true) {
		//If this would overwrite data/is finished: end function
		if (left > right){
//			cout << "Ending writing on: LR" << endl;
			break;
		}
		//Copy top row
		for (arraySizeAndForLoopVariableType i = left; i <= right; i++) {
			spiralMatrix[top][i] = inputData[index++];
		}
		top++;


		//If this would overwrite data/is finished: end function
		if (top > bottom) {
//			cout << "Ending writing on: TB" << endl;
			break;
		}
		//Copy right column
		for (arraySizeAndForLoopVariableType i = top; i <= bottom; i++) {
			spiralMatrix[i][right] = inputData[index++];
		}
		right--;


		//If this would overwrite data/is finished: end function
		if (left > right) {
//			cout << "Ending writing on: LR" << endl;
			break;
		}
		//Copy bottom row
		for (arraySizeAndForLoopVariableType i = right; i >= left; i--) {
			spiralMatrix[bottom][i] = inputData[index++];
		}
		bottom--;


		//If this would overwrite data/is finished: end function
		if (top > bottom) {
//			cout << "Ending writing on: TB" << endl;
			break;
		}
		//Copy left column
		for (arraySizeAndForLoopVariableType i = bottom; i >= top; i--) {
			spiralMatrix[i][left] = inputData[index++];
		}
		left++;
	}
}
*/


void createSpiral (bool * inputData, bool ** spiralMatrix, arraySizeAndForLoopVariableType ySize, arraySizeAndForLoopVariableType xSize) {
	arraySizeAndForLoopVariableType top = 0;
	arraySizeAndForLoopVariableType bottom = ySize - 1;
	arraySizeAndForLoopVariableType left = 0;
	arraySizeAndForLoopVariableType right = xSize - 1;
	arraySizeAndForLoopVariableType index = 0;

	while (true) {
		//If this would overwrite data/is finished: end function
		if (left > right){
//			cout << "Ending writing on: LR" << endl;
			break;
		}
		//Copy top row
		for (arraySizeAndForLoopVariableType i = left; i <= right; i++) {
			spiralMatrix[top][i] = inputData[index++];
		}
		top++;


		//If this would overwrite data/is finished: end function
		if (top > bottom) {
//			cout << "Ending writing on: TB" << endl;
			break;
		}
		//Copy right column
		for (arraySizeAndForLoopVariableType i = top; i <= bottom; i++) {
			spiralMatrix[i][right] = inputData[index++];
		}
		right--;


		//If this would overwrite data/is finished: end function
		if (left > right) {
//			cout << "Ending writing on: LR" << endl;
			break;
		}
		//Copy bottom row
		for (arraySizeAndForLoopVariableType i = right; i >= left; i--) {
			spiralMatrix[bottom][i] = inputData[index++];
		}
		bottom--;


		//If this would overwrite data/is finished: end function
		if (top > bottom) {
//			cout << "Ending writing on: TB" << endl;
			break;
		}
		//Copy left column
		for (arraySizeAndForLoopVariableType i = bottom; i >= top; i--) {
			spiralMatrix[i][left] = inputData[index++];
		}
		left++;
	}
}
void createSpiral (int_fast64_t * inputData, int_fast64_t ** spiralMatrix, arraySizeAndForLoopVariableType ySize, arraySizeAndForLoopVariableType xSize) {
	arraySizeAndForLoopVariableType top = 0;
	arraySizeAndForLoopVariableType bottom = ySize - 1;
	arraySizeAndForLoopVariableType left = 0;
	arraySizeAndForLoopVariableType right = xSize - 1;
	arraySizeAndForLoopVariableType index = 0;

	while (true) {
		//If this would overwrite data/is finished: end function
		if (left > right){
//			cout << "Ending writing on: LR" << endl;
			break;
		}
		//Copy top row
		for (arraySizeAndForLoopVariableType i = left; i <= right; i++) {
			spiralMatrix[top][i] = inputData[index++];
		}
		top++;


		//If this would overwrite data/is finished: end function
		if (top > bottom) {
//			cout << "Ending writing on: TB" << endl;
			break;
		}
		//Copy right column
		for (arraySizeAndForLoopVariableType i = top; i <= bottom; i++) {
			spiralMatrix[i][right] = inputData[index++];
		}
		right--;


		//If this would overwrite data/is finished: end function
		if (left > right) {
//			cout << "Ending writing on: LR" << endl;
			break;
		}
		//Copy bottom row
		for (arraySizeAndForLoopVariableType i = right; i >= left; i--) {
			spiralMatrix[bottom][i] = inputData[index++];
		}
		bottom--;


		//If this would overwrite data/is finished: end function
		if (top > bottom) {
//			cout << "Ending writing on: TB" << endl;
			break;
		}
		//Copy left column
		for (arraySizeAndForLoopVariableType i = bottom; i >= top; i--) {
			spiralMatrix[i][left] = inputData[index++];
		}
		left++;
	}
}



void universalSemiReverse (bool * ogPtr, uint_fast64_t size){
	bool* newPtr = new bool[size];
	uint_fast64_t revNum = size - 1;
	for (uint_fast64_t i = 0; i < size; i++) {
		newPtr[revNum] = ogPtr[i];
		revNum--;
	}
	delete[] ogPtr;
	ogPtr = newPtr;
}
void universalSemiReverse (uint_fast64_t * ogPtr, uint_fast64_t size){
	uint_fast64_t* newPtr = new uint_fast64_t[size];
	uint_fast64_t revNum = size - 1;
	for (uint_fast64_t i = 0; i < size; i++) {
		newPtr[revNum] = ogPtr[i];
		revNum--;
	}
	delete[] ogPtr;
	ogPtr = newPtr;
}
void universalSemiReverse (int_fast64_t * ogPtr, uint_fast64_t size){
	int_fast64_t* newPtr = new int_fast64_t[size];
	uint_fast64_t revNum = size - 1;
	for (uint_fast64_t i = 0; i < size; i++) {
		newPtr[revNum] = ogPtr[i];
		revNum--;
	}
	delete[] ogPtr;
	ogPtr = newPtr;
}


bool** single2D_Bool (uint_fast64_t xySize, bool * ogPtr){
	bool** newPtr = new bool * [xySize];
	for (uint_fast64_t y = 0; y < xySize; y++) {
		newPtr[y] = new bool[xySize];
		for (uint_fast64_t x = 0; x < xySize; x++) {
			newPtr[y][x] = ogPtr[x * y];
		}
	}
	return newPtr;
}
