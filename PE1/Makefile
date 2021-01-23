CXX = g++ 
CXXFLAGS = -std=c++17 -Wall

all: main

main: Point.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Point.o -o main

Point.o: Point.cpp
	$(CXX) $(CXXFLAGS) -c Point.cpp

clean:
	rm Point.o main

#Resources I found helpful
#Source: https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
#Source: https://github.com/CSCI-3010-CUBoulder/csci3010-cuboulder/blob/master/examples/Makefile
