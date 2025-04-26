
#include "listaagentes.hpp"

/// ---------------------------- ENTREGABLE 7

ListaAgentes::ListaAgentes() : ancla(nullptr) {}

ListaAgentes::ListaAgentes(const ListaAgentes& l):ListaAgentes() {
    eliminarTodosAgentes();

    copiarTodo(l);
    }

bool ListaAgentes::esVacia() const {
    return ancla == nullptr;
    }

bool ListaAgentes::posValida(AgenteNodo* p) const {
    AgenteNodo * aux = ancla;

    while(aux != nullptr) {
        if(aux == p) {
            return true;
            }
        aux = aux->dameNodoSig();
        }
    return false;
    }


string ListaAgentes::aCadena(const bool& conLlam = false) const {
    string resultado = "";

    if(esVacia()) {
        return resultado;
        }

    AgenteNodo* aux = ancla;

    while(aux != nullptr) {
        resultado += aux->dameAgente().aCadena(conLlam) + "\n\n";
        aux = aux->dameNodoSig();
        }

    return resultado;
    }

string ListaAgentes::filtrarEspecialidad(const bool& conLlam = false, const string& especialidad = "") const
{
    string resultado = "";

    if(esVacia()) {
        return resultado;
        }

    AgenteNodo* aux = ancla;

    while(aux != nullptr) {
            if(aux->dameAgente().dameEspecialidad() == especialidad){
                resultado += aux->dameAgente().aCadena(conLlam) + "\n\n";
            }
        aux = aux->dameNodoSig();
        }

    return resultado;
}

void ListaAgentes::insertaAgente( Agente& e) {
    AgenteNodo* aux;

    if(esVacia()) {
        try {
            aux = new AgenteNodo(e);
            }
        catch (const AgenteNodoExcepcion& ex) {
            /// Hacer algo
            throw ListaExcepcion(ex.what());
            }
        if(aux == nullptr) {
            throw AgenteNodoExcepcion(" Error memoria no disponible, insertaAgente");
            }
        ancla = aux;
        }
    else {
        aux = ancla;
        AgenteNodo* nvoNodo;

        try {
            nvoNodo = new AgenteNodo(e);
            }
        catch (const AgenteNodoExcepcion& ex) {
            /// Hacer algo
            throw ListaExcepcion(ex.what());
            }

        if(nvoNodo == nullptr) {
            throw AgenteNodoExcepcion(" Error memoria no disponible, insertaAgente");
            }

        while(dameSiguiente(aux) !=  nullptr) {
            aux = dameSiguiente(aux);
            }

        aux->ponerNodoSig(nvoNodo);
        nvoNodo->ponerNodoAnte(aux);
        }
    }
/// ----------------------------

/// Entregable 8
AgenteNodo* ListaAgentes::damePrimero() {
    if(esVacia()) {
        return nullptr;
        }
    return ancla;
    }

AgenteNodo* ListaAgentes::dameUltimo() {
    if(esVacia()) {
        return nullptr;
        }

    AgenteNodo* aux = ancla;

    while(dameSiguiente(aux) != nullptr) {
        aux = dameSiguiente(aux);
        }

    return aux;
    }

AgenteNodo* ListaAgentes::dameAnterior(AgenteNodo* p) {
    if(!posValida(p) or p == ancla) {
        return nullptr;
        }
    return p->dameNodoAnte();
    }

AgenteNodo* ListaAgentes::dameSiguiente(AgenteNodo* p) {
    if(!posValida(p) or p == nullptr) {
        return nullptr;
        }
    return p->dameNodoSig();
    }

void ListaAgentes::eliminaAgente(AgenteNodo* p) {
    if(!posValida(p)) {
        throw ListaExcepcion("posicion no existe en la lista, eliminaAgente");
        }
    if(dameAnterior(p) == nullptr) {
        ancla = p->dameNodoSig();
        if(ancla != nullptr) {
            ancla->ponerNodoAnte(nullptr);
            }
        delete p;
        }
    else {
        dameAnterior(p)->ponerNodoSig(dameSiguiente(p));
        if(dameSiguiente(p) == nullptr) {
            delete p;
            }
        else {
            dameSiguiente(p)->ponerNodoAnte(dameAnterior(p));
            delete p;
            }
        }
    }


AgenteNodo* ListaAgentes::encontrarAgente(const Agente& e) {
    if(esVacia()) {
        return nullptr;
        }

    AgenteNodo* aux = ancla;

    while(aux != nullptr) {
        if(aux->dameAgente() == e) {
            return aux;
            }
        aux = dameSiguiente(aux);
        }

    return nullptr;
    }

ListaAgentes::~ListaAgentes() {
    eliminarTodosAgentes();
    delete ancla;
    }

void ListaAgentes::eliminarTodosAgentes() {
    if(esVacia()) {
        return;
        }

    AgenteNodo* aux;
    while (ancla != nullptr) {
        aux = ancla;
        ancla = dameSiguiente(aux);

        delete aux;
        }
    }


void ListaAgentes::copiarTodo(const ListaAgentes& l) {
    AgenteNodo* aux(l.ancla);
    AgenteNodo* ultimo(nullptr);
    AgenteNodo* nvoNodo;

    while(aux != nullptr) {

        try {
            nvoNodo = new AgenteNodo(recuperar(aux));
            }
        catch(const AgenteNodoExcepcion& ex) {
            string msg;

            msg = "Ha ocurrido un error, el error resportado es:\n";
            msg += ex.what();
            msg += "\n Si esto ocurre continuamente, reporte a sistemas. \n";

            throw ListaExcepcion(msg);
            }

        if(nvoNodo == nullptr) {
            throw ListaExcepcion("memoria no disponible, copyAll");
            }

        if(ultimo == nullptr) {
            ancla = nvoNodo;
            }
        else {
            ultimo->ponerNodoSig(nvoNodo);
            }

        ultimo = nvoNodo;

        aux = dameSiguiente(aux);
        }
    }

Agente& ListaAgentes::recuperar(AgenteNodo* p) const {
    if(!posValida(p)) {
        throw ListaExcepcion("Error, no se encuentra en la lista, recuperar.");
        }
    return p->dameAgente();
    }


/// -----------------------------------
void ListaAgentes::cambiarPtr(AgenteNodo* a, AgenteNodo* b) {
    Agente* aux = a->dameAgentePtr();
    a->ponerAgentePtr(b->dameAgentePtr());
    b->ponerAgentePtr(aux);
    }

void ListaAgentes::ordenarPorNombre(AgenteNodo* izquierdo, AgenteNodo* derecho) {
    if(izquierdo == derecho) {
        return;
        }
    if(dameSiguiente(izquierdo) == derecho) {
        if(izquierdo->dameAgente().dameNombre() > derecho->dameAgente().dameNombre()) {
            cambiarPtr(izquierdo,derecho);
            }
        return;
        }

    /// Separacion
    AgenteNodo* i = izquierdo;
    AgenteNodo* j = derecho;


    while(i != j) {
        while(i != j and i->dameAgente().dameNombre() <= derecho->dameAgente().dameNombre()) {
            i = i->dameNodoSig();
            }
        while(i != j and j->dameAgente().dameNombre() >= derecho->dameAgente().dameNombre()) {
            j = j->dameNodoAnte();
            }

        if(i != j) {
            cambiarPtr(i,j);

            i = i->dameNodoSig();

            if(i != j) {
                j = j ->dameNodoAnte();
                }
            }
        }
    if(i != derecho) { /// ubicar pivote en su lugar
        cambiarPtr(i,derecho);
        }

    if(i != izquierdo) { /// ordenar lado izquierdo
        ordenarPorNombre(izquierdo,i->dameNodoAnte());
        }

    if(i != derecho) { /// ordenar lado derecho
        ordenarPorNombre(i->dameNodoSig(),derecho);
        }
    }

void ListaAgentes::ordenarPorNombre() {
    ordenarPorNombre(damePrimero(),dameUltimo());
    }


void ListaAgentes::ordenarPorEspecialidad(AgenteNodo* izquierdo, AgenteNodo* derecho) {
    if(izquierdo == derecho) {
        return;
        }
    if(dameSiguiente(izquierdo) == derecho) {
        if(izquierdo->dameAgente().dameEspecialidad() > derecho->dameAgente().dameEspecialidad()) {
            cambiarPtr(izquierdo,derecho);
            }
        return;
        }

    /// Separacion
    AgenteNodo* i = izquierdo;
    AgenteNodo* j = derecho;


    while(i != j) {
        while(i != j and i->dameAgente().dameEspecialidad() <= derecho->dameAgente().dameEspecialidad()) {
            i = i->dameNodoSig();
            }
        while(i != j and j->dameAgente().dameEspecialidad() >= derecho->dameAgente().dameEspecialidad()) {
            j = j->dameNodoAnte();
            }

        if(i != j) {
            cambiarPtr(i,j);

            i = i->dameNodoSig();

            if(i != j) {
                j = j ->dameNodoAnte();
                }
            }
        }
    if(i != derecho) { /// ubicar pivote en su lugar
        cambiarPtr(i,derecho);
        }

    if(i != izquierdo) { /// ordenar lado izquierdo
        ordenarPorEspecialidad(izquierdo,i->dameNodoAnte());
        }

    if(i != derecho) { /// ordenar lado derecho
        ordenarPorEspecialidad(i->dameNodoSig(),derecho);
        }
    }


void ListaAgentes::ordenarPorEspecialidad() {
    ordenarPorEspecialidad(damePrimero(),dameUltimo());
    }

void ListaAgentes::escribirDisco(const string& nombreArchivo) {
    ofstream miArchivo;

    miArchivo.open(nombreArchivo,miArchivo.trunc);

    if(!miArchivo.is_open()) {
        string msg;
        msg += " El archivo " ;
        msg += nombreArchivo + " no se pudo abrir archivo escritura.";

        throw ListaExcepcion(msg);
        }

    AgenteNodo* aux(ancla);

    while(aux != nullptr) {
        miArchivo << aux->dameAgente() << endl;

        try {
            aux->dameAgentePtr()->dameListaLlamadas().escribirDisco(aux->dameAgente().dameNumeroEmpleado() + ".llamadas");
            }
        catch(const ListaExcepcion& ex) {
            cout << endl << ex.what() << endl;
            }
        aux = aux->dameNodoSig();
        }

    miArchivo.close();
    }

void ListaAgentes::leerDisco(const string& nombreArchivo) {
    ifstream miArchivo;

    miArchivo.open(nombreArchivo);

    if(!miArchivo.is_open()) {
        string msg;
        msg += " El archivo " ;
        msg += nombreArchivo + " no se pudo abrir archivo lectura.";

        throw ListaExcepcion(msg);
        }

    eliminarTodosAgentes();

    Agente misDatos;

    AgenteNodo* nvoNodo;

    try {

        while(miArchivo >> misDatos) {
            misDatos.dameListaLlamadas().leerDisco(misDatos.dameNumeroEmpleado() + ".llamadas");
            try {
                if((nvoNodo = new AgenteNodo(misDatos)) == nullptr) {
                    miArchivo.close();
                    throw ListaExcepcion("Memoria no disponible, leer del disco Lista Agentes");
                    }
                }
            catch(const AgenteNodoExcepcion& ex) {
                miArchivo.close();
                throw ListaExcepcion(ex.what());
                }
            if(ancla == nullptr) {
                ancla = nvoNodo;
                }
            else {
                AgenteNodo* aux;

                aux = ancla;

                while(dameSiguiente(aux) !=  nullptr) {
                    aux = dameSiguiente(aux);
                    }
                aux->ponerNodoSig(nvoNodo);
                nvoNodo->ponerNodoAnte(aux);
                }
            miArchivo.ignore(1, '\n');
            }
        }
    catch(const invalid_argument& ex) {}

    miArchivo.close();
    }
