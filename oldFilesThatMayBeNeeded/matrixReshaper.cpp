#include "matrixReshaper.hpp"

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

typedef bool VARIABLETYPE___;

enum direction {UP, DOWN, LEFT, RIGHT};


struct uint_fast64_tAndBool {
	uint_fast64_t num;
	bool isSet;
};
struct boolAndBool {
	bool num;
	bool isSet;
};


void printMatrix(void ** ogPtr, varTypeVar varType, uint_fast64_t xSize, uint_fast64_t ySize){
	uint_fast64_t number;

	switch (varType) {
		case (BOOL): {
			for (size_t yLoc = 0; yLoc < ySize; yLoc++) {
				for (size_t xLoc = 0; xLoc < xSize; xLoc++) {
					number = (uint_fast64_t*)ogPtr[yLoc][xLoc];
				}
			}


		}
		break;


		case (CHAR): {


		}
		break;


		case (LONG_LONG): {


		}
		break;


		case (LONG_LONG_DOUBLE): {


		}
		break;


		case (CSTRING): {


		}
		break;


		case (INT_FAST64_T): {


		}
		break;


		case (UINT_FAST64_T): {


		}
		break;


		case (INT64_T): {


		}
		break;


		case (UINT64_T): {


		}
		break;


		case (INTMAX_T): {


		}
		break;


		case (UINTMAX_T): {


		}
		break;


		case (BOOST__MULTIPRECISION__INT1024_T): {


		}
		break;


		case (BOOST__MULTIPRECISION__UINT1024_T): {


		}
		break;


	}

}




void print_spiral (int ** matrix, int size)
{
    int x = 0; // current position; x
    int y = 0; // current position; y
    int d = 0; // current direction; 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
    int c = 0; // counter
    int s = 1; // chain size

    // starting point
    x = ((int)floor(size/2.0))-1;
    y = ((int)floor(size/2.0))-1;

    for (int k=1; k<=(size-1); k++)
    {
        for (int j=0; j<(k<(size-1)?2:3); j++)
        {
            for (int i=0; i<s; i++)
            {
               cout << matrix[x][y] << " ";
                c++;

                switch (d)
                {
                    case 0: y = y + 1; break;
                    case 1: x = x + 1; break;
                    case 2: y = y - 1; break;
                    case 3: x = x - 1; break;
                }
            }
            d = (d+1)%4;
        }
        s = s + 1;
    }
}


void singleReverse_Bool (uint_fast64_t size, bool * ogPtr){
	bool* newPtr = new bool[size];
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

void stdToSpiralUfast64 (uint_fast64_t xSize, uint_fast64_t ySize, uint_fast64_t ** ogPtr){
	//These might slow code down a little, but they make coding a bit easier
	uint_fast64_t leftLimit = 0;
	uint_fast64_t topLimit = 0;
	uint_fast64_t downLimit = ySize - 1;
	uint_fast64_t rightLimit = xSize - 1;


	uint_fast64_tAndBool ** midPtr = new uint_fast64_tAndBool * [ySize];
	for (uint_fast64_t y = 0; y < ySize; y++) {
		midPtr[y] = new uint_fast64_tAndBool [xSize];
		for (uint_fast64_t x = 0; x < xSize; x++) {
			midPtr[y][x].isSet = false;
		}
	}




	uint_fast64_t nextX;
	uint_fast64_t nextY;
	bool nextLocIsValid;
	bool nextValisSet;
	uint_fast64_t numValSet = 0;


	uint_fast64_t currentX;
	uint_fast64_t currentY;
	direction currentDirection;
	if (startAtLeft == true) {
		currentX = 0;
		if (startAtTop == true) {
			currentY = 0;
			if (isCCW == true) {
				currentDirection = RIGHT;
			}
			else{
				currentDirection = DOWN;
			}
		}
		else{
			currentY = downLimit;
			if (isCCW == true) {
				currentDirection = UP;
			}
			else{
				currentDirection = RIGHT;
			}
		}
	}
	else{
		currentX = rightLimit;
		if (startAtTop == true) {
			currentY = 0;
			if (isCCW == true) {
				currentDirection = DOWN;
			}
			else{
				currentDirection = LEFT;
			}
		}
		else{
			currentY = downLimit;
			if (isCCW == true) {
				currentDirection = LEFT;
			}
			else{
				currentDirection = UP;
			}
		}
	}




	do {
		do {
			midPtr[currentY][currentX].num = ogPtr[currentY][currentX];
			midPtr[currentY][currentX].isSet = true;
			numValSet = numValSet + 1;


			switch (currentDirection) {
				case LEFT:
					nextX = currentX - 1;
					nextY = currentY;
					break;
				case UP:
					nextX = currentX;
					nextY = currentY - 1;
					break;
				case RIGHT:
					nextX = currentX + 1;
					nextY = currentY;
					break;
				case DOWN:
					nextX = currentX;
					nextY = currentY + 1;
					break;
			}



			nextValisSet = midPtr[nextY][nextX].isSet;
			nextLocIsValid = (nextX >= leftLimit && nextX <= rightLimit && nextY >= topLimit && nextY <= downLimit);
		} while(nextValisSet == false && nextLocIsValid == true);


		if (isCCW == true) {
			switch (currentDirection) {
				case LEFT:
					currentDirection = UP;
					break;
				case UP:
					currentDirection = RIGHT;
					break;
				case RIGHT:
					currentDirection = DOWN;
					break;
				case DOWN:
					currentDirection = LEFT;
					break;
			}
		}
		else {
			switch (currentDirection) {
				case LEFT:
					currentDirection = UP;
					break;
				case UP:
					currentDirection = RIGHT;
					break;
				case RIGHT:
					currentDirection = DOWN;
					break;
				case DOWN:
					currentDirection = LEFT;
					break;
			}
		}

	} while (nextValisSet == false && numValSet <= xSize * ySize);



	//Convert back to a normal array
	uint_fast64_t ** output = new uint_fast64_t * [ySize];
	for (uint_fast64_t y = 0; y < ySize; y++) {
		output[y] = new uint_fast64_t [xSize];
		for (size_t x = 0; x < xSize; x++) {
			output[y][x] = midPtr[y][x].num;
		}
	}
	//Deallocates the array created for generation
	delete[] midPtr;
}

void stdToSpiralBool (uint_fast64_t xSize, uint_fast64_t ySize, bool ** ogPtr, bool isCCW, bool startAtTop, bool startAtLeft){
	//These might slow code down a little, but they make coding a bit easier
	uint_fast64_t leftLimit = 0;
	uint_fast64_t topLimit = 0;
	uint_fast64_t downLimit = ySize - 1;
	uint_fast64_t rightLimit = xSize - 1;


	boolAndBool ** midPtr = new boolAndBool * [ySize];
	for (uint_fast64_t y = 0; y < ySize; y++) {
		midPtr[y] = new boolAndBool [xSize];
		for (uint_fast64_t x = 0; x < xSize; x++) {
			midPtr[y][x].isSet = false;
		}
	}




	uint_fast64_t nextX;
	uint_fast64_t nextY;
	bool nextLocIsValid;
	bool nextValisSet;
	uint_fast64_t numValSet = 0;


	uint_fast64_t currentX;
	uint_fast64_t currentY;
	direction currentDirection;
	if (startAtLeft == true) {
		currentX = 0;
		if (startAtTop == true) {
			currentY = 0;
			if (isCCW == true) {
				currentDirection = DOWN;
			}
			else{
				currentDirection = RIGHT;
			}
		}
		else{
			currentY = downLimit;
			if (isCCW == true) {
				currentDirection = RIGHT;
			}
			else{
				currentDirection = UP;
			}
		}
	}
	else{
		currentX = rightLimit;
		if (startAtTop == true) {
			currentY = 0;
			if (isCCW == true) {
				currentDirection = LEFT;
			}
			else{
				currentDirection = DOWN;
			}
		}
		else{
			currentY = downLimit;
			if (isCCW == true) {
				currentDirection = UP;
			}
			else{
				currentDirection = LEFT;
			}
		}
	}



	do {
		do {
			midPtr[currentY][currentX].num = ogPtr[currentY][currentX];
			midPtr[currentY][currentX].isSet = true;
			numValSet = numValSet + 1;


			switch (currentDirection) {
				case LEFT:
					nextX = currentX - 1;
					nextY = currentY;
					break;
				case UP:
					nextX = currentX;
					nextY = currentY - 1;
					break;
				case RIGHT:
					nextX = currentX + 1;
					nextY = currentY;
					break;
				case DOWN:
					nextX = currentX;
					nextY = currentY + 1;
					break;
			}

			currentX = nextX;
			currentY = nextY;
			nextValisSet = midPtr[nextY][nextX].isSet;
			nextLocIsValid = (nextX >= leftLimit && nextX <= rightLimit && nextY >= topLimit && nextY <= downLimit);
		} while(nextValisSet == false && nextLocIsValid == true);


		if (isCCW == true) {
			switch (currentDirection) {
				case LEFT:
					currentDirection = DOWN;
					break;
				case UP:
					currentDirection = LEFT;
					break;
				case RIGHT:
					currentDirection = UP;
					break;
				case DOWN:
					currentDirection = RIGHT;
					break;
			}
		}
		else {
			switch (currentDirection) {
				case LEFT:
					currentDirection = UP;
					break;
				case UP:
					currentDirection = RIGHT;
					break;
				case RIGHT:
					currentDirection = DOWN;
					break;
				case DOWN:
					currentDirection = LEFT;
					break;
			}
		}
		nextValisSet = midPtr[nextY][nextX].isSet;
	} while (nextValisSet == false && numValSet <= xSize * ySize);



	//Convert back to a normal array
	for (uint_fast64_t y = 0; y < ySize; y++) {
		for (size_t x = 0; x < xSize; x++) {
			ogPtr[y][x] = midPtr[y][x].num;
		}
	}
	//Deallocates the array created for generation
	delete[] midPtr;
}


void stdToCCWSpiralBool2 (uint_fast64_t xySize, bool ** ogPtr){
	uint_fast64_t xLoc = xySize - 1;
	uint_fast64_t yLoc = xySize - 1;

	bool* sinPtr = new bool [xySize * xySize];
	for (uint_fast64_t y = 0; y < xySize; y++) {
		for (uint_fast64_t x = 0; x < xySize; x++) {
			sinPtr[y * x] = ogPtr[y][x];
		}
	}


	bool ** midPtr = new bool * [xySize];
	for (uint_fast64_t y = 0; y < xySize; y++) {
		midPtr[y] = new bool [xySize];
	}


	uint_fast64_t locNum = 0;
	uint_fast64_t currentDist = xySize;
	do {
		currentDist--;
		for (uint_fast64_t i = 0; i < currentDist; i++) {
			midPtr[yLoc][xLoc] = sinPtr[locNum];
			xLoc--;
			locNum++;
		}
		for (uint_fast64_t i = 0; i < currentDist; i++) {
			midPtr[yLoc][xLoc] = sinPtr[locNum];
			yLoc--;
			locNum++;
		}
		for (uint_fast64_t i = 0; i < currentDist; i++) {
			midPtr[yLoc][xLoc] = sinPtr[locNum];
			xLoc++;
			locNum++;
		}
		for (uint_fast64_t i = 0; i < currentDist - 1; i++) {
			midPtr[yLoc][xLoc] = sinPtr[locNum];
			yLoc++;
			locNum++;
		}
	} while (currentDist > 1);
	//center

	for (uint_fast64_t i = 0; i < xySize; i++) {
		delete[] ogPtr[i];
	}
	delete[] ogPtr;
	delete[] sinPtr;
}

void stdToCCWSpiralBool3 (uint_fast64_t xySize, bool ** ogPtr) {
	bool ** newPtr = new bool * [xySize];
	for (uint_fast64_t i = 0; i < xySize; i++) {
		newPtr[i] = new bool [xySize];
	}



	uint_fast64_t currentX = 0; // current position; currentX
	uint_fast64_t currentY = 0; // current position; currentY
	uint_fast64_t d = 0; // current direction; 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
	uint_fast64_t c = 0; // counter
	uint_fast64_t s = 1; // chain size

	// starting point
	currentX = static_cast<long double>(floor(static_cast<long double>(xySize) / 2.0)) - 1;
	currentY = static_cast<long double>(floor(static_cast<long double>(xySize) / 2.0)) - 1;

	for (uint_fast64_t k = 1; k <= (xySize - 1); k++) {
		for (uint_fast64_t j = 0; j < ( k < (xySize - 1) ? 2 : 3); j++) {
			for (uint_fast64_t i = 0; i < s; i++) {
				newPtr[currentX][currentY] = ogPtr[currentX][currentY];
				c++;
				cout << "mark_----------------" << endl;
				switch (d) {
						case 0: currentY = currentY + 1;
					break;
						case 1: currentX = currentX + 1;
					break;
						case 2: currentY = currentY - 1;
					break;
						case 3: currentX = currentX - 1;
					break;
				}
			}
			d = (d + 1) % 4;
			cout << "end innerloop" << endl;
		}
		s = s + 1;
		cout << "end midloop" << endl;
	}
	cout << "prewipe" << endl;
	for (uint_fast64_t i = 0; i < xySize; i++) {
		delete[] ogPtr[i];
	}
	delete[] ogPtr;
	ogPtr = newPtr;
}
