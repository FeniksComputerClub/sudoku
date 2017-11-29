CXX = g++
CXXFLAGS = -Wall -g -std=c++14          #Show all Warnings, make Debugable and use C++14
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

obj/%.o: src/%.cpp
#To get file *.o use file *.src
	$(CXX) $(CXXFLAGS) -c $< -o $@
#Compiler Flags -(compile) source/dependecies -(output) output

all: $(OBJ_FILES)
#When calling "make all", first make the required *.o files
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o out
#Compiler Flags (all required *.o files) -(output) path:"./out"

clean:
#When calling "make clean", remove all *.o files, and remove the executable
	rm $(OBJ_FILES)
	rm ./out
