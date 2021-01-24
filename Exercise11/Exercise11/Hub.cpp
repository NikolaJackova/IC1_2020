#include "Hub.h"

void Hub::Pripoj(ASitovyPrvek* sitovyPrvek)
{
	if (sitovyPrvek == nullptr)
	{
		throw std::exception("Prvek je null");
	}
	if (pocetPripojenychPrvku == maximumPripojenychPrvku)
	{
		throw std::exception("Hub ma plno");
	}
	pripojenePrvky[pocetPripojenychPrvku++] = sitovyPrvek;
}

void Hub::Provadej()
{
	while (!prichoziZpravy.JePrazdna())
	{
		ZpracujPrichoziZpravu(prichoziZpravy.Odeber());
	}
}

void Hub::ZpracujPrichoziZpravu(ZpravaPort* zprava)
{
	if (zpracovanéZpravy.Obsahuje(zprava->zprava)) {
		return;
	}
	for (int i = 0; i < pocetPripojenychPrvku; i++)
	{
		if (pripojenePrvky[i] == zprava->port)
		{
			continue;
		}
		pripojenePrvky[i]->VlozPrichoziZpravu(zprava->zprava, pripojenePrvky[i]);
	}
	zpracovanéZpravy.Vloz(zprava->zprava);
}

Hub::Hub(int max)
{
	maximumPripojenychPrvku = max;
	pripojenePrvky = new ASitovyPrvek * [max];
	for (size_t i = 0; i < max; i++)
	{
		pripojenePrvky[i] = nullptr;
	}
	pocetPripojenychPrvku = 0;
}

Hub::~Hub()
{
	delete[] pripojenePrvky;
}
