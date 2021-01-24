#pragma once

#ifndef HUB_H
#define HUB_H

#include "ASitovyPrvek.h"

struct Hub :ASitovyPrvek {
    int pocetPripojenychPrvku;
    int maximumPripojenychPrvku;
    ASitovyPrvek** pripojenePrvky;
    Fronta<Zprava*> zpracovanéZpravy;
    void Pripoj(ASitovyPrvek* sitovyPrvek) override;
    void Provadej() override;
    void ZpracujPrichoziZpravu(ZpravaPort* zprava) override;
    Hub(int max);
    ~Hub();
};

#endif // !HUB_H