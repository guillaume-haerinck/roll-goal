@echo off
conan remove roll-goal-wasm/* -f
conan create . conan/testing  -k -p emscripten.profile --build missing
conan install conanfile.txt  -pr emscripten.profile