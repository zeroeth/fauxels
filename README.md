fauxels
=======

A wrapper for simulating my https://github.com/zeroeth/pixeltastic themes in the browser (and possibly gl/sdl)

Uses a thin header/implementation of a few functions it expects to find on an Arduino with the Neopixel library.

Can be compiled with make, or you can generate a new makefile with cmake.

Supports compiling/running with emscripten.

Feel free to extend however you see fit. Possibly by including the actual Arduino.h and providing your own backing code.
