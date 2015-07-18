# Simple build script from: http://mrbook.org/tutorials/make/
# for a more detailed guide: http://felixcrux.com/blog/creating-basic-makefile
.DEFAULT_GOAL := all

CXXFLAGS=-Wall -I. -O3
SOURCES=$(wildcard *.cpp)
SOURCES+=$(wildcard sketch/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=fauxels

ifdef EMSCRIPTEN
	EXECUTABLE+=.bc
	LDFLAGS+=--js-library fauxels-view.js
else
	LDFLAGS+=`pkg-config sdl2 gl --libs`
	CXXFLAGS+=`pkg-config sdl2 gl --cflags`
endif

clean:
	-rm -f dist/* $(OBJECTS)

.o:
	$(CXX) $(CXXFLAGS) $< -o $@

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p dist
	$(CXX) $(OBJECTS) $(CXXFLAGS) $(LDFLAGS) -o dist/$@

all: $(SOURCES) $(EXECUTABLE)

web: all
	$(CXX) $(CXXFLAGS) $(LDFLAGS) dist/$(EXECUTABLE) -o dist/index.html
