/*

 */

#ifndef _listallamadas_hpp_
#define _listallamadas_hpp_

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdexcept>


#include "llamadanodo.hpp"
#include "listaexcepcion.hpp"
#include "llamada.hpp"
#include "hora.hpp"

using namespace std;
class ListaLlamadas {

    private:
        LlamadaNodo* ancla;

        bool posValida(LlamadaNodo*)const;
        void copiarTodo(const ListaLlamadas&);

    public:
        ListaLlamadas();
        ListaLlamadas(const ListaLlamadas&);

        bool esVacia()const ;
        void insertaLlamada(LlamadaNodo*, const Llamada&);
        void insertaOrdenado(const Llamada&);

        void modificarDuracion(const Llamada&, const Hora&);

        void eliminaLlamada(LlamadaNodo*);

        LlamadaNodo * damePrimero();
        LlamadaNodo * dameUltimo();
        LlamadaNodo * dameAnterior(LlamadaNodo*);
        LlamadaNodo * dameSiguiente(LlamadaNodo*);

        LlamadaNodo * encontrarLlamada(const Llamada&);
        Llamada recuperar(LlamadaNodo*)const;

        string aCadena()const ;

        void eliminarTodasLlamadas();

        ListaLlamadas & operator = (const ListaLlamadas&);

        void escribirDisco(const string&);
        void leerDisco(const string&);

        ~ListaLlamadas();


    };

#endif /* _ListaLlamadas_hh_ */

