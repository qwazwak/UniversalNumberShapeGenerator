#if !defined PRIME_FINDER
	#define PRIME_FINDER

	//#include <boost/multiprecision/cpp_int.hpp>
	#include <cstdint>


	/*
		Pre:
		Post:
	*/

	bool ** make2DPrimeArray (uint_fast64_t ySize, uint_fast64_t xSize, int NUM_OF_TESTS = 16);

	bool * make1DPrimeArray (uint_fast64_t numLimit, int NUM_OF_TESTS = 16);

#endif
