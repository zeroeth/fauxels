# Simple build script from: http://mrbook.org/tutorials/make/
# for a more detailed guide: http://felixcrux.com/blog/creating-basic-makefile

CXXFLAGS=-Wall -I.
SOURCES=$(wildcard *.cpp)
SOURCES+=$(wildcard sketch/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=fauxels

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p dist
	$(CXX) $(LDFLAGS) $(OBJECTS) -o dist/$@

.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	-rm -f dist/* $(OBJECTS)
