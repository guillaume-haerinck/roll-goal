# Roll Goal - Using SDL

## Getting Started

### Prerequisites

You need to install [Cmake](https://cmake.org/) to build the project, and [Conan](https://conan.io/) to download dependencies.

Then you can add the server which contains the dependencies of the project :

```bash
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
```

### Build for your machine

You can handle the `CMakeLists.txt` in any way you like, it will download the dependecies by itself. Here's some way to use it :

#### `Option 1: Bash (Linux only)`

```bash
cmake . -DCMAKE_BUILD_TYPE=Release
make
```

You can then run the project with `./bin/roll-goal`

#### `Option 2: Visual Studio (Windows only)`

Open this folder with the `CMake...` option in file->open on Visual Studio, and run the project.

#### `Option 3: VSCode (Cross-Platform)`

Use the `CMakeTools` plugin, build with `f7` then run with `f5` (But be carefull to be on the right platform, there is a launch file for windows and for linux).

### Build as Web Assembly

This project support Web Assembly, so it can run in a browser like Google Chrome or Firefox !

The build steps are the same for any platform (you just need to delete the build folder if it already exist) :

```bash
conan install ./wasm.recipe.py --build missing --install-folder build -pr ./wasm.profile
conan build ./wasm.recipe.py --build-folder build
```

You can then copy the files inside `build/bin` into `www` and run this folder with a simple web-server. You can easily create one with python on your shell with :

```bash
python -m http.server --directory www --bind 127.0.0.1
```

Then open [your local server](http://127.0.0.1:8000/) to see the project.
