#ifndef _billing_hpp_
#define _billing_hpp_

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Polaczenie
{
    Polaczenie(std::string data_in){
        counter++;
        std::cout<<data_in<<std::endl;
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
