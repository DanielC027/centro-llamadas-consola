#ifndef MENULLAMADAS_HPP_INCLUDED
#define MENULLAMADAS_HPP_INCLUDED

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#include "listallamadas.hpp"

#ifdef __WIN32
#define LIMPEA_PANTALLA "cls"
#else
#define LIMPEA_PANTALLA "clear"
#endif // __WIN32

class MenuLlamadas {
    private:
        ListaLlamadas * listaLlamadas;

    public:
        MenuLlamadas(ListaLlamadas*);

        void menuPrincipal();

        void agregarLlamada();

        void modificarDuracion();

        void eliminarLlamada();

        void muestraLista();

        void eliminaTodo();

        void enterParaContinuar();

        void limpeaPantalla();

        ~MenuLlamadas();

    };


#endif // MENULLAMADAS_HPP_INCLUDED
