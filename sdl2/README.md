# Roll Goal - Using SDL

## Getting Started

### Prerequisites

You need to install [Cmake](https://cmake.org/) to build the project, and [Conan](https://conan.io/) to download dependencies.

Then you can add the server which contains the dependencies of the project :

```bash
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
```

If you are on Linux or Mac there is one step remaining :

#### On linux

```bash
sudo cp lib/ultralight-1.0/bin/linux/libWebCore.so /usr/lib
```

#### On mac

```bash
sudo cp lib/ultralight-1.0/bin/mac/libWebCore.so /usr/lib
```

### Build

You can handle the `CMakeLists.txt` in any way you like, it will download the dependecies by itself. 

Here's some way to use it :

#### `Option 1: CLI`

```bash
cmake . -DCMAKE_BUILD_TYPE=Release
make
```

You can then run the project with `./bin/roll-goal`

#### `Option 2: Visual Studio (Windows only)`

Open this folder with the `CMake...` option in file->open on Visual Studio, and run the project.

#### `Option 3: VSCode`

Use the `CMakeTools` plugin, build with `f7` then run with `f5` (But be carefull to be on the right platform, there is a launch file for windows and for linux).

### Build as Web Assembly

*As Ultralight lib is not yet available as Emscripten builds, web assembly is broken*

This project support Web Assembly, so it can run in a browser like Google Chrome or Firefox !

The build steps are the same for any platform (however it seems broken for now on Windows). Do not forget to delete `CMakeCache.txt` if there is one on the folder.

```bash
conan install ./wasm.recipe.py --build missing --install-folder wasm -pr ./wasm.profile
conan build ./wasm.recipe.py --build-folder wasm
```

You can then copy the files inside `wasm/bin` into `www` and run this folder with a simple web-server. On this exemple, we are creating a simple one with python :

```bash
cp -a wasm/bin/. www
cd www
python3 -m http.server -b 127.0.0.1
```

Then open [your local server](http://127.0.0.1:8000/) to see the project.

## Running test

The test target is build by default. To run it, you can launch the `TEST_ROLL_GOAL` executable next to the project, or you can go to the build folder, and run the CMake test utility with `ctest .`

## Dependencies

- [ENTT](https://github.com/skypjack/entt) - An ECS library
- [Ultralight](https://ultralig.ht/) - Web engine for user interfaces

## Inspired by

- [WacMan](https://github.com/carlfindahl/wacman) - A pacman clone made with ENTT
- [Hazel Engine](https://github.com/TheCherno/Hazel) - A game engine made by Cherno and explained in his youtube series
