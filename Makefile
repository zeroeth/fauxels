# Simple build script from: http://mrbook.org/tutorials/make/
# for a more detailed guide: http://felixcrux.com/blog/creating-basic-makefile

CXXFLAGS=-Wall -I. -O3
SOURCES=$(wildcard *.cpp)
SOURCES+=$(wildcard sketch/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=fauxels

ifdef EMSCRIPTEN
	EXECUTABLE=fauxels.bc
	LDFLAGS=--js-library fauxels.js
endif

clean:
	-rm -f dist/* $(OBJECTS)

.o:
	$(CXX) $(CXXFLAGS) $< -o $@

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p dist
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o dist/$@

all: $(SOURCES) $(EXECUTABLE)

web: all
	$(CXX) $(CXXFLAGS) $(LDFLAGS) dist/$(EXECUTABLE) -o dist/index.html
