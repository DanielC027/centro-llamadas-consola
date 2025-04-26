#include "llamadanodo.hpp"

LlamadaNodo::LlamadaNodo():llamadaSig(nullptr){}

LlamadaNodo::LlamadaNodo(const Llamada& e):llamada(e),llamadaSig(nullptr){}

void LlamadaNodo::ponerLlamada(const Llamada& e)
{
    llamada = e;
}

void LlamadaNodo::ponerSig(LlamadaNodo* p)
{
    llamadaSig = p;
}

Llamada LlamadaNodo::dameLlamada()
{
    return llamada;
}

LlamadaNodo* LlamadaNodo::dameSiguiente() const
{
    return llamadaSig;
}

LlamadaNodo::~LlamadaNodo()
{

}



