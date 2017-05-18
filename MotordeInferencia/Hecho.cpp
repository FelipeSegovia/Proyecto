#include "Hecho.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
#include <vector>

using namespace System;
using namespace std;

Hecho::Hecho(string predicado, vector<Argumento> arg, int est) {
    relacion = predicado;
    argumentos = arg;
    estado = est;
}

Hecho::Hecho(string predicado, vector<Argumento> arg) {
    relacion = predicado;
    argumentos = arg;
    estado = INDETERMINADO;
}

Hecho::Hecho(string predicado, Argumento arg, int est) {
    relacion = predicado;
    argumentos.push_back(arg);
    estado = est;
}

Hecho::Hecho(string predicado, Argumento arg) {
    relacion = predicado;
    argumentos.push_back(arg);
    estado = INDETERMINADO;
}

Hecho::~Hecho() {}

string Hecho::getRelacion() {
    return relacion;
}

void Hecho::setRelacion(string rel) {
    relacion = rel;
}

int Hecho::getNumeroArgumentos() {
    if (argumentos.size == 0)
        return argumentos.size;
    else
        return 0;
}

int Hecho::getEstado() {
    return estado;
}

void Hecho::setEstado(int est) {
    estado = est;
}

string Hecho::getEstadoTexto() {
    if (estado == VERDADERO)
        return "Verdadero";
    else if (estado == FALSO)
        return "Falso";
    else
        return "Indeterminado";
}

bool Hecho::getPermanente() {
    return permanente;
}

void Hecho::setPermanente(bool per) {
    permanente = per;
}

bool Hecho::operator==(Hecho &h1, Hecho &h2) {
    //Se usan objetos para poder comparar si son nulos
    //Sin crear una recursividad infinita
    Object o1 = (Object)h1;
    Object o2 = (Object)h2;
    if (o1 == null && o2 == null)
        return true;
    else if ((o1 == null && o2 != null) || (o1 != null && o2 == null))
        return false;
    else if (h1.Relacion == h2.Relacion && h1.NumeroArgumentos == h2.NumeroArgumentos) {
        bool iguales = true;
        for (int x = 0; x < h1.NumeroArgumentos; x++) {
            //Tienen el mismo numero de argumento por lo que el limite de x vale para los dos
            if (h1.argumentos[x] != h2.argumentos[x])
                iguales = false;
        }
        return iguales;
    }
    return false;
}

bool Hecho::operator!=(Hecho &h1, Hecho &h2) {
    if (h1 == h2)
        return false;
    return true;
}

template<typename Object>
bool Hecho::Equals(Object h1) {
    if (this == (Hecho)h1)
            return true;
    return false;
}

int Hecho::GetHashCode() {
    int valor = getRelacion().GetHashCode();
    for (int x = 0; x<Argumento.Length; x++)
    {
        valor += Argumento[x].GetHashCode();
    }
    return valor;
}

string Hecho::ToString() {
    int n = getNumeroArgumentos();
    ostringstream convert;
    convert << n;
    string txt = convert.str();

    string texto = "Hecho: " + getRelacion() + " con " + txt + " argumentos\n";
    for (int x = 0; x<getNumeroArgumentos(); x++)
    {
        texto += "\tArgumento " + (x + 1) + ": " + argumentos[x] + "\n";
    }
    texto += "Estado: " + getEstadoTexto();
    return texto;
}
