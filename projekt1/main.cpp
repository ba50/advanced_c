#include "billing.hpp"

int main ()
{
	try{
		Billing bil (std::cin);

		std::cout << "*** STATYSTYKA DZIENNA ***" << std::endl;
		bil.statystykaDzienna (std::cout);

		std::cout << "\n*** STATYSTYKA KRAJOWA ***" << std::endl;
		bil.statystykaKrajowa (std::cout);

	} catch(std::string s){
		std::cout<<s<<std::endl;
	}

	return 0;
}
