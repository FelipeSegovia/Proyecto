#include "Variable.h"
#include <string>

using namespace System;
using namespace std;

Variable::Variable(string nom) {
    nombre = nom;
}

Variable::~Variable() {}

string Variable::getNombreVariable() {
    return nombre;
}

void Variable::setNombreVariable(string value) {
    nombre = value;
}

bool Variable::operator==(Variable &v1, Variable &v2) {
    //Se usan objetos para poder comparar si son nulos
    //Sin crear una recursividad infinita
    Object o1 = (Object)v1;
    Object o2 = (Object)v2;
    if (o1 == null && o2 == null)
        return true;
    else if ((o1 == null && o2 != null) || (o1 != null && o2 == null))
        return false;
    else if (v1.NombreVariable == v2.NombreVariable)
        return true;
    return false;
}

bool Variable::operator!=(Variable &v1, Variable &v2) {
    if (v1 == v2)
        return false;
    return true;
}

template<typename Object>
bool Variable::Equals(Object v1) {
    if (this == (Variable)v1)
        return true;
    return false;
}

int Variable::GetHashCode() {
    return nombre.GetHashCode();
}

string Variable::ToString() {
    return nombre;
}
