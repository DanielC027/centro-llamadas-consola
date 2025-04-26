/*

 */

#ifndef _hora_hpp_
#define _hora_hpp_

#include <cstring>
#include <cstdio>
#include <iostream>
#include <chrono>

using namespace std;

class Hora {

    private:
        int hora;
        int minutos;
        int segundos;

        bool esValida(const int&,const int&,const int&);
        int aEntero()const;

    public:
        Hora();
        Hora(const Hora&);
        Hora(const int&,const int&,const int&);

        void ponerHora(const int&);
        void ponerMinutos(const int&);
        void ponerSegundos(const int&);

        string aCadena()const ;

        int dameHora()const;
        int dameMinutos()const;
        int dameSegundos()const;


        Hora& operator =(const Hora&);

        bool operator ==(const Hora&);
        bool operator >(const Hora&);
        bool operator <(const Hora&);
        bool operator >=(const Hora&);
        bool operator <=(const Hora&);
        bool operator !=(const Hora&);

        friend std::istream& operator >> (std::istream&, Hora&);
        friend std::ostream& operator << (std::ostream&, const Hora&);
        ~Hora();


    };

#endif /* _Hora_hh_ */

