#include "functions.hpp"

//Current file writing library
#include <CImg\CImg.h>

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

#include <boost/array.hpp>


//getopt.h is required for the getopt function
#include <getopt.h>

#include <quadmath.h> //required for the boost float 128
#include <gmp.h>
#include <boost\multiprecision\gmp.hpp> //Sister to cppint, but floating, also fixes some of cppint's erros
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




//Idk if we actually need this.. but its so helpful
#include <cstdlib>


#include <iostream>
#include <iomanip>

#include <cstdint>
#include <cmath>
#include <cstring>
#include <string>

//Libraries maybe needed, possibly for debug/logging
//#include <time.h>
//#include <fstream>
//#include <ctime>


using namespace std;
