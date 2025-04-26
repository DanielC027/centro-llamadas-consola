/*
    Aqui se encuentra la clase NodoAgente que ayuda a la lista de agentes
 */

#ifndef _agentenodo_hpp_
#define _agentenodo_hpp_

#include <exception>

#include <cstring>
#include "agente.hpp"

class AgenteNodoExcepcion : public std::exception {
    private:
        std::string msg;

    public:
        explicit AgenteNodoExcepcion(const char* message) : msg(message) {}

        explicit AgenteNodoExcepcion(const std::string& message) : msg(message) {}

        virtual ~AgenteNodoExcepcion() throw () {}

        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };



class AgenteNodo {

    private:
        Agente* agente;
        AgenteNodo* nodoSig;
        AgenteNodo* nodoAnte;


    public:
        AgenteNodo();
        AgenteNodo(Agente&);

        void ponerAgente(Agente&);
        void ponerAgentePtr(Agente*);
        void ponerNodoSig(AgenteNodo*);
        void ponerNodoAnte(AgenteNodo*);

        Agente& dameAgente()const;
        Agente* dameAgentePtr();
        AgenteNodo* dameNodoSig();
        AgenteNodo* dameNodoAnte();

        ~AgenteNodo();
    };

#endif /* _AgenteNodo_hh_ */

