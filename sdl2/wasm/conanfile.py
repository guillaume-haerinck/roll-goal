from conans import ConanFile, CMake

class ConanHelloEmscripten(ConanFile):
    name = "roll-goal-wasm"
    version = "1.0"
    description = "Allow to build the Rool Goal project as WebAssembly"
    topics = ("conan", "emscripten", "js", "javascript")
    license = "MIT"
    url = "https://github.com/guillaume-haerinck/roll-goal"
    homepage = "https://github.com/guillaume-haerinck/roll-goal"
    settings = {"os": ["Emscripten"]}
    exports_sources = ["CMakeLists.txt"]
    generators = ["cmake"]

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()
