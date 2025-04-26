#ifndef MENUAGENTES_HPP_INCLUDED
#define MENUAGENTES_HPP_INCLUDED

#include <iostream>
#include <cstring>

#include "menullamadas.hpp"
#include "listaagentes.hpp"
#include "agentenodo.hpp"
#include "agente.hpp"
#include "nombre.hpp"
#include "hora.hpp"
#include "turno.hpp"
#include <algorithm>



#ifdef __WIN32
#define LIMPEA_PANTALLA "cls"
#else
#define LIMPEA_PANTALLA "clear"
#endif // __WIN32

class MenuAgentes {
    private:
        ListaAgentes * listaRef;

        bool inicioSesion();

        void menuPrincipal();

        void agregarAgente();

        void eliminarAgente();
        void eliminarListaAgentes();

        void mostrarAgentes();
        void mostrarAgentesFiltrados();

        void ordenarAgentePorNombre();
        void ordenarAgentePorEspecialidad();

        void modificarAgente();
        void regresar();

        void escribirEnDisco();
        void leerDelDisco();
    public:
        MenuAgentes(ListaAgentes*);



        void limpeaPantalla();
        void enterParaContinuar();
        ~MenuAgentes();
    };

#endif // MENUAGENTES_HPP_INCLUDED
