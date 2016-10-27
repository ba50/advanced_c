#include "histogram.hpp"

#include <algorithm>
#include <math.h>


Histogram::Histogram (){
	srednia_akt_ = false;
	odchylenie_akt_ = false;
	srednia_ = 0.f;
	odchylenie_ = 0.f;
}


void Histogram::dodaj(float x){
	dane_.push_back(x);	
}


size_t Histogram::rozmiar () const{
	return dane_.size();	
}


float Histogram::srednia () const{ // użyj std::for_each() !
	if(srednia_akt_){
		return srednia_;
	} else {
		srednia_akt_ = true;
		std::for_each(dane_.begin(), dane_.end(), [this] (float x) {this->srednia_ += x;});
		return srednia_/=dane_.size();
	}	
}


float Histogram::odchylenie () const{ // użyj std::for_each() !
	if(!srednia_akt_)
		srednia();

	if(odchylenie_akt_){
		return odchylenie_;
	} else if(srednia_){
		odchylenie_akt_ = true;
		auto odh = [this] (float x) {
			this->odchylenie_+=pow(x-this->srednia_,2);
		};
		std::for_each(dane_.begin(), dane_.end(), odh);
		odchylenie_/=dane_.size();
		return sqrt(odchylenie_);
	}
	else{
		throw std::string("Nie mozna policzyc odchylenia bo nie ma sredniej\n");
	}
}


float Histogram::max () const{ // użyj std::max_element() !
	return *max_element(dane_.begin(), dane_.end());
}


float Histogram::min () const{ // użyj std::min_element() !
	return *min_element(dane_.begin(), dane_.end());
}
