#include "rozklad.hpp"


RozkladGaussa::RozkladGaussa (const std::vector <float> &dane) : Rozklad (dane) {}


// Statyczny kreator wybranej klasy (to naprawd jest takie proste!)
Rozklad *RozkladGaussa::kreator (const std::vector <float> &dane)
{
	return new RozkladGaussa (dane);
}


// Statyczna metoda woajca (cho trudno to zobaczy) kreator typu o podanym id
Rozklad *FabrykaRozkladow::utworz (unsigned typ, const std::vector <float> &dane)
{
	return rozklady [typ] (dane);
}


