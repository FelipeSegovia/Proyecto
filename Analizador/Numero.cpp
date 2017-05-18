#include "Numero.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace System;
using namespace std;

Numero::Numero(double num) {
    numero = num;
}

Numero::~Numero() { }

double Numero::getValor() {
    return numero;
}

void Numero::setValor(double num) {
    numero = num;
}

bool Numero::operator==(Numero &n1, Numero &n2) {
    // Se usan objetos para poder comparar si son nulos
    //Sin crear una recursividad infinita
    if (n1 == null && n2 == null)
        return true;
    else if ((n1 == null && n2 != null) || (n1 != null && n2 == null))
        return false;
    else if (n1.Valor == n2.Valor)
        return true;
    return false;
}

bool Numero::operator!=(Numero &n1, Numero &n2) {
    if (n1 == n2)
        return false;
    return true;
}

template<typename Object>
bool Numero::Equals(Object n1) {
    if (this == (Numero)n1)
        return true;
    return false;
}

int Numero::GetHashCode() {
    return numero.GetHashCode();
}

string Numero::ToString() {
    std::ostringstream strs;
    strs << numero;
    std::string str = strs.str();
    return str;
}
