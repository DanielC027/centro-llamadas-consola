#ifndef LISTAEXCEPCION_HPP_INCLUDED
#define LISTAEXCEPCION_HPP_INCLUDED


#include <exception>
#include <cstring>


class ListaExcepcion: std::exception {
    private:
        std::string msg;

    public:

        ListaExcepcion () noexcept;
        ListaExcepcion (const std::string& m):msg(m) {}
        ListaExcepcion (const ListaExcepcion& ex) noexcept: msg(ex.msg) {};
        ListaExcepcion& operator = (const ListaExcepcion& ex) noexcept {
            msg = ex.msg;
            return *this;
            }
        virtual const char* what() const noexcept {
            return msg.c_str();
            }
    };


#endif // LISTAEXCEPCION_HPP_INCLUDED
