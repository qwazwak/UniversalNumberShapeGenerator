rem This code is fully cross platform.
rem Currently, however, the only way to automatically build it is on windows.
rem But, if you know what you are doing, or if you don't it's not very hard, it can be built on any OS with a C++ compiler.
rem If anybody comes across this with the ability to make a cmake file for this, please do!

g++ -std=gnu++17 -Ilibraries -O0 -g3 -Wall -c PUScore.cpp
g++ -std=gnu++17 -Ilibraries -O0 -g3 -Wall -c functions.cpp
rem g++ -std=gnu++17 -Ilibraries -O0 -g3 -Wall -c FILE.cpp


rem for any new cpp files, make sure to add them to the compile list
g++ -std=gnu++17 -O0 -g3 -Wall -o PortableUlamSpiral_TestingBuild.exe PUScore.o functions.o
PortableUlamSpiral_TestingBuild.exe
pause
