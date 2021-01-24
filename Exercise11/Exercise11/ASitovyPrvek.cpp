#include "ASitovyPrvek.h"

void ASitovyPrvek::VlozPrichoziZpravu(Zprava* zprava, ASitovyPrvek* prvek)
{
	prichoziZpravy.Vloz(new ZpravaPort(zprava, prvek));
}

ASitovyPrvek::~ASitovyPrvek()
{
}
