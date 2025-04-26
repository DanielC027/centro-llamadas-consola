/*

 */

#ifndef _menucallcenter_hpp_
#define _menucallcenter_hpp_

class MenuCallCenter {
private:
    void agregarAgente();
    void eliminarAgente();
    void eliminarListaAgentes();
    void mostrarAgentes();
    void mostrarAgentePorEspecialidad();
    void mostrarAgentePorNombre();
    void ordenarAgentePorNombre();
    void ordenarAgentePorEspecialidad();
    void modificarAgente();
    void agregarLlamada();
    void eliminarLlamada();
    void eliminarListaLlamadas();
    void modificarLlamada();
    void regresar();
  public:
    MenuCallCenter(const ListaAgentes&);
    ~MenuCallCenter();


};

#endif /* _MenuCallCenter_hh_ */

