#include "Uzel.h"
#include "Sit.h"

using namespace std;

int Sit::idZpravy = -1;

Uzel::Uzel(string adresa)
{
	this->adresa = adresa;
	pripojenyPrvek = nullptr;
}

Uzel::~Uzel()
{
}

void Uzel::Pripoj(ASitovyPrvek* sitovyPrvek)
{
	if (sitovyPrvek == nullptr)
	{
		throw std::exception("Prvek je null");
	}
	pripojenyPrvek = sitovyPrvek;
}

void Uzel::Provadej()
{
	while (!odchoziZpravy.JePrazdna()) {
		pripojenyPrvek->VlozPrichoziZpravu(odchoziZpravy.Odeber(), this);
	}

	while (!prichoziZpravy.JePrazdna())
	{
		ZpracujPrichoziZpravu(prichoziZpravy.Odeber());
	}

}

void Uzel::ZpracujPrichoziZpravu(ZpravaPort* zprava)
{
	if (zprava->zprava->adrCil != this->adresa) {
		return;
	}
	cout << zprava->zprava->adrCil << " id:" << zprava->zprava->id << " src:" << zprava->zprava->adrZdroj << " msg:" << zprava->zprava->obsah << endl;
	if (zprava->zprava->obsah.find("ping") != string::npos) {
		PripravZpravuKOdeslani(zprava->zprava->adrZdroj, "pong");
	}
}

void Uzel::PripravZpravuKOdeslani(string cil, string obsah)
{
	odchoziZpravy.Vloz(new Zprava(Sit::DejNoveId(), this->adresa, cil, obsah));
}
