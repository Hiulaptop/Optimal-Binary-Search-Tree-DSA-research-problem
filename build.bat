
if exist build rmdir /s /q build
cmake -G "MinGW Makefiles" -S . -B build
cd build
cmake --build .
OptimalBST.exe