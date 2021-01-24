#pragma once
#ifndef ZPRAVA_PORT_H
#define ZPRAVA_PORT_H

#include "Zprava.h"

struct ASitovyPrvek;

struct ZpravaPort {
    Zprava* zprava;
    ASitovyPrvek* port;
    ZpravaPort();
    ZpravaPort(Zprava* zprava, ASitovyPrvek* port);
};
#endif