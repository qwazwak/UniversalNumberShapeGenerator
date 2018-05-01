#include "primeFinder.hpp"


#include <random>

//Prime tester from boost
#include <boost/multiprecision/miller_rabin.hpp>

#include <quadmath.h> //required for the boost float 128

//#include <gmp.h>
//#include <boost\multiprecision\gmp.hpp> //Sister to cppint, but floating, also fixes some of cppint's erros

#include <boost/multiprecision/float128.hpp> //very precision float for shading
//	boost::multiprecision::float128 variableName;
#include <boost/multiprecision/cpp_int.hpp> //Needed for absoluly huge resolution images (This program should have no problems generating over 100x gigapixel images)
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


bool writePrimeFile (uint_fast64_t numCount, bool * primalityAry, string filename){
	bool hasErrored = false;
	ofstream primeFile;
	primeFile.open(filename);
	for (uint_fast64_t i = 0; i < numCount; i++) {
		primeFile << primalityAry[i] << endl;
		if (!hasErrored && primeFile.fail()) {
			hasErrored = true;
		}
	}
	return hasErrored;
}



bool ** make2DPrimes (uint_fast64_t ySize, uint_fast64_t xSize, int NUM_OF_TESTS){
	random_device realRandom;
	uint_fast64_t seed = time(NULL);
	if (realRandom.entropy() != 0) {
		seed = realRandom();
	}
	mt19937_64 primeTesterGenerator(seed);

	uint_fast64_t checking;
	bool ** newPtr = new bool *[ySize];
	for (uint_fast64_t y = 0; y < ySize; y++) {
		newPtr[y] = new bool[xSize];
		for (uint_fast64_t x = 0; x < xSize; x++) {
			checking = ((y + 1) * xSize) + (x + 1);
			if (checking % 2 == 0) {
				if (checking != 2) {
					newPtr[y][x] = false;
				}
				else{
					newPtr[y][x] = true;
				}
			}
			else if (boost::multiprecision::miller_rabin_test(checking, NUM_OF_TESTS, primeTesterGenerator) == false) {
				newPtr[y][x] = false;
			}
			else{
				newPtr[y][x] = true;
				for (uint_fast64_t x = 0; x < static_cast<uint_fast64_t>(ceil(sqrt(static_cast<long double>(x)))); x++) {
					if ((static_cast<double>(checking) / static_cast<double>(x)) == floor(static_cast<double>(checking) / static_cast<double>(x))) {
						newPtr[y][x] = false;
					}
				}
			}
		}
	}
	return newPtr;
}



bool * makeFindPrimes (uint_fast64_t numLimit, int NUM_OF_TESTS){
	random_device realRandom;
	uint_fast64_t seed = time(NULL);
	if (realRandom.entropy() != 0) {
		seed = realRandom();
	}
	mt19937_64 primeTesterGenerator(seed);

	bool * aryPtr = new bool[numLimit];
	for (uint_fast64_t i = 0; i < numLimit; i++) {
		if ((i + 1) % 2 == 0) {
			if ((i + 1) == 2) {
				aryPtr[i] = true;
			}
			else{
				aryPtr[i] = false;
			}
		}
		else if (boost::multiprecision::miller_rabin_test(i + 1, NUM_OF_TESTS, primeTesterGenerator) == false) {
			aryPtr[i] = false;
		}
		else{
			aryPtr[i] = true;
			for (uint_fast64_t x = 0; x < static_cast<uint_fast64_t>(ceil(sqrt(static_cast<long double>(x)))); x++) {
				if ((static_cast<double>(i + 1) / static_cast<double>(x)) == floor(static_cast<double>(i + 1) / static_cast<double>(x))) {
					aryPtr[i] = false;
				}
			}
		}
	}
	return aryPtr;
}


bool genWritePrimeFile (uint_fast64_t numCount, string filename, int NUM_OF_TESTS){
	bool hasErrored = false;
	hasErrored = writePrimeFile (numCount, makeFindPrimes (numCount, NUM_OF_TESTS), filename);
	return hasErrored;
}
