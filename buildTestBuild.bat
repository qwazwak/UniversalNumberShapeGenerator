rem This code is fully cross platform.
rem Currently, however, the only way to automatically build it is on windows.
rem But, if you know what you are doing, or if you don't it's not very hard, it can be built on any OS with a C++ compiler.
rem If anybody comes across this with the ability to make a cmake file for this, please do!

rem png.o 

rem for any new cpp files, make sure to add them to the compile list with:
rem g++ -std=gnu++17 -Ilibraries -O0 -g3 -Wall -c FILE.cpp

 

g++ -std=gnu++17 -Ilibraries -O0 -g3 -fpermissive -c Main.cpp -lgdi32 -Llibraries/libpng12.dll -Llibraries/libpng3.dll -Llibraries/libpng12-config -Llibraries/libpng-config -lpthread -Ilibraries/libpng -Llibraries/libpng -llibraries/libpng/png
g++ -std=gnu++17 -Ilibraries -O0 -g3 -fpermissive -c matrixPlusNone.cpp -lgdi32
g++ -std=gnu++17 -Ilibraries -O0 -g3 -fpermissive -c primeFinder.cpp -lgdi32



g++ -std=gnu++17 -O0 -g3 -fpermissive -lgdi32 -Llibraries/libpng12.dll -Llibraries/libpng3.dll -Llibraries/libpng12-config -Llibraries/libpng-config -lpthread -Ilibraries/libpng -Llibraries/libpng -o PortableUlamSpiral_Testi ngBuild.exe primeFinder.o matrixPlusNone.o Main.o

rem  png.o pngerror.o pngget.o pngmem.o pngpread.o pngread.o pngrio.o pngrtran.o pngrutil.o pngset.o pngtrans.o pngwio.o pngwrite.o pngwtran.o pngwutil.o

PortableUlamSpiral_TestingBuild.exe -r 500
pause
