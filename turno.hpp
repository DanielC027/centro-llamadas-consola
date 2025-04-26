/*
	Este archivo continene la clase turno perteneciente a agentes
 */

#ifndef _turno_hpp_
#define _turno_hpp_

#include <iostream>
#include <cstring>
#include "hora.hpp"

using namespace std;

class Turno {

    private:
        Hora horaInicio;
        Hora horaFinal;


    public:
        Turno();
        Turno(const Turno&);

        void ponerHoraInicio(const Hora&);
        void ponerHoraFinal(const Hora&);

        Hora dameHoraInicio()const;
        Hora dameHoraFinal()const;

        string aCadena()const;

        Turno& operator = (const Turno&);
        bool operator == (const Turno&);

        friend istream& operator >> (istream&, Turno&);
        friend ostream& operator << (ostream&, const Turno&);


        ~Turno();


    };

#endif /* _Turno_hh_ */

