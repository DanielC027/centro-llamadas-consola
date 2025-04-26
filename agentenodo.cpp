
#include "agentenodo.hpp"

AgenteNodo::AgenteNodo():nodoAnte(nullptr), agente(nullptr), nodoSig(nullptr) {}

AgenteNodo::AgenteNodo(Agente& e):nodoAnte(nullptr), agente(new Agente(e)), nodoSig(nullptr) {
    if(agente == nullptr) {
        throw AgenteNodoExcepcion("Memoria no disponible, creando AgenteNodo ");
        }
    }

AgenteNodo::~AgenteNodo() {
    delete agente;
    }

void AgenteNodo::ponerAgente(Agente& e) {
    delete agente;

    agente = new Agente(e);

    if(agente == nullptr) {
        throw AgenteNodoExcepcion("Memoria no disponible, ponerAgente");
        }
    }

void AgenteNodo::ponerAgentePtr(Agente* p)
{
    agente = p;
}

void AgenteNodo::ponerNodoSig(AgenteNodo* p) {
    nodoSig = p;
    }

void AgenteNodo::ponerNodoAnte(AgenteNodo* p) {
    nodoAnte = p;
    }

Agente& AgenteNodo::dameAgente() const {
    return *agente;
    }

Agente* AgenteNodo::dameAgentePtr() {
    if(agente == nullptr) {
        throw AgenteNodoExcepcion("Error, el dato no existe.");
        }

    return agente;
    }

AgenteNodo* AgenteNodo::dameNodoSig() {
    return nodoSig;
    }

AgenteNodo* AgenteNodo::dameNodoAnte() {
    return nodoAnte;
    }
