#ifndef CONECTOR_H
#define CONECTOR_H

#include <string>
#include "BaseDeHechos.h"
#include "BaseDeConocimiento.h"
#include "Regla.h"


class Conector
{
    private:
        BaseDeConocimiento reglas;
        BaseDeHechos hechos;
        static Conector *conector;
        bool leyendoRegla = false;

    public:
        Conector();
        ~Conector();
        static Conector obtenerConector();
        void agregarRegla(Regla regla);
        void agregarHecho(Hecho hecho);
        bool getLeyendoRegla();
        void inicioRegla();
        void finRegla();
        BaseDeConocimiento obtenerBaseDeConocimiento();
        BaseDeHechos obtenerBaseDeHechos();
        void cerrarArchivo();
        string ToString();
};

#endif // CONECTOR_H
