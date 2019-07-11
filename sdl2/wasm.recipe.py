from conans import ConanFile, CMake

class RollGoalWasm(ConanFile):
    settings = {"os": ["Emscripten"]}
    requires = "entt/3.x.y-WIP@skypjack/stable"
    generators = ["cmake"]

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()
