
#include "hora.hpp"


bool Hora::esValida(const int& h,const int& m,const int& s) {
    return h >= 0 and h <= 23 and m >= 0 and m <=59 and s >= 0 and s <= 59;
    }

int Hora::aEntero() const {
    return ((hora * 10000)+(minutos * 100)+(segundos));
    }

Hora::Hora() {
    chrono::system_clock::time_point today(chrono::system_clock::now());
    time_t tt;
    tt = chrono::system_clock::to_time_t (today);
    struct tm* timeinfo;
    timeinfo = localtime(&tt);

    hora = timeinfo->tm_hour;
    minutos = timeinfo->tm_min;
    segundos = timeinfo->tm_sec;
    }

Hora::Hora(const Hora& h):hora(h.hora),minutos(h.minutos),segundos(h.segundos) {}

Hora::Hora(const int& h, const int& m, const int& s):Hora() {
    if(esValida(h,m,s)) {
        hora = h;
        minutos = m;
        segundos = s;
        }
    }

void Hora::ponerHora(const int& h) {
    if(esValida(h,minutos,segundos)) {
        hora = h;
        }
    }

void Hora::ponerMinutos(const int& m) {
    if(esValida(hora,m,segundos)) {
        minutos = m;
        }
    }

void Hora::ponerSegundos(const int& s) {
    if(esValida(hora,minutos,s)) {
        segundos = s;
        }
    }

string Hora::aCadena() const {
    char myStr[5];
    // 0 para que salga el mismo, 2 para que salga con 2 digitos y i para que salga el numero
    sprintf(myStr,"%02i:%02i:%02i", hora, minutos, segundos);

    return myStr;
    }

int Hora::dameHora() const {
    return hora;
    }

int Hora::dameMinutos() const {
    return minutos;
    }

int Hora::dameSegundos() const {
    return segundos;
    }

Hora& Hora::operator = (const Hora& h) {
    hora = h.dameHora();
    minutos = h.dameMinutos();
    segundos = h.dameSegundos();

    return *this;
    }

bool Hora::operator == (const Hora& h) {
    return aEntero() == h.aEntero();
    }

bool Hora::operator < (const Hora& h) {
    return aEntero() < h.aEntero();
    }


bool Hora::operator != (const Hora& h) {
    return !(*this == h);
    }

bool Hora::operator <= (const Hora& h) {
    return *this == h or *this < h;
    }

bool Hora::operator > (const Hora& h) {
    return !(*this <= h);
    }
bool Hora::operator>=(const Hora& h) {
    return *this > h or *this == h;
    }

istream& operator >> (std::istream& is, Hora& h) {
    string miStr;
    getline(is, miStr, ':');
    h.hora = stoi(miStr);
    getline(is, miStr, ':');
    h.minutos = stoi(miStr);
    getline(is, miStr);
    h.segundos = stoi(miStr);

    return is;
    }

ostream& operator << (std::ostream& os, const Hora& h) {
    char miStr[9];

    sprintf(miStr,"%02i:%02i:%02i",h.hora,h.minutos,h.segundos);


    string str(miStr);
    os << miStr;

    return os;
    }

Hora::~Hora() {

    }
