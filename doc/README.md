## TODO Notes

### Improvement with sdl2 project from tower defense

- Layers for rendering order instead of tags
- Conan for dependencies
- Pushdown automaton instead of raw State machine for better code quality
- Use singleton components instead of many events to prevent spaghetti code
- Use Catch2 to test the code
- Defered rendering to improve performance and code quality (render command sends with custom api, easy to configure to use DirectX instead of OpenGL)
- Better camera handling (beginScene and endScene, and aspect ratio handling)
- Build with wasm supported (use OpenGL ES instead of OpenGL 4)
- Use HTML/CSS/JS for interfaces instead of XAML
