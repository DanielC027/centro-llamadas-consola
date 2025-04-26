/*

 */

#ifndef _agente_hpp_
#define _agente_hpp_

#include "listallamadas.hpp"
#include "nombre.hpp"
#include "turno.hpp"
#include "hora.hpp"

class Agente {

    private:
        Nombre nombre;
        Turno horarioTrabajo;
        string numeroDeEmpleado;
        string numeroDeExtension;
        Hora horasExtrasTrabajadas;
        string especialidad;
        ListaLlamadas listaLlamadas;


    public:
        Agente();
        Agente(Agente&);

        void ponerNombre(const Nombre&);
        void ponerHorarioDeTrabajo(const Turno&);
        void ponerNumeroEmpleado(const string&);
        void ponerNumeroExtension(const string&);
        void ponerHorasExtrasTrabajadas(const Hora&);
        void ponerEspecialidad(const string&);
        void ponerListaLlamadas(const ListaLlamadas&);

        string aCadena(const bool&)const;

        Nombre dameNombre()const ;
        Turno dameHorarioDeTrabajo()const ;
        string dameNumeroEmpleado()const ;
        string dameNumeroDeExtension()const ;
        Hora dameHorasExtrasTrabajadas()const ;
        string dameEspecialidad()const ;
        ListaLlamadas& dameListaLlamadas();

        Agente& operator =(Agente&);
        bool operator ==(const Agente&);

        friend istream& operator >> (istream&, Agente&);
        friend ostream& operator << (ostream&, const Agente&);

        ~Agente();


    };

#endif /* _Agente_hh_ */

