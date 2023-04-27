$BUILD_DIR = "./build/"
if [ -d "$BUILD_DIR" ] then
    mkdir build
fi
cmake -S . -B ./build/
cmake --build ./build/