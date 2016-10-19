#include "billing.hpp"
#include "histogram.hpp"
#include <map>


void operator>>	(std::istream &is,
	       	std::vector<Polaczenie> &blng_vector_){

	std::string line;
	std::string cell;
	std::vector<std::string> cell_vector;
	cell_vector.reserve(3);

	for(int i =0; i < 3902; i++){

		std::getline(is,line);
		std::stringstream line_stream(line);

		while(std::getline(line_stream, cell, '\t')){
			cell_vector.push_back(cell);
		}

		blng_vector_.push_back(cell_vector);
		cell_vector.clear();

	}

}


Billing::Billing(std::istream &is){
	blng_vector_.reserve(3902);
	is>>blng_vector_;
}


void Billing::statystykaDzienna (std::ostream &os) const
{
	std::vector <unsigned> stat (32, 0); // przechowuje liczbę połączeń każdego dnia
	// Przelatuje całą tablicę blng_ i uzuzpełnia tablicę stat
	// Formatuje i wyświetla wyniki na os
}


void Billing::statystykaKrajowa (std::ostream &os) const
{
	std::map <std::string, Histogram> stat; // osobna statystyka dla każdego kodu
	// Przelatuje całą tablicę blng_ i wrzuca czasy rozmów do
	// odpowiednich histogramów w stat
	// Formatuje i wyświetla wyniki na os
}
