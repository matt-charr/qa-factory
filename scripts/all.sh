cmake -S . -B ./build -G "MinGW Makefiles" -DCONTRACT_SOURCE_FILE="tests/main" &&
cmake --build ./build -j8 &&
./bin/main