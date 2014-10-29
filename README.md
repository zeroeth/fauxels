fauxels
=======

A wrapper for simulating my https://github.com/zeroeth/pixeltastic themes in the browser (and possibly gl/sdl)

Uses a thin header/implementation of a few functions it expects to find on an Arduino with the Neopixel library.

Can be compiled with make, or you can generate a new makefile with cmake.

Supports compiling/running with emscripten. `em++ *.cpp -o index.html -I. --js-library fauxels.js`

Feel free to extend however you see fit. Possibly by including the actual Arduino.h and providing your own backing code.

How it works
------------

Back story: Normally the Arduino IDE run the `.ino` sketch files through a preprocessor to wrap your loop() and setup() functions in a .cpp file that has a main and includes `arduino.h`

To get fauxels working: Rename your sketch to .cpp and add #include "Arduino.h" to the top of it.

Flow of operation
-----------------

* `fauxels.cpp` is the entry point that runs your arduino loop. It also has an emscripten define to appease how javascript deals with infinite loops.

* `Arduino.cpp` is a thin (feel free to modify it as you want, I'm not trying to write a 100% accurate electrical simulator) wrapper for methods the Arduino sketch expects.

* `Adafruit_NeoPixel.cpp` is an incomplete wrapper for the NeoPixel library, just the functions I'm currently using. It also does one important thing, declare an extern for two methods.

* `fauxels.js` emscripten allows you to pass a library module (see: http://kripken.github.io/emscripten-site/docs/porting/connecting_cpp_and_javascript/Interacting-with-code.html#implement-c-in-javascript). This module listens to the neopixel wrapper and draws circles on canvas!
