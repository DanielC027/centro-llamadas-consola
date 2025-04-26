
#include "agente.hpp"

Agente::Agente() {}

Agente::Agente(Agente& e):nombre(e.dameNombre()),horarioTrabajo(e.dameHorarioDeTrabajo()),numeroDeEmpleado(e.dameNumeroEmpleado()),numeroDeExtension(e.dameNumeroDeExtension()),horasExtrasTrabajadas(e.dameHorasExtrasTrabajadas()),especialidad(e.dameEspecialidad()),listaLlamadas(e.dameListaLlamadas()) {}

void Agente::ponerNombre(const Nombre& n) {
    nombre = n;
    }

void Agente::ponerHorarioDeTrabajo(const Turno& t) {
    horarioTrabajo = t;
    }

void Agente::ponerNumeroEmpleado(const string& n) {
    numeroDeEmpleado = n;
    }

void Agente::ponerNumeroExtension(const string& n) {
    numeroDeExtension = n;
    }

void Agente::ponerHorasExtrasTrabajadas(const Hora& h) {
    horasExtrasTrabajadas = h;
    }

void Agente::ponerEspecialidad(const string& e) {
    especialidad = e;
    }

void Agente::ponerListaLlamadas(const ListaLlamadas& l) {
    listaLlamadas = l;
    }


string Agente::aCadena(const bool& conLista = false) const {
    string resultado = "";

    resultado += "_______________________________________________________________________________________________________________________________________\n\n";
    resultado += "\tAGENTE\n";
    resultado += "NOMBRE                            APELLIDO                HORARIO  INIC.      FIN.     NUM. EMPL.   EXTEN.  HRS. EXTR.   ESPECIA.\n\n";
    resultado += nombre.aCadena();
    resultado += " | ";
    resultado += horarioTrabajo.aCadena();
    resultado += " | ";
    resultado += numeroDeEmpleado;
    resultado += " | ";
    resultado += numeroDeExtension;
    resultado += " | ";
    resultado += horasExtrasTrabajadas.aCadena();
    resultado += " | ";
    resultado += especialidad;

    if(conLista == true) {
        resultado += "\n\n**********************************\n";
        resultado += "\t\tLLAMADAS\n";
        resultado += "\t NOMBRE                          APELLIDO                        NUM. CUENTA     TELEFONO     DURACION   HORA ATENCION\n\n";
        resultado +=  listaLlamadas.aCadena();
        resultado += "\n**********************************\n\n";
        }
    resultado += "\n_______________________________________________________________________________________________________________________________________\n\n";
    return resultado;
    }


Nombre Agente::dameNombre() const {
    return nombre;
    }

Turno Agente::dameHorarioDeTrabajo() const {
    return horarioTrabajo;
    }

string Agente::dameNumeroEmpleado() const {
    return numeroDeEmpleado;
    }

string Agente::dameNumeroDeExtension() const {
    return numeroDeExtension;
    }

Hora Agente::dameHorasExtrasTrabajadas() const {
    return horasExtrasTrabajadas;
    }

string Agente::dameEspecialidad() const {
    return especialidad;
    }

ListaLlamadas& Agente::dameListaLlamadas() {
    return listaLlamadas;
    }

Agente& Agente::operator = ( Agente& e) {
    nombre = e.dameNombre();
    horarioTrabajo = e.dameHorarioDeTrabajo();
    numeroDeEmpleado = e.dameNumeroEmpleado();
    numeroDeExtension = e.dameNumeroDeExtension();
    horasExtrasTrabajadas = e.dameHorasExtrasTrabajadas();
    especialidad = e.dameEspecialidad();
    listaLlamadas = e.dameListaLlamadas();

    return *this;
    }

bool Agente::operator == (const Agente& e) {
    return nombre == e.dameNombre();
    }

istream& operator >> (istream& is, Agente& e){
    is >> e.nombre;
    is >> e.horarioTrabajo;
    getline(is,e.numeroDeEmpleado);
    getline(is,e.numeroDeExtension);
    is >> e.horasExtrasTrabajadas;
    getline(is, e.especialidad);

    return is;
}

ostream& operator << (ostream& os, const Agente& a){
    string nombreLista = "";

    os << a.nombre << endl;
    os << a.horarioTrabajo << endl;
    os << a.numeroDeEmpleado << endl;
    os << a.numeroDeExtension << endl;
    os << a.horasExtrasTrabajadas << endl;
    os << a.especialidad << endl;

    return os;
}

Agente::~Agente() {

    }
