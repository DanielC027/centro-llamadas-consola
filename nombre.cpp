

#include "nombre.hpp"

Nombre::Nombre() {
    nombre = "Jesus";
    apellido = "De Nazaret";
    }

Nombre::Nombre(const Nombre& nom):nombre(nom.dameNombre()),apellido(nom.dameApellido()) {}

void Nombre::ponNombre(const string& n) {
    nombre = n;
    }

void Nombre::ponApellido(const string& a) {
    apellido = a;
    }

string Nombre::dameNombre() const {
    return nombre;
    }

string Nombre::dameApellido() const {
    return apellido;
    }

/**
*
*   retorna cadena de 83
*
*/

string Nombre::aCadena() const {
    string resultado;

    resultado += nombre;
    resultado.resize(30,' ');
    resultado += " | ";
    resultado += apellido;
    resultado.resize(63,' ');

    return resultado;
    }

Nombre & Nombre::operator = (const Nombre& nom) {
    nombre = nom.dameNombre();
    apellido = nom.dameApellido();

    return *this;
    }

bool Nombre::operator == (const Nombre& nom) {
    return aCadena() == nom.aCadena();
    }

bool Nombre::operator<(const Nombre& nom) {
    return aCadena() < nom.aCadena();
    }

bool Nombre::operator>(const Nombre& nom) {
    return !(*this <= nom);
    }

bool Nombre::operator>=(const Nombre& nom) {
    return *this > nom or *this == nom;
    }

bool Nombre::operator<=(const Nombre& nom) {
    return *this == nom or *this < nom;
    }

bool Nombre::operator!=(const Nombre& nom) {
    return !(*this == nom);
    }

istream& operator >> (istream& is, Nombre& e) {
    getline(is, e.nombre);
    getline(is, e.apellido);

    return is;
    }

ostream& operator << (ostream& os, const Nombre& e) {
    os << e.nombre << endl;
    os << e.apellido;

    return os;
    }

Nombre::~Nombre() {

    }
