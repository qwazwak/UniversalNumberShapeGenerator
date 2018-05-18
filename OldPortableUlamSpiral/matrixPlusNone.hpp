#if !defined MATRIX_PLUS_NONE
	#define MATRIX_PLUS_NONE

	#include <cstdint>

	using CHANGEMEVARIABLE = int_fast64_t;
	using arraySizeAndForLoopVariableType = int_fast64_t;

	/*enum varTypeVar {
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

	enum direction {UP, DOWN, LEFT, RIGHT};


	struct uint_fast64_tAndBool {
		uint_fast64_t num;
		bool isSet;
	};
	struct boolAndBool {
		bool num;
		bool isSet;
	};
*/
	/*
		Assuming inputs are valid it should(tm) give no errors... maybe
		Takes in a 1D array of <VALUES> and a pointer array of pointer array things (2D array in hap memory) and must already be allocated
		fills the 2d array with the 1D values in a spiral shape starting at the top left goign clockwise
		NOTE: be careful! If you want (ex) a 3x3 matrix your input array MUST have ATLEAST 9 values, otherwise bad things will happen
		remember to delete arrays!

		supprts these variables:
			int_fast64_t
			bool
	*/
	void createSpiral(int_fast64_t * arr, int_fast64_t ** mat, arraySizeAndForLoopVariableType ySize, arraySizeAndForLoopVariableType xSize);
	void createSpiral(bool * arr, bool ** mat, arraySizeAndForLoopVariableType ySize, arraySizeAndForLoopVariableType xSize);


	/*
		Assuming inputs are valid it should(tm) give no errors...
		Takes in a 2D array and prints it.
	*/
//	void printMatrix(uint_fast64_t ** ogPtr, varTypeVar varType, uint_fast64_t xSize, uint_fast64_t ySize);

	/*
		Assuming inputs are valid it should(tm) give no errors...

		Takes in a 2D array of <VALUES> and returns a pointer to a new 2d array of <values>
		Starting in the top left going clockwise

		remember to delete arrays!
	*/
	uint_fast64_t ** generateSpiral_UINT_FAST64_T(uint_fast64_t ** inputMatrix, uint_fast64_t ySize, uint_fast64_t xSize);

	void universalSemiReverse (int_fast64_t * ogPtr, uint_fast64_t size);
	void universalSemiReverse (uint_fast64_t * ogPtr, uint_fast64_t size);
	void universalSemiReverse (bool * ogPtr, uint_fast64_t size);

#endif
