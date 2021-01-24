#include "Zprava.h"

Zprava::Zprava()
{
}

Zprava::Zprava(int id, std::string adrZdroj, std::string adrCil, std::string obsah) :
	id(id), adrZdroj(adrZdroj), adrCil(adrCil), obsah(obsah) {
}
