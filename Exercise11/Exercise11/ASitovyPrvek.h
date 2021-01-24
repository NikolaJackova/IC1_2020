#pragma once
#ifndef A_SITOVY_PRVEK_H
#define A_SITOVY_PRVEK_H

#include "Fronta.h"
#include "Zprava.h"
#include "ZpravaPort.h"

struct ASitovyPrvek {
protected:
    virtual void ZpracujPrichoziZpravu(ZpravaPort* zprava) = 0;
    Fronta<ZpravaPort*> prichoziZpravy;
public:
    void VlozPrichoziZpravu(Zprava* zprava, ASitovyPrvek* prvek);
    virtual void Provadej() = 0;
    virtual void Pripoj(ASitovyPrvek* prvek) = 0;
    virtual ~ASitovyPrvek();
};
#endif