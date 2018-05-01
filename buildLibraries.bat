rem This code is fully cross platform.
rem Currently, however, the only way to automatically build it is on windows.
rem But, if you know what you are doing, or if you don't it's not very hard, it can be built on any OS with a C++ compiler.
rem If anybody comes across this with the ability to make a cmake file for this, please do!

g++ -std=gnu++17 -O3 -g3 -Wall -c libraries/imGUI/imgui_demo.cpp
g++ -std=gnu++17 -O3 -g3 -Wall -c libraries/imGUI/imgui_draw.cpp
g++ -std=gnu++17 -O3 -g3 -Wall -c libraries/imGUI/imgui.cpp
g++ -std=gnu++17 -O3 -g3 -Wall -c libraries/EasyBMP/EasyBMP_SimpleArray.cpp
g++ -std=gnu++17 -O3 -g3 -Wall -c libraries/EasyBMP/EasyBMP.cpp

rem g++ -std=gnu++17 -O3 -g3 -Wall -c libraries/


move *.o %~dp0\building\
pause
