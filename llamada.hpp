/*

 */

#ifndef _llamada_hpp_
#define _llamada_hpp_

#include <iostream>
#include <cstring>
#include <fstream>

#include "cliente.hpp"
#include "hora.hpp"

using namespace std;

class Llamada {

  private:
    Cliente cliente;
    Hora horaAtencion;
    Hora duracionLlamada;


  public:
    Llamada();
    Llamada(const Llamada&);
    // setters
    void ponerCliente(const Cliente&);
    void ponerDuracionLlamada(const Hora&);
    void ponerHoraAtencion(const Hora&);

    // getters
    string aCadena()const ;

    Cliente dameCliente()const ;
    Hora dameDuracionLlamada()const ;
    Hora dameHoraAtencion()const ;

    Llamada& operator = (const Llamada&);
    bool operator == (const Llamada&);
    bool operator < (const Llamada&);
    bool operator != (const Llamada&);
    bool operator <= (const Llamada&);

    bool operator > (const Llamada&);
    bool operator >= (const Llamada&);

    ~Llamada();
    friend istream& operator >> (istream&, Llamada&);
    friend ostream& operator << (ostream&, const Llamada&);

};

#endif /* _Llamada_hh_ */

