.SILENT:

CXX = g++
CXXFLAGS = -Wall -pedantic -O2 -std=c++17
LIBRARIES = 

program: dane_stat.o rozklad.o main.o
			$(CXX) -o program dane_stat.o rozklad.o main.o $(CXXFLAGS)
billing.o: dane_stat.cpp dane_stat.hpp
			$(CXX) -o dane_stat.o -c dane_stat.cpp $(CXXFLAGS)
histogram.o: rozklad.cpp rozklad.hpp
			$(CXX) -o rozklad.o -c rozklad.cpp $(CXXFLAGS)
main.o: main.cpp dane_stat.hpp rozklad.hpp
			$(CXX) -o main.o -c main.cpp $(CXXFLAGS)
clean:
			rm -f *.o
