/*

 */

#ifndef _cliente_hpp_
#define _cliente_hpp_

#include <iostream>
#include <cstring>
#include <fstream>

#include "nombre.hpp"

using namespace std;

class Cliente {

    private:
        Nombre nombre;
        string numeroCuenta;
        string numeroTelefono;


    public:
        Cliente();
        Cliente(const Cliente&);
        void ponerNombre(const Nombre&);
        void ponerNumeroCuenta(const string&);
        void ponerNumeroTelefono(const string&);

        string aCadena()const;

        Nombre dameNombre()const;
        string dameNumeroCuenta()const ;
        string dameNumeroTelefono()const ;

        Cliente & operator =(const Cliente&);
        bool operator == (const Cliente&);

        friend istream& operator >> (istream&, Cliente&);
        friend ostream& operator << (ostream&, const Cliente&);

        ~Cliente();


    };

#endif /* _Cliente_hh_ */

