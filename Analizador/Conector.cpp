#include "Conector.h"
#include <string>

using namespace System;
using namespace std;

Conector::Conector() {
    reglas = new BaseDeConocimiento();
    hechos = new BaseDeHechos();
}

Conector::~Conector() {}

static Conector Conector::obtenerConector() {
    if (conector == NULL) {
        conector = new Conector();
    }
    return *conector;
}

void Conector::agregarRegla(Regla regla) {
    reglas.agregarRegla(regla);
}

void Conector::agregarHecho(Hecho hecho) {
    hechos.agregarHecho(hecho);
}

bool Conector::getLeyendoRegla() {
    return leyendoRegla;
}

void Conector::inicioRegla() {
    leyendoRegla = true;
}

void Conector::finRegla() {
    leyendoRegla = false;
}

BaseDeConocimiento Conector::obtenerBaseDeConocimiento() {
    return reglas;
}

BaseDeHechos Conector::obtenerBaseDeHechos() {
    return hechos;
}

void Conector::cerrarArchivo() {
    reglas = new BaseDeConocimiento();
    hechos = new BaseDeHechos();
}

string Conector::ToString() {
    string texto = "Base de Conocimiento\n";
    for (int x = 0; x<reglas.NumeroReglas; x++)
    {
        texto += reglas.obtenerRegla(x);
    }
    texto += "Base de Hechos\n";
    /*for(int x=0; x<hechos.NumeroHechos; x++)
    {
    texto += hechos.obtenerHecho (x);
    }*/
    return texto;
}
