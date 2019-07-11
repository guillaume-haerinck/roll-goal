from conans import ConanFile, CMake

class RollGoalWasm(ConanFile):
    settings = {"os": ["Emscripten"]}
    exports_sources = ["CMakeLists.txt", "src/*"]
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
