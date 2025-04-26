
#include "turno.hpp"

Turno::Turno() {};

Turno::Turno(const Turno& t):horaInicio(t.dameHoraInicio()),horaFinal(t.dameHoraFinal()) {};

void Turno::ponerHoraInicio(const Hora& h) {
    horaInicio = h;
    }

void Turno::ponerHoraFinal(const Hora& h) {
    horaFinal = h;
    }

Hora Turno::dameHoraInicio() const {
    return horaInicio;
    }

Hora Turno::dameHoraFinal() const {
    return horaFinal;
    }

string Turno::aCadena() const {
    string resultado;

    resultado += horaInicio.aCadena();
    resultado += " | ";
    resultado += horaFinal.aCadena();

    return resultado;
    }

Turno& Turno::operator = (const Turno& t) {
    horaInicio = t.dameHoraInicio();
    horaFinal = t.dameHoraFinal();

    return *this;
    }

bool Turno::operator == (const Turno& t) {
    return horaFinal == t.dameHoraFinal() and horaInicio == t.dameHoraInicio();
    }

istream& operator >> (istream& is, Turno& t) {
    is >> t.horaInicio;
    is >> t.horaFinal;

    return is;
    }

ostream& operator << (ostream& os, const Turno& t) {
    os << t.horaInicio << endl;
    os << t.horaFinal;

    return os;
    }

Turno::~Turno() {

    }
