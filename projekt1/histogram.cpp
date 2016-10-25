#include "histogram.hpp"

Histogram::Histogram (){
}

void Histogram::dodaj(float x){
	dane_.push_back(x);	
}
size_t Histogram::rozmiar () const{
	return dane_.size();	
}
float Histogram::srednia () const{ // użyj std::for_each() !
		
}
float Histogram::odchylenie () const{ // użyj std::for_each() !
}
float Histogram::max () const{ // użyj std::max_element() !
}
float Histogram::min () const{ // użyj std::min_element() !
}


