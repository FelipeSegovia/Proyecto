#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

class Variable : public Argumento
{
    private:
        string nombre;

    public:
        Variable(string nom);
        ~Variable();
        string getNombreVariable();
        void setNombreVariable(string value);
        bool operator == (Variable &v1, Variable &v2);
        bool operator != (Variable &v1, Variable &v2);
        template<typename Object>
        bool Equals(Object v1);
        string ToString();
};
#endif // VARIABLE_H
