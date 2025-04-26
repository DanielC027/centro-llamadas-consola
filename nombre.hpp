/*
    Este archivo contiene la clase Nombre, la cual es usada para agentes y para clientes
 */

#ifndef _nombre_hh_
#define _nombre_hh_

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Nombre {

    private:
        string nombre;
        string apellido;


    public:
        Nombre();
        Nombre(const Nombre&);

        void ponNombre(const string&);
        void ponApellido(const string&);

        string aCadena()const;

        string dameNombre()const;
        string dameApellido()const;

        Nombre & operator = (const Nombre&);

        bool operator == (const Nombre&);

        bool operator > (const Nombre&);
        bool operator < (const Nombre&);

        bool operator >= (const Nombre&);
        bool operator <= (const Nombre&);

        bool operator != (const Nombre&);

        friend istream& operator >> (istream&, Nombre&);
        friend ostream& operator << (ostream&, const Nombre&);

        ~Nombre();


    };

#endif /* _Nombre_hh_ */

