#include "argumento.h"

template<class T>

bool Argumento<T>::operator ==(Argumento &a1)
{
	//Se usan objetos para poder comparar si son nulos
	//Sin crear una recursividad infinita
	Object o1 = (Object)a1;
	Object o2 = (Object)a2;
	if (o1 == null && o2 == null)
		return true;
	else if ((o1 == null && o2 != null) || (o1 != null && o2 == null))
		return false;
	else if (a1.equals(Constante) && a2.equals(Constante) && ((Constante)a1) == ((Constante)a2))
		return true;
	else if (a1.equals(Variable) && a2.equals(Variable) && ((Variable)a1) == ((Variable)a2))
		return true;
	else if (a1.equals(Numero) && a2.equals(Numero) && ((Numero)a1) == ((Numero)a2))
		return true;
	return false;
}

template<class T>
bool Argumento<T>::operator !=(Argumento &a2)
{
	if (a1 == a2) {
		return false;
	}
	return true;
}



template<class T>
bool Argumento<T>::Equals(Argumento &a1)
{
	if (this == *(Argumento)a1) {
		return true;
	}
	return false;
}

template<class T>
int Argumento<T>::GetHashCode()
{
	return 0;
}
