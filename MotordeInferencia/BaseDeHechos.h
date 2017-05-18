#ifndef BASEDEHECHOS_H
#define BASEDEHECHOS_H

#include <hash_map>
#include "Hecho.h"

using namespace System::Collections;

class BaseDeHechos
{
    private:
        hash_map<Hecho, int> hechos;

    public:
        BaseDeHechos();
        ~BaseDeHechos();
        void agregarHecho(Hecho hecho);
        bool existeHecho(Hecho hecho);
        int estadoHecho(Hecho hecho);
        String^ hechosVerdaderos();
        string ToString();
};

#endif // BASEDEHECHOS_H
