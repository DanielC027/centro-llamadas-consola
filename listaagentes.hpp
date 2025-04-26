/*

 */

#ifndef _listaagentes_hpp_
#define _listaagentes_hpp_

#include <stdexcept>
#include "agentenodo.hpp"
#include "agente.hpp"


class ListaAgentes {

    private:
        AgenteNodo* ancla;

        bool posValida(AgenteNodo*)const;

        void copiarTodo(const ListaAgentes&);

        void ordenarPorNombre(AgenteNodo*,AgenteNodo*);
        void ordenarPorEspecialidad(AgenteNodo*,AgenteNodo*);

        void cambiarPtr(AgenteNodo*,AgenteNodo*);

    public:
        ListaAgentes();
        ListaAgentes(const ListaAgentes&);

        bool esVacia()const ;

        void insertaAgente(Agente&);

        void eliminaAgente(AgenteNodo*);

        AgenteNodo* damePrimero();
        AgenteNodo* dameUltimo();
        AgenteNodo* dameAnterior(AgenteNodo*);
        AgenteNodo* dameSiguiente(AgenteNodo*);
        Agente& recuperar(AgenteNodo*)const;
        AgenteNodo* encontrarAgente(const Agente&);

        string aCadena(const bool&)const;
        string filtrarEspecialidad(const bool&, const string&)const;

        void ordenarPorEspecialidad();
        void ordenarPorNombre();

        void eliminarTodosAgentes();

        void escribirDisco(const std::string&);
        void leerDisco(const std::string&);

        ~ListaAgentes();

    };

#endif /* _ListaAgentes_hh_ */

