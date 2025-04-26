/*
    Clase LlamadaNodo Ayuda a la lista de llamadas
 */

#ifndef _llamadanodo_hpp_
#define _llamadanodo_hpp_

#include "llamada.hpp"

class LlamadaNodo {

    private:
        Llamada llamada;
        LlamadaNodo * llamadaSig;


    public:
        LlamadaNodo();
        LlamadaNodo(const Llamada&);
        // setters
        void ponerLlamada(const Llamada&);
        void ponerSig(LlamadaNodo*);
        // getters
        Llamada dameLlamada() ;
        LlamadaNodo  * dameSiguiente()const ;

        ~LlamadaNodo();


    };

#endif /* _LlamadaNodo_hh_ */

