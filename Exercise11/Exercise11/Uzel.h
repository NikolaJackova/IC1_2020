#pragma once

#ifndef UZEL_H
#define UZEL_H

#include "ASitovyPrvek.h"

struct Uzel :ASitovyPrvek {
    std::string adresa;
    ASitovyPrvek* pripojenyPrvek;
    Fronta<Zprava*> odchoziZpravy;
    Uzel(std::string adresa);
    ~Uzel();
    void Pripoj(ASitovyPrvek* sitovyPrvek) override;
    void Provadej() override;
    void ZpracujPrichoziZpravu(ZpravaPort* zprava) override;
    void PripravZpravuKOdeslani(std::string cil, std::string obsah);
};

#endif // !UZEL_H
