# Compilers
CC= gcc
CXX= g++
# Compiler flags
# -g for debugging
# -Wall turns on compiler warnings
CPPFLAGS= -std=c++2a -Wall -I./include

# Absolute path

# Linker flags
LINKERFLAG= -lm

# Directories and Files
SOURCEDIR:= src
INCLUDEDIR:= include
OBJECTDIR:= build
BINDIR:= bin

SOURCES:= $(wildcard $(SOURCEDIR)/*.cpp)
INCLUDE:= $(wildcard $(INCLUDEDIR)/*.h)
OBJECTS:= $(SOURCES:$(SOURCEDIR)/%.cpp=$(OBJECTDIR)/%.o)
TARGET:= run


all: $(TARGET)

$(TARGET): $(OBJECTS)
	${CXX} $^ -o $@

$(OBJECTS): $(OBJECTDIR)/%.o: $(SOURCEDIR)/%.cpp $(wildcard $(INCLUDEDIR)/*.h)
	$(CXX) $(CPPFLAGS) -c $< -o $@


.PHONEY: clean
clean:
	rm -f $(OBJECTS) $(TARGET)