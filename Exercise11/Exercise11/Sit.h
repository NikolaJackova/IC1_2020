#pragma once

#ifndef SIT_H
#define SIT_H

#include "ASitovyPrvek.h"
struct Sit
{
private:
    static int idZpravy;
    Fronta<ASitovyPrvek*> sitovePrvky;
public:
    static int DejNoveId();
    void Pripoj(ASitovyPrvek* sitovyPrvek);
    void ProvadejVse();
};
#endif // !SIT_H
