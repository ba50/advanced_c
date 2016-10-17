.SILENT:

CXX = g++
CXXFLAGS = -Wall -pedantic -O2 -std=c++14
LIBRARIES = 

program: billing.o histogram.o main.o
			$(CXX) -o program billing.o histogram.o main.o $(CXXFLAGS)
billing.o: billing.cpp billing.hpp
			$(CXX) -o billing.o -c billing.cpp $(CXXFLAGS)
histogram.o: histogram.cpp histogram.hpp
			$(CXX) -o histogram.o -c histogram.cpp $(CXXFLAGS)
main.o: main.cpp billing.hpp histogram.hpp
			$(CXX) -o main.o -c main.cpp $(CXXFLAGS)
clean:
			rm -f *.o
