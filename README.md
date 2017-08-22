# Tanks

A clone of the Atari game "Tanks", which I originally used as an example when teaching Java Programming
at Digital Media Academy, UBC 2017 (http://www.digitalmediaacademy.org). I'm adapting the code to use C/C++ to
improve my skills working with large C++ projects.

## Dependencies

The game depends on SDL2 and SDL2_image for drawing graphics.

*Mac OS X Installation (Homebrew):*
```
brew install sdl2
brew install sdl2_image
```

## Building and Running

The game can be built using the CMake build system. From the root of the project:
```
mkdir -p build && cd build
cmake ..
make all
./tanks
```
