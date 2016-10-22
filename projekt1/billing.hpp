#ifndef _billing_hpp_
#define _billing_hpp_

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

struct Polaczenie
{
	Polaczenie(){
		dzien = 0;
		nr = "";
		czas = 0;
	}

	Polaczenie(const std::vector<std::string> cell_vector){

		if(cell_vector.size()<3){
			printf("Rozmiar cell_vector: %zu < 3 :( \n", cell_vector.size());
			throw(0);
		}

		std::string::size_type sz;

		dzien = std::stoi(cell_vector[0],nullptr, 0);
		nr = cell_vector[1];	
		czas = std::stof(cell_vector[2], &sz);
	};

	void Print(){
		printf("%d, %s, %f\n", dzien, nr.c_str(), czas);
	};

	unsigned dzien;
	std::string nr;
	float czas; // czas po##czenia
	std::string kod () const{ // zwraca dwucyfrowy kod mi#dzynarodowy
		return std::string(nr.begin(),nr.begin()+2);
	}

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
