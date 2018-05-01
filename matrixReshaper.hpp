#if !defined MATRIX_RESHAPER
	#define MATRIX_RESHAPER

	#include <cstdint>




	/*
		Assuming inputs are valid it should(tm) give no errors...

		Takes in a 2D array of uint_fast64_t numbers and returns a pointer to a new 2d array of uint_fast64_t numbers
		Can be set to Clockwise or counter clockwise and starting corner can be set

		remember to delete arrays!
	*/
	void stdToSpiralUfast64 (uint_fast64_t xSize, uint_fast64_t ySize, uint_fast64_t ** ogPtr, bool isCCW = false, bool startAtTop = false, bool startAtLeft = false);

	void stdToSpiralBool (uint_fast64_t xSize, uint_fast64_t ySize, bool ** ogPtr, bool isCCW = false, bool startAtTop = false, bool startAtLeft = false);

	void stdToCCWSpiralBool2 (uint_fast64_t xySize, bool ** ogPtr);

	bool** single2D_Bool (uint_fast64_t xySize, bool * ogPtr);

	void singleReverse_Bool (uint_fast64_t size, bool * ogPtr);

	void stdToCCWSpiralBool3 (uint_fast64_t xySize, bool ** ogPtr);

	void stdToCCWSpiralBool4 (uint_fast64_t xySize, bool ** ogPtr);

#endif
