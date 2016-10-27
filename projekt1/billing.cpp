#include "billing.hpp"
#include "histogram.hpp"
#include <map>
#include <algorithm>


std::istream &operator>> (std::istream &is, Polaczenie &p){

	is>>p.dzien;
	is>>p.nr;
	is>>p.czas;
		
	return is;
}


Billing::Billing(std::istream &is){
	blng_vector_.reserve(4000);
	Polaczenie temp;
	while(	is>>temp){
		blng_vector_.push_back(temp);
	}
}


void Billing::statystykaDzienna (std::ostream &os) const
{
	std::vector <unsigned> stat_vector (31, 0); 
	for(auto& blng_ : blng_vector_){
		stat_vector[blng_.dzien-1]++;
	}
	unsigned min_ = *min_element(stat_vector.begin(), stat_vector.end());
	int i =1;
	for(auto& stat : stat_vector){
		printf("%d:\t%d\t", i, stat);	
		printf("(%f%%):\t", (static_cast<float>(stat)*100.f)/
			static_cast<float>(blng_vector_.size()));
		for(stat-=(min_-1) ; stat != 0 ; stat--){
			printf("*");	
		}
		printf("\n");
		i++;
	}	

	printf("\nWYKONANYCH POLACZEN: %zu\n", blng_vector_.size());
}


void Billing::statystykaKrajowa (std::ostream &os) const
{
	std::map <std::string, Histogram> stat; // osobna statystyka dla każdego kodu
	// Przelatuje całą tablicę blng_ i wrzuca czasy rozmów do
	// odpowiednich histogramów w stat
	// Formatuje i wyświetla wyniki na os
	for(auto& blan_ : blng_vector_){
		stat[blan_.kod()].dodaj(blan_.czas);
	}	

	printf("Kraj\tN\t\tSred.\t\tOdch.\t\tMin\t\tMax\n");

	for(auto& s : stat){
		printf("%s:\t%zu\t%f\t%f\t%f\t%f\n", 
		s.first.c_str(), s.second.rozmiar(), s.second.srednia(), s.second.odchylenie(), s.second.min(), s.second.max());
	}

}
