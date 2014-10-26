# Simple build script from: http://mrbook.org/tutorials/make/
# for a more detailed guide: http://felixcrux.com/blog/creating-basic-makefile

CXXFLAGS=-c -Wall
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=fauxels

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	-rm -f $(EXECUTABLE) $(OBJECTS)
