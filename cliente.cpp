
#include "cliente.hpp"

Cliente::Cliente() {

    }

Cliente::Cliente(const Cliente& client):nombre(client.dameNombre()),numeroCuenta(client.dameNumeroCuenta()),numeroTelefono(client.dameNumeroTelefono()) {}

void Cliente::ponerNombre(const Nombre& nom) {
    nombre = nom;
    }

void Cliente::ponerNumeroCuenta(const string& numC) {
    numeroCuenta = numC;
    }

void Cliente::ponerNumeroTelefono(const string& numT) {
    numeroTelefono = numT;
    }

string Cliente::aCadena() const {
    string resultado;

    resultado += nombre.aCadena();  // 63
    resultado += " | ";
    resultado += numeroCuenta;      // 79
    resultado.resize(79,' ');
    resultado += " | ";
    resultado += numeroTelefono;
    resultado.resize(92,' ');

    return resultado;
    }

Nombre Cliente::dameNombre() const {
    return nombre;
    }

string Cliente::dameNumeroCuenta() const {
    return numeroCuenta;
    }

string Cliente::dameNumeroTelefono() const {
    return numeroTelefono;
    }

Cliente & Cliente::operator = (const Cliente& client) {
    nombre = client.dameNombre();
    numeroCuenta = client.dameNumeroCuenta();
    numeroTelefono = client.dameNumeroTelefono();
    return *this;
    }

bool Cliente::operator == (const Cliente& client) {
    return numeroCuenta == client.dameNumeroCuenta() and nombre == client.dameNombre() and numeroTelefono == client.dameNumeroTelefono();
    }

istream& operator >> (istream& is, Cliente& e) {
    is >> e.nombre;
    getline(is, e.numeroCuenta);
    getline(is, e.numeroTelefono);

    return is;
    }

ostream& operator << (ostream& os, const Cliente& e) {
    os << e.nombre << endl;
    os << e.numeroCuenta << endl;
    os << e.numeroTelefono;

    return os;
    }

Cliente::~Cliente() {

    }

