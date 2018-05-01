const int NUM_OF_TESTS = 16;

#include "primeFinder.hpp"
#include "matrixReshaper.hpp"

//Current file writing library
//#include <CImg\CImg.h>
#include <EasyBMP/EasyBMP.h>

//GUI engine:
/*
#include <imGUI/imgui.h>
//#include <imGUI/imgui_internal.h>
//#include <imGUI/imconfig.h>
//#include <imGUI/stb_rect_pack.h>
//#include <imGUI/stb_textedit.h>
//#include <imGUI/stb_truetype.h>
*/



//getopt.h is required for the getopt function
#include <getopt.h>
//Large size variables
#include <quadmath.h> //required for the boost float 128

//#include <gmp.h>
//#include <boost/multiprecision/gmp.hpp> //Sister to cppint, but floating, also fixes some of cppint's erros

#include <boost/multiprecision/float128.hpp> //very precision float for shading
//	boost::multiprecision::float128 variableName;
#include <boost/multiprecision/cpp_int.hpp> //Needed for absoluly huge resolution images (This program should have no problems generating over 100x gigapixel images)
/*		boost::multiprecision::uint128_t
		boost::multiprecision::uint256_t
		uint_fast64_t
		boost::multiprecision::uint1024_t
		boost::multiprecision::int128_t
		boost::multiprecision::int256_t
		boost::multiprecision::int512_t
		boost::multiprecision::int1024_t*/




#include <cstdlib>
#include <random>

#include <iostream>
#include <iomanip>

#include <cstdint>
#include <cmath>
#include <cstring>
#include <string>

//Libraries maybe needed, possibly for debug/logging
//#include <time.h>
#include <fstream>
#include <ctime>


using namespace std;




//Hardcoded max limit for pixel count, currently 50 Petapixels
//const boost::multiprecision::cpp_int::int512_t MAXRES = 50000000000000000;
int main (int argc, char* argv[]){
	//Variable Creation
		//variables created here are used all over


			uint_fast64_t edgeResolution;
			uint_fast64_t numberOfNumbers;

		//Flags:
			bool enableDebugOutput = false;
			bool resolutionIsSet = false;
			bool externalDataLoading = false;
			//bool isShaded = false;
			bool filenameIsSet = false;

		//File/Image Things:
			BMP mainImage;
			//RGBApixel pixelWriter;
			RGBApixel blackPix;
			RGBApixel whitePix;
			blackPix.Red = 0;
			blackPix.Blue = 0;
			blackPix.Green = 0;
			whitePix.Alpha = 255;
			whitePix.Red = 255;
			whitePix.Blue = 255;
			whitePix.Green = 255;
			whitePix.Alpha = 255;
			//pixelWriter.Alpha = 255;
			string inputDataFileName;
			string outputFileName = "ulam_spiral.bmp";

		//This library is so difficult cimg_library::CImg<int> cimage;


	//Variables created

	{//Argument Parsing:
		uint_fast64_t possibleEdgeResolution = 0;
		extern char *optarg;
		char argSwitcher;
		bool continueLoading = true;
		do {
			//Argument meanings:
			// h: help
			// d: debug
			// f: output filename
			// r: resolution (pixel edge)
			// s: is shaded?
			// m: minimum max prime
			// e: external data input
			argSwitcher = getopt(argc, argv, "hdf:r:m:e:o:");
			if (argSwitcher == -1) {
				continueLoading = false;
				break;
			}
			else {
				switch (argSwitcher) {
				//	case 's':
				//		isShaded = true;
				//		break;
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
						possibleEdgeResolution = static_cast<uint_fast64_t>(atoi(optarg));
						if (possibleEdgeResolution % 2 == 0) {
							possibleEdgeResolution = possibleEdgeResolution + 1;
						}
						if (resolutionIsSet == true) {
							if (possibleEdgeResolution > edgeResolution) {
								edgeResolution = possibleEdgeResolution;
							}
							cout << "Resolution has already been set..." <<
							endl << "using the resolution of: " << edgeResolution << "x" << edgeResolution << endl;
							resolutionIsSet = true;
						}
						else {
							edgeResolution = possibleEdgeResolution;
							cout << "Using the resolution of: " << possibleEdgeResolution << "x" << possibleEdgeResolution << endl;
							resolutionIsSet = true;
						}
						break;
					case 'm':
						possibleEdgeResolution = static_cast<uint_fast64_t >(
											ceil(
												sqrt(
													static_cast<long double>(
														atoi(optarg)
													))));
						if (possibleEdgeResolution % 2 == 0) {
							possibleEdgeResolution = possibleEdgeResolution + 1;
						}
						if (resolutionIsSet == true) {
							if (possibleEdgeResolution > edgeResolution) {
								edgeResolution = possibleEdgeResolution;
							}
							cout << "Resolution has already been set..." <<
							endl << "     using the resolution of: " << edgeResolution << "x" << edgeResolution << endl;
							resolutionIsSet = true;
						}
						else {
							edgeResolution = possibleEdgeResolution;
							cout << "Using the resolution of: " << possibleEdgeResolution << "x" << possibleEdgeResolution << endl;
							resolutionIsSet = true;
						}
						break;
					case 'e':
						//set loading of external data
						if (externalDataLoading == false) {
							inputDataFileName = optarg;
							externalDataLoading = true;
						}
						else {
							int userOption;
							cout << "External dataset file name is already set.." <<
							endl << "  Enter the number of the name you want:" <<
							endl << "      0.  <enter new name>" <<
							endl << "      1.  " << inputDataFileName <<
							endl << "      2.  " << optarg <<
							endl << ":" << endl;
							cin >> userOption;
							while (cin.fail() || !(userOption == 0 || userOption == 1 || userOption == 2)) {
								if (cin.fail()) {
									cin.ignore();
									cin.clear();
								}
								cout << "External dataset file name is already set.." <<
								endl << "  Enter the number of the name you want:" <<
								endl << "      0.  <enter new name>" <<
								endl << "      1.  " << inputDataFileName <<
								endl << "      2.  " << optarg <<
								endl << ":";
								cin >> userOption;
							}
							//User choice is validated. options are:
								//0: new file namespace
								//1: ise original inputDataName
								//2: use new input
							switch (userOption) {
								case 0:
									do {
										cout << "Enter new filename, without extention or spaces" <<
										endl << "  only supports XXX.txt files without spaces in the name" <<
										endl << "  with each number on its own line" <<
										endl << "   ex:" <<
										endl << "      File name: primeNumbers.txt" <<
										endl << "      You type:  primeNumbers" <<
										endl << "      Contents:" <<
										endl << "         1" <<
										endl << "         1" <<
										endl << "         2" <<
										endl << "         3" <<
										endl << "         ..." <<
										endl <<
										endl;
										getline(cin, inputDataFileName);
									} while (cin.fail());
									break;
								case 2:
									inputDataFileName = optarg;
								case 1:
									break;
								default:
									cout << "An unexpected error has occured, exiting program" << endl;
									return EXIT_FAILURE;
								break;
							}

						}






						break;
					case '?':
					default:
						cout << endl << "Invalid argument: " << optarg << "Exiting Program" << endl;
						return EXIT_FAILURE;
						break;
				}
			}
		} while (continueLoading == true);
	}//End argument parsing

	numberOfNumbers = edgeResolution * edgeResolution;

	mainImage.SetBitDepth(24);
	mainImage.SetSize(edgeResolution, edgeResolution);

	cout << "PostBackground" << endl;

	//bool * singlePrimalityAry = makeFindPrimes (numberOfNumbers, NUM_OF_TESTS);
	//singleReverse_Bool (numberOfNumbers, singlePrimalityAry);
	cout << "post reverse" << endl;
	//bool ** doublePrimalityAry = single2D_Bool (edgeResolution, singlePrimalityAry);
	bool ** doublePrimalityAry = make2DPrimes (edgeResolution, edgeResolution, NUM_OF_TESTS);
	void print_spiral (int ** matrix, int edgeResolution)

	cout << "preSpiral" <<	 endl;

	//stdToCCWSpiralBool4 (edgeResolution, doublePrimalityAry);
	//stdToCCWSpiralBool2 (edgeResolution, doublePrimalityAry);


	//stdToSpiralBool (edgeResolution, edgeResolution, doublePrimalityAry, false, false, false);

	cout << "postSpiral" << endl;
	cout << "preloop" << endl;
	for (uint_fast64_t y = 0; y < edgeResolution; y++) {
		for (uint_fast64_t x = 0; x < edgeResolution; x++) {
			if (doublePrimalityAry[y][x] == true) {
				cout << "X";
				mainImage.SetPixel(y, x, blackPix);
			}
			else {
				cout << " ";
				mainImage.SetPixel(y, x, whitePix);
			}
		}
		cout << endl;
	}
	cout << "about to close" << endl;



	mainImage.WriteToFile(outputFileName.c_str());
	cout << "File saved" << endl;
	for (uint_fast64_t i = 0; i < edgeResolution; i++) {
		delete[] doublePrimalityAry[i];
	}
	delete[] doublePrimalityAry;
	//delete[] singlePrimalityAry;
	cout << "Program Ending" << endl;
	cout << "Press enter to close program..." << endl;
	cin.ignore();
	//EXIT_SUCCESS
	return 0;
}
