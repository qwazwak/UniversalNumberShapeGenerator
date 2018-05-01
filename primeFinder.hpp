#if !defined PRIME_FINDER
	#define PRIME_FINDER


	#include <string>
	#include <boost/multiprecision/cpp_int.hpp>

	#include <cstdint>




	/*
		Pre:
		Post:
	*/

	bool ** make2DPrimes (uint_fast64_t ySize, uint_fast64_t xSize, int NUM_OF_TESTS = 16);

	bool ** makeFindPrimes (uint_fast64_t ySize, uint_fast64_t xSize, uint_fast64_t ** inputPtr, int NUM_OF_TESTS = 16);

	bool writePrimeFile (uint_fast64_t numCount, bool * primalityAry, std::string filename = "primeFile.txt");

	bool * makeFindPrimes (uint_fast64_t numLimit, int NUM_OF_TESTS = 16);

	bool genWritePrimeFile (uint_fast64_t numCount, std::string filename = "primeFile.txt", int NUM_OF_TESTS = 16);


#endif
