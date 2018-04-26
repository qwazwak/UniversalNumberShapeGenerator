/*




*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)


//Current file writing library

//GUI engine:
/*
#include <imGUI/imgui.cpp>
#include <imGUI/imgui.h>
#include <imGUI/imgui_demo.cpp>
#include <imGUI/imgui_draw.cpp>
#include <imGUI/imgui_internal.h>
#include <imGUI/imconfig.h>
#include <imGUI/stb_rect_pack.h>
#include <imGUI/stb_textedit.h>
#include <imGUI/stb_truetype.h>
*/

//getopt.h is required for the getopt function
#include <getopt.h>

//required for the boost float 128
#include <quadmath.h>
//very precision float for shading
#include <boost/multiprecision/float128.hpp>
/*
	boost::multiprecision::float128 variableName;
*/

//Needed for absoluly huge resolution images (This program should have no problems generating over 100x gigapixel images)
#include <boost/multiprecision/cpp_int.hpp>
/*
	// Fixed precision unsigned inegers:
		boost::multiprecision::uint128_t
		boost::multiprecision::uint256_t
		boost::multiprecision::uint512_t
		boost::multiprecision::uint1024_t
	// Fixed precision signed inegers:
		boost::multiprecision::int128_t
		boost::multiprecision::int256_t
		boost::multiprecision::int512_t
		boost::multiprecision::int1024_t
*/

#include <gmp.h>

//Sister to cppint, but floating, also fixes some of cppint's erros
#include <boost\multiprecision\gmp.hpp>


//#include <vector>
/*
		Vectors:
		ONE DATA TYPE
		Varibale size

		format:
			vector <DATA TYPE HERE> VARIABLE NAME; //initial zero sized
			vector <DATA TYPE HERE> VARIABLE NAME (INITIALSIZE); //sized with INITIALSIZE size
			vector <DATA TYPE HERE> VARIABLE NAME (INITIALSIZE, OGVARIABLE); //all vals are OGVARIABLE at first
			vector <DATA TYPE HERE> VARIABLE NAME (anothervectorname); //othervectorname is copyed to the new one

		Access/assign:
			myvector[i]



		VECTORNAME.push_back(NUMBER)
			puts somthing at the end of a vector
		VECTORNAME.clear()
			clears vector
		VECTORNAME.size()
			gets size
		VECTORNAME.empty()
			If empty returns a one/true
		VECTORNAME.at(i)
			returns value of ith entry
		VECTORNAME.capacity()
			current max size
		VECTORNAME.reverse()
			reverse orders entries
		VECTORNAME.resize (i, val)
			adds I spaces to vector, and optinally initialzes to val
		VECTORNAME.swap(OTHERVECTORNAME);
			swaps two vectors contents
*/


//#include <windows.h>
/*
	Directories:
		LPCWSTR FOOBARDIRECTERY = L"c:\testdir";
		CreateDirectory(FOOBARDIRECTERY, NULL);
		CreateDirectory("output", NULL);

	consoleThings:

		SetConsoleTextAttribute(hConsole, k);
				HANDLE  hConsole;
				int k;
			Sets console colours
			colorattribute = foreground + (background * 16)
				colors are:
					0: Black
					1: Navy
					2: Dark green
					3: Teal
					4: Burgundy
					5: Burgundy, but with 10 blue because why not
					6: Olive
					7: Slightly Grey
					8: Grey
					9: BSOD Blue
					10: Lime Green
					11: Cyan
					12: Really Red
					13: Pink
					14: Yellow
					15: Nearly White
	Dialog:
		https://msdn.microsoft.com/en-us/library/windows/desktop/ms645505(v=vs.85).aspx
		MessageBox( 0, "Hello World!", "Greetings", 0 );
		MessageBox( NULL, AcutalBodyMessage, Title, TypeTHingInt );

			int msgboxID = MessageBox(
				NULL,
				"Resource not available\nDo you want to try again?",
				"Account Details",
				MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
			);


*/


//#include <ctime>
/*
	http://www.cplusplus.com/reference/ctime/

	Macro:
		CLOCKS_PER_SEC

	seconds = clock() / CLOCKS_PER_SEC

	unsigned int start = clock();
	cout << "waiting for keyhit";
	cin.ignore();
	cout << "Time taken in millisecs: " << clock()-start;
*/


//#include <random>
//All of this library is c++11 and requires compiler support
/*
	C++11
	random_device FOOBARNAMEME;
	cout << "Minumum: " << FOOBARNAMEME.min() << endl;
	cout << "Maximum: " << FOOBARNAMEME.max() << endl;
	cout << "Entropy: " << FOOBARNAMEME.entropy() << endl;
	This is real random. Only use it to seed a pseduo random generator - SEE cstdlib and rand()




		random_device rd; //call random numbers with rd()
		int seed = rd() * clock()
		mt19937_64 generator(seed);  // mt19937 is a standard mersenne_twister_engine
		srand(seed);
		Call randoms with generator() or rand()

		cout << "Seed: " << seed << endl;
		cout << "Minimum: " << rd.min() << endl;
		cout << "Maximum: " << rd.max() << endl;
		cout << "Entropy: " << rd.entropy() << endl;
		cout << "setup done" << endl;
*/


#include <cstdint>
//All of this library is c++11 and requires compiler support
/*
	C++11
	What it adds:
		Signed maximum width integer type
			intmax_t
		Maximum width unsigned integer type
			uintmax_t

		Integer with width of exactly 8, 16, 32 and 64 bits respectively with no padding bits and using 2's complement for negative values
		(provided only if the implementation directly supports the type)
			Signed:
				int8_t
				int16_t
				int32_t
				int64_t
			Unsigned:
				uint8_t
				uint16_t
				uint32_t
				uint64_t

		Fastest integer type with width of at least 8, 16, 32 and 64 bits respectively
			Signed:
				int_fast8_t
				int_fast16_t
				int_fast32_t
				int_fast64_t
			Unsigned:
				uint_fast8_t
				uint_fast16_t
				uint_fast32_t
				uint_fast64_t

		Smallest integer type with width of at least 8, 16, 32 and 64 bits respectively
			Signed:
				int_least8_t
				int_least16_t
				int_least32_t
				int_least64_t
			Unsigned:
				uint_least8_t
				uint_least16_t
				uint_least32_t
				uint_least64_t

		Constants: (max value)
			INTMAX_MAX
			INT8_MAX
			INT16_MAX
			INT32_MAX
			INT64_MAX
			INT_FAST8_MAX
			INT_FAST16_MAX
			INT_FAST32_MAX
			INT_FAST64_MAX
			INT_LEAST8_MAX
			INT_LEAST16_MAX
			INT_LEAST32_MAX
			INT_LEAST64_MAX
*/


#include <cstdlib>
/*
	Quicksort:
		qsort (SOURCEARRAY, NumberOfElements, SizeOfEachElementInBytes/sizeof(int), compareMyType);

		Outside main you must make a fucnction that quicksort references when checking how things are related
			prototype
				int compar (const void* p1, const void* p2);
			Actuall function:
				int compareMyType (const void * a, const void * b){
					if( *(MyType*)a <  *(MyType*)b ){
						return -1;
					}
					if( *(MyType*)a == *(MyType*)b ){
						return 0;
					}
					if( *(MyType*)a >  *(MyType*)b ){
						return 1;
					}
				}
			What returns do:
				<0	p1 goes before p2
				0	p1 is the same as p2
				>0	p1 goes after p2

		The actual call to quicksort:
			qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
				Parameters
					base
						Pointer to the first object of the array to be sorted, converted to a void*.
					num
						Number of elements in the array pointed to by base.
						size_t is an unsigned integral type.
					size
						Size bytes of each element in the array.
						size_t is an unsigned integral type.
					compar
						Pointer to a function that compares two elements.
						This function is called repeatedly by qsort to compare two elements. It shall follow the following prototype:


	random:
		srand(SEEDGOESHERE);
			seed sources:
				time(NULL)

				if c++ 11 is avalible use a real random generator to seed
		rand() to generate random numbers


	String to XXX Conversions:
		To use these the format is VARIABLEWITHTARGETTYPE = functionName(SOURCEVARIABLE)
			atof
				Convert string to double (function )
			atoi
				Convert string to integer (function )
			atol
				Convert string to long integer (function )
			atoll
				C++11
				Convert string to long long integer (function )
			strtod
				Convert string to double (function )
			strtof
				C++11
				Convert string to float (function )
			strtol
				Convert string to long integer (function )
			strtold
				C++11
				Convert string to long double (function )
			strtoll
				C++11
				Convert string to long long integer (function )
			strtoul
				Convert string to unsigned long integer (function )
			strtoull
				C++11
				Convert string to unsigned long long integer (function )
*/


//#include <time.h>
/*
	Has more, all I use is:
	VARIABLE = time(NULL);
*/


#include <iostream>
/*
	system("pause")
		Enter any key to continue..
	cout << "" << endl;
		output things
	cin >> VARNAME;
		Bring in numbers
	cin.get(VARNAME);
		Single Char
	getline(cin, VARNAME);
		get a line
*/


#include <iomanip>
/*
	Manipulates input and output
	cout << setprecision(2) << fixed << showpoint;
	cout << minumum decimal points(VARIABLE OR NUMBER) << cutoff decimal points? << show decimal point always;
*/


//#include <fstream>
/* i/ofstream info
	(i or o)fstream FILEIDENT;
	FILEIDENT.open("FILENAME.txt");
	FILEIDENT << VARIABLE << endl;
	FILEIDENT.close();

	General:
		foobar_recognizablename.open(stringVariableName.c_str());



		bar_recognizablename.open("foo/bar_Input.txt");
			Will open file for reading, file must exist to work
		foo_recognizablename.open("bar/foo_Output.txt");
			Will create file, if it already exists it will be deleted and overwritten
		if(!bar_recognizablename){HAPPENS IF ERROR}
			For input validation, you can use infile.fail()

		Closing files:
			bar_recognizablename.close();
			foo_recognizablename.close();
	Input:
		bar_recognizablename >> myVariable;
			Can be used for boolean.. [foo/bar_Input >> myVariable] returns true when it works


	Output:
		foo_recognizablename << "Thing happened" << endl;


	if(!IDENFIFIERWHATEVERYOUWANT){
		happens if it didnt open correctly
	}
*/

#include <cstring>
#include <string>
#include <cmath>

using namespace std;

//Hardcoded max limit for pixel count, currently 50 Petapixels
//const boost::multiprecision::cpp_int::int512_t MAXRES = 50000000000000000;
int main (int argc, char* argv[]){
	//Variable Creation
		//variables created here are used all over
		boost::multiprecision::uint512_t edgeResolution;


		bool enableDebugOutput = false;
		bool resolutionIsSet = false;
		bool filenameIsSet = false;
		string outputFileName = "ulam_spiral.bmp";

	//Variables created
	//Argument Parsing:
	{
		boost::multiprecision::uint512_t currentEdgeResolution = 0;
		boost::multiprecision::uint512_t possibleEdgeResolution = 0;
		extern char *optarg;
		char argSwitcher;
		bool continueLoading = true;
		do {
			//Argument meanings:
			// h: help
			// d: debug
			// f XXX: output filename
			// r: resolution (pixel edge)
			// m: minimum max prime
			argSwitcher = getopt(argc, argv, "hdf:r:m:e:");
			if (argSwitcher == -1) {
				continueLoading = false;
				break;
			}
			else {
				switch (argSwitcher) {
					case 'h':
						cout << "Portable Ilam Spiral Generator Help and Info:" <<
						endl <<
						endl << "Main use:" <<
						endl << "     Just art the program" <<
						endl << "     arguments are optional ways of speeding up generation" <<
						endl <<
						endl << "Arguments:" <<
						endl << "-h" <<
						endl << "     Opens this help menu" << endl <<
						endl << "-d" <<
						endl << "     Enables debug output" << endl <<
						endl << "-f XXXXXXXX" <<
						endl << "     Specify the output file name" <<
						endl << "otherwise defaults to ulamOutput_TIMECREATED.bmp" << endl <<
						endl << "-r" <<
						endl << "     Specifies minimum output resolution" << endl <<
						endl << "-m" <<
						endl << "     Specifies minimum maximum prime number" << endl <<
						endl;

						return EXIT_SUCCESS;
						break;
					case 'd':
						if (enableDebugOutput == true) {
							cout << "Warning: '-d' (debug) argument entered multiple times" <<
							endl << "          It's fine, but don't keep it up" << endl;
						}
						enableDebugOutput = true;
						break;
					case 'f':
						if (filenameIsSet == true) {
							cout << "Warning: '-f' (filename) argument entered multiple times" <<
							endl << "          using only the first appearance" << endl;
						}
						else{
							outputFileName = optarg;
							filenameIsSet = true;
						}
						break;
					case 'r':
						possibleEdgeResolution = static_cast<boost::multiprecision::uint512_t>(atoi(optarg));
						if (possibleEdgeResolution % 2 == 0) {
							possibleEdgeResolution = possibleEdgeResolution + 1;
						}
						if (resolutionIsSet == true) {
							if (possibleEdgeResolution > currentEdgeResolution) {
								currentEdgeResolution = possibleEdgeResolution;
							}
							cout << "Resolution has already been set..." <<
							endl << "using the resolution of: " << currentEdgeResolution << "x" << currentEdgeResolution << endl;
							resolutionIsSet = true;
						}
						else {
							currentEdgeResolution = possibleEdgeResolution;
							cout << "Using the resolution of: " << possibleEdgeResolution << "x" << possibleEdgeResolution << endl;
							resolutionIsSet = true;
						}
						break;
					case 'm':
						possibleEdgeResolution = static_cast<boost::multiprecision::uint512_t >(
											ceil(
												sqrt(
													static_cast<boost::multiprecision::mpf_float_1000>(
														atoi(optarg)
													))));
						if (possibleEdgeResolution % 2 = 0) {
							possibleEdgeResolution = possibleEdgeResolution + 1;
						}
						if (resolutionIsSet == true) {
							if (possibleEdgeResolution > currentEdgeResolution) {
								currentEdgeResolution = possibleEdgeResolution;
							}
							cout << "Resolution has already been set..." <<
							endl << "     using the resolution of: " << currentEdgeResolution << "x" << currentEdgeResolution << endl;
							resolutionIsSet = true;
						}
						else {
							currentEdgeResolution = possibleEdgeResolution;
							cout << "Using the resolution of: " << possibleEdgeResolution << "x" << possibleEdgeResolution << endl;
							resolutionIsSet = true;
						}
						break;
					case 'e':




						break;
					case '?':
					default:
						cout << endl << "Invalid argument: " << optarg << "Exiting Program" << endl;
						return EXIT_FAILURE;
						break;
				}
			}
		} while (continueLoading == true);
		edgeResolution = currentEdgeResolution;
	}
	//End argument parsing



	for (long i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0 ) {

			cout << "help" << endl;

		}
	}
	//TODO: Add launch by commandline argument(s) option
	//NOTE: Arguments: resolution or max value, res/maxval, output filename, shadded or discrete,

	//Deal with arguments here..
cout << outputFileName;


	cout << "Press enter to close program..." << endl;
	cin.ignore();
	return EXIT_SUCCESS;
}
