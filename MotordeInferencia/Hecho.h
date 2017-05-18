#ifndef HECHO_H
#define HECHO_H

#include <string>
#include <vector>
#include "Argumento.h"

class Hecho
{
    private:
        string relacion;
        vector<Argumento> argumentos;
        int estado;
        bool permanente = false;

    public:
        const int VERDADERO = 0;
        const int FALSO = 1;
        const int INDETERMINADO = 2;

    public:
        Hecho(string predicado, vector<Argumento> arg, int est);
        Hecho(string predicado, vector<Argumento> arg);
        Hecho(string predicado, Argumento arg, int est);
        Hecho(string predicado, Argumento arg);
        ~Hecho();
        string getRelacion();
        void setRelacion(string rel);
        int getNumeroArgumentos();
        int getEstado();
        void setEstado(int est);
        string getEstadoTexto();
        bool getPermanente();
        void setPermanente(bool per);
        bool operator==(Hecho &h1, Hecho &h2);
        bool operator!=(Hecho &h1, Hecho &h2);
        template<typename Object>
        bool Equals(Object h1);
        int GetHashCode();
        string ToString();
};

#endif // HECHO_H
