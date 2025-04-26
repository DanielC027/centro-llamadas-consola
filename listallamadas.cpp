
#include "listallamadas.hpp"
/// entregable 4
ListaLlamadas::ListaLlamadas():ancla(nullptr) {}

bool ListaLlamadas::posValida(LlamadaNodo* p) const {
    LlamadaNodo * aux = ancla;

    while(aux != nullptr) {
        if(aux == p) {
            return true;
            }
        aux = aux->dameSiguiente();
        }
    return false;
    }

bool ListaLlamadas::esVacia() const {
    return ancla == nullptr;
    }


void ListaLlamadas::insertaLlamada(LlamadaNodo* p, const Llamada& e) {
    if(p != nullptr and !posValida(p)) {
        throw ListaExcepcion("posicion invalida, insertaLlamada");
        }

    LlamadaNodo* aux = new LlamadaNodo(e);

    if(aux == nullptr) {
        throw ListaExcepcion("memoria no disponible, insertaLlamada");
        }

    if(p == nullptr) {
        if(esVacia()) {
            aux->ponerSig(nullptr);

            ancla = aux;
            }
        else {
            aux->ponerSig(ancla);
            ancla = aux;
            }
        }
    else {
        aux->ponerSig(p->dameSiguiente());

        p->ponerSig(aux);
        }
    }

void ListaLlamadas::insertaOrdenado(const Llamada& e) {
    LlamadaNodo* aux = ancla;
    LlamadaNodo* prev = nullptr;

    while(aux != nullptr and aux->dameLlamada() < e) {
        prev = aux;
        aux = aux->dameSiguiente();
        }

    insertaLlamada(prev,e);
    }


void ListaLlamadas::modificarDuracion(const Llamada& n, const Hora& d) {
    LlamadaNodo* aux = ancla;
    Llamada llam;

    while(aux != nullptr) {
        if(aux->dameLlamada() == n) {
            llam = aux->dameLlamada();
            llam.ponerDuracionLlamada(d);
            aux->ponerLlamada(llam);

            return;
            }
        aux = aux->dameSiguiente();
        }
    }


//-------- antes del 12/02/23 ------------
/// entregable 5

string ListaLlamadas::aCadena() const {
    string resultado = "";
    if(esVacia()) {
        return resultado;
        }
    LlamadaNodo * aux(ancla);

    while(aux != nullptr) {
        resultado += "\t" + aux->dameLlamada().aCadena() + "\n";
        aux = aux->dameSiguiente();
        }
    return resultado;
    }

LlamadaNodo * ListaLlamadas::dameAnterior(LlamadaNodo* p) {
    if(p == nullptr or !posValida(p)) {
        return nullptr;
        }

    LlamadaNodo * aux(ancla);

    while(aux->dameSiguiente() != p) {
        aux = aux->dameSiguiente();
        }

    return aux;
    }

void ListaLlamadas::eliminaLlamada(LlamadaNodo* p) {
    if(!posValida(p)) {
        throw ListaExcepcion("posicion invalida, eliminaLlamada");
        }

    if(p == ancla) {
        ancla = p->dameSiguiente();
        }
    else {
        dameAnterior(p)->ponerSig(p->dameSiguiente());
        }

    delete p;
    }


LlamadaNodo* ListaLlamadas::encontrarLlamada(const Llamada& e) {
    LlamadaNodo* aux = ancla;
    while(aux != nullptr and aux->dameLlamada() != e) {
        aux = aux->dameSiguiente();
        }


    return aux;
    }

void ListaLlamadas::eliminarTodasLlamadas() {
    if(esVacia()) {
        return;
        }

    LlamadaNodo* aux(ancla);

    while(aux != nullptr) {
        eliminaLlamada(aux);
        aux = ancla;
        }

    }


ListaLlamadas::~ListaLlamadas() {
    eliminarTodasLlamadas();
    }


///---------------------------------------

void ListaLlamadas::copiarTodo(const ListaLlamadas& l) {
    LlamadaNodo* aux(l.ancla);
    LlamadaNodo* ultimo(nullptr);
    LlamadaNodo* nvoNodo;

    while(aux != nullptr) {
        nvoNodo = new LlamadaNodo(aux->dameLlamada());

        if(nvoNodo == nullptr) {
            throw ListaExcepcion("memoria no disponible, copyAll");
            }

        if(ultimo == nullptr) {
            ancla = nvoNodo;
            }
        else {
            ultimo->ponerSig(nvoNodo);
            }

        ultimo = nvoNodo;

        aux = aux->dameSiguiente();
        }
    }

ListaLlamadas::ListaLlamadas(const ListaLlamadas& l):ListaLlamadas() {
    copiarTodo(l);
    }

LlamadaNodo* ListaLlamadas::damePrimero() {
    return ancla;
    }

LlamadaNodo* ListaLlamadas::dameUltimo() {
    if(esVacia()) {
        return nullptr;
        }

    LlamadaNodo* aux = ancla;

    while(aux->dameSiguiente() != nullptr) {
        aux = aux->dameSiguiente();
        }

    return aux;
    }

LlamadaNodo* ListaLlamadas::dameSiguiente(LlamadaNodo* p) {
    if(!posValida(p)) {
        return nullptr;
        }

    return p->dameSiguiente();
    }

Llamada ListaLlamadas::recuperar(LlamadaNodo* p)const {
    if(!posValida(p)) {
        throw ListaExcepcion("posicion no valida, recuperar");
        }
    return p->dameLlamada(); // no retorna memoria pero vemos

    }

ListaLlamadas& ListaLlamadas::operator = (const ListaLlamadas& l) {
    eliminarTodasLlamadas();
    copiarTodo(l);

    return *this;
    }

void ListaLlamadas::escribirDisco(const string& nombreArchivo) {
    ofstream miArchivo;

    miArchivo.open(nombreArchivo,miArchivo.trunc);

    if(!miArchivo.is_open()) {
        string msg;
        msg += " El archivo " ;
        msg += nombreArchivo + " no se pudo abrir archivo escritura.";

        throw ListaExcepcion(msg);
        }

    LlamadaNodo* aux(ancla);

    while(aux != nullptr) {
        miArchivo << aux->dameLlamada() << endl;

        aux = aux->dameSiguiente();
        }

    miArchivo.close();
    }

void ListaLlamadas::leerDisco(const string& nombreArchivo) {
    ifstream miArchivo;

    miArchivo.open(nombreArchivo);
    if(!miArchivo.is_open()) {
        throw ListaExcepcion("no se pudo abrir el archivo de lectura de llamadas");
        }
    eliminarTodasLlamadas(); // importante

    Llamada misDatos;

    LlamadaNodo* ultimoNodo(nullptr);
    LlamadaNodo* nvoNodo;

    try {
        while(miArchivo >> misDatos) { /// miArchivo es un flujo, no una cadena
            /// insertarj datos

            if((nvoNodo = new LlamadaNodo(misDatos)) == nullptr) {
                miArchivo.close();
                throw ListaExcepcion("memoria no disponible, leer del disco llamadas");
                }

            if(ultimoNodo == nullptr) {
                ancla = nvoNodo;
                }
            else {
                ultimoNodo->ponerSig(nvoNodo);
                }
            ultimoNodo = nvoNodo;
            miArchivo.ignore(1, '\n');
            }
        }
    catch(const invalid_argument& ex) {}

    miArchivo.close();

    }

