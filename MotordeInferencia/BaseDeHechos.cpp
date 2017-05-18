#include "BaseDeHechos.h"
#include "Hecho.h"
#include <string>
#include <algorithm>
#include <hash_map>

using namespace System;
using namespace System::Collections;
using namespace std;

BaseDeHechos::BaseDeHechos() {
    hechos = hash_map<Hecho, int>();
}

BaseDeHechos::~BaseDeHechos() {}

void BaseDeHechos::agregarHecho(Hecho hecho)
{
    //cout << "Agregando hecho: " + hecho.Argumento[0];
    if (existeHecho(hecho)) {
        if (estadoHecho(hecho) == Hecho.FALSO &&
                hecho.Estado == Hecho.VERDADERO) {
                hechos.erase(hecho);
                hechos.insert(hecho, hecho.Estado);
        }
    }
    else if (hecho.Estado != Hecho.INDETERMINADO)
        hechos.insert(hecho, hecho.Estado);
    else
        cout << "Error: Intento ingresar un hecho indeterminado" << endl;
}

bool BaseDeHechos::existeHecho(Hecho hecho)
{
    return hechos.count(hecho);
}

int BaseDeHechos::estadoHecho(Hecho hecho)
{
    return (int)hechos[hecho];
}

string BaseDeHechos::hechosVerdaderos()
{
    string texto = "";
    for (Hecho hecho: hechos.max_size) {
        if (hecho.Estado == Hecho.VERDADERO) {
            texto += hecho.Argumento[0] + ", ";
        }
    }
    if (texto.length() > 0)
            texto = texto.substr(0, texto.length() - 2).replace("_", " ",texto);
    return texto;
}

string BaseDeHechos::ToString()
{
    string texto = "Numero de hechos: " + hechos.count + "\n";
    for(Hecho h: hechos.max_size) {
        texto += h.EstadoTexto + "\t\t" + h.Argumento[0] + "\n";
    }
    return texto;
}
