
#include "llamada.hpp"

Llamada::Llamada() {}

Llamada::Llamada(const Llamada& llam):cliente(llam.dameCliente()),duracionLlamada(llam.dameDuracionLlamada()),horaAtencion(llam.dameHoraAtencion()) {}

void Llamada::ponerCliente(const Cliente& client) {
    cliente = client;
    }

void Llamada::ponerDuracionLlamada(const Hora& dLlam) {
    duracionLlamada = dLlam;
    }

void Llamada::ponerHoraAtencion(const Hora& hAten) {
    horaAtencion = hAten;
    }

string Llamada::aCadena() const {
    string resultado;

    resultado += cliente.aCadena(); // 92
    resultado += " | ";
    resultado += duracionLlamada.aCadena();
    resultado += " | ";
    resultado += horaAtencion.aCadena();

    return resultado; // 114
    }

Cliente Llamada::dameCliente() const {
    return cliente;
    }

Hora Llamada::dameDuracionLlamada() const {
    return duracionLlamada;
    }

Hora Llamada::dameHoraAtencion() const {
    return horaAtencion;
    }

Llamada & Llamada::operator = (const Llamada& llam) {
    cliente = llam.dameCliente();
    duracionLlamada = llam.dameDuracionLlamada();
    horaAtencion = llam.dameHoraAtencion();
    return *this;
    }

bool Llamada::operator == (const Llamada& llam) {
    return horaAtencion == llam.dameHoraAtencion();
    }

bool Llamada::operator>(const Llamada& llam) {
    return  horaAtencion > llam.dameHoraAtencion();
    }

bool Llamada::operator!=(const Llamada& llam) {
    return !(*this == llam);
    }

bool Llamada::operator>=(const Llamada& llam) {
    return *this == llam or *this > llam;
    }

bool Llamada::operator<(const Llamada& llam) {
    return horaAtencion < llam.dameHoraAtencion();
    }

bool Llamada::operator<=(const Llamada& llam) {
    return *this < llam or *this == llam;
    }
istream& operator >>(istream& is, Llamada& e) {
    is >> e.cliente;
    is >> e.horaAtencion;
    is >> e.duracionLlamada;
    return is;
    }

ostream& operator << (ostream& os, const Llamada& e) {
    os << e.cliente << endl;
    os << e.horaAtencion << endl;
    os << e.duracionLlamada << endl;

    return os;
    }

Llamada::~Llamada() {

    }
