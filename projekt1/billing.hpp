#ifndef _billing_hpp_
#define _billing_hpp_

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

struct Polaczenie
{
	Polaczenie(std::string line_in){
		counter++;

		std::stringstream line_stream(line_in);
		std::string cell;
		std::vector<std::string> cell_vector;
		//cell_vector.reserve(6);

		while(std::getline(line_stream, cell, '\t')){
			cell_vector.push_back(cell);
		}

		//std::string::size_type sz;
		dzien = std::stoi(cell_vector[3],nullptr, 0);
		nr = cell_vector[4];	
		//czas = std::stof(cell_vector[5], &sz);
	};

	void Print(){
		printf("%d, %s, %f\n", dzien, nr.c_str(), czas);
	};

	unsigned dzien;
	std::string nr;
	float czas; // czas po##czenia
	static unsigned int counter;
	std::string kod () const; // zwraca dwucyfrowy kod mi#dzynarodowy
};

std::istream &operator>> (std::istream &is, Polaczenie &p);

class Billing
{
	public:
		explicit Billing (std::istream &is); // wczytuje po##czenia z is
		void statystykaDzienna (std::ostream &os) const;
		void statystykaKrajowa (std::ostream &os) const;
	private:
		std::vector <Polaczenie> blng_vector_; // tablica po##cze#
};

#endif
