#include "billing.hpp"
#include "histogram.hpp"
#include <map>

unsigned int Polaczenie::counter = 0;

Billing::Billing(std::istream &is){
    blng_vector_.reserve(4000);

    std::string temp;

    std::getline(is,temp);
    
    blng_vector_.push_back({temp});


    printf("%d\n", Polaczenie::counter);
    //for(auto& blng_ : blng_vector_){
    //}
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
