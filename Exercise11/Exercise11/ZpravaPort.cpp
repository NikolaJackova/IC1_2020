#include "ZpravaPort.h"

ZpravaPort::ZpravaPort()
{
	zprava = nullptr;
	port = nullptr;
}

ZpravaPort::ZpravaPort(Zprava* zprava, ASitovyPrvek* port) : zprava(zprava), port(port) {}