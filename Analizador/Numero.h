#ifndef NUMERO_H
#define NUMERO_H

#include <string>

class Numero : public Argumento
{
    private:
        double numero;

    public:
        Numero(double num);
        ~Numero() {}
        double getValor();
        void setValor(double num);
        bool operator==(Numero &n1, Numero &n2);
        bool operator!=(Numero &n1, Numero &n2);
        template<typename Object>
        bool Equals(Object n1);
        int GetHashCode();
        string ToString();
};
#endif // NUMERO_H
