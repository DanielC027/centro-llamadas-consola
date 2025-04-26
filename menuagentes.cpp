
#include "menuagentes.hpp"
using namespace std;
MenuAgentes::MenuAgentes(ListaAgentes* l):listaRef(l) {
    menuPrincipal();
    }

bool MenuAgentes::inicioSesion() {
    string CONTRASENA_USUARIO = "contrasena";   // esa es la contraseña para entrar al sistema
    string NOMBRE_USUARIO  = "usuario";         // es el usuario para entrar al sistema

    int i = 0; // contador para darle solo 5 oportunidades de entrar
    string contrasena  = "";
    string usuario = "";


    do {
        limpeaPantalla();
        cout << endl;
        cout << "$$\\      $$\\ $$$$$$$$\\ $$$$$$$\\  $$$$$$\\  $$$$$$\\        $$\\      $$\\ $$$$$$$$\\ $$$$$$$$\\ $$$$$$$\\   $$$$$$\\ " << endl;
        cout << "$$$\\    $$$ |$$  _____|$$  __$$\\ \\_$$  _|$$  __$$\\       $$$\\    $$$ |$$  _____|\\__$$  __|$$  __$$\\ $$  __$$\\ " << endl;
        cout << "$$$$\\  $$$$ |$$ |      $$ |  $$ |  $$ |  $$ /  $$ |      $$$$\\  $$$$ |$$ |         $$ |   $$ |  $$ |$$ /  $$ | " << endl;
        cout << "$$\\$$\\$$ $$ |$$$$$\\    $$ |  $$ |  $$ |  $$ |  $$ |      $$\\$$\\$$ $$ |$$$$$\\       $$ |   $$$$$$$  |$$ |  $$ | " << endl;
        cout << "$$ \\$$$  $$ |$$  __|   $$ |  $$ |  $$ |  $$ |  $$ |      $$ \\$$$  $$ |$$  __|      $$ |   $$  __$$< $$ |  $$ | " << endl;
        cout << "$$ |\\$  /$$ |$$ |      $$ |  $$ |  $$ |  $$ |  $$ |      $$ |\\$  /$$ |$$ |         $$ |   $$ |  $$ |$$ |  $$ | " << endl;
        cout << "$$ | \\_/ $$ |$$$$$$$$\\ $$$$$$$  |$$$$$$\\  $$$$$$  |      $$ | \\_/ $$ |$$$$$$$$\\    $$ |   $$ |  $$ | $$$$$$  | " << endl;
        cout << "\\__|     \\__|\\________|\\_______/ \\______| \\______/       \\__|     \\__|\\________|   \\__|   \\__|  \\__| \\______/  " << endl << endl;
        //cout << "\t\tCALL CENTER" << endl;
        cout << "     usuario:    ";
        getline(cin,usuario);
        cout << "     contrasena: ";
        getline(cin,contrasena);
        if(contrasena == CONTRASENA_USUARIO and usuario ==  NOMBRE_USUARIO) {
            return true;
            }
        else {
            cout << endl << endl << " Usuario o contrasena invalidas, Intente de nuevo... " << endl << endl;
            enterParaContinuar();
            }
        i++;
        }
    while(i < 5);
    return false;
    }


void MenuAgentes::menuPrincipal() {
    char op;

    if(!inicioSesion()) {
        return;
        }
    enterParaContinuar();
    do {
        limpeaPantalla();
        cout << endl << "\t\tMENU DE AGENTES " << endl << endl;
        cout << "(1) agregar un agente" << endl;
        cout << "(2) mostrar todos los agentes " << endl;
        cout << "(B) filtrar por especialidad" << endl;
        cout << "(3) modificar agente  " << endl;
        cout << "(4) eliminar agente     " << endl;
        cout << "(5) eliminar todos los agentes " << endl;
        cout << "(6) ordenar por nombre" << endl;
        cout << "(7) ordenar por especialidad" << endl;
        cout << "(8) buscar agente           " << endl;
        cout << "(9) escribir en disco " << endl;
        cout << "(A) leer del disco " << endl;
        cout << "(0) salir" << endl;
        cout << " Elija una opcion: " ;
        cin >> op;
        cin.ignore();

        limpeaPantalla();

        switch(op) {
            case '1': // AGREGAR
                agregarAgente();
                break;
            case '2': // MOSTRAR
                mostrarAgentes();
                break;
            case 'B': // LEER DEL DISCO
                mostrarAgentesFiltrados();
                break;
            case '3': // MODIFICAR
                modificarAgente();
                break;
            case '4': // ELIMINAR
                eliminarAgente();
                break;
            case '5': // ELIMINAR TODO
                eliminarListaAgentes();
                break;
            case '6': // ORDEN NOMBRE
                ordenarAgentePorNombre();
                break;
            case '7': // ORDEN ESPECIALIDAD
                ordenarAgentePorEspecialidad();
                break;
            case '8': // BUSCAR AGENTE
                regresar();
                break;
            case '9': // ESCRIBIR EN DISCO
                escribirEnDisco();
                break;
            case 'A': // LEER DEL DISCO
                leerDelDisco();
                break;
            case '0':
                cout << endl << " REGRESANDO... " << endl;
                break;
            default:
                cout << endl << " Opcion invalida, vuelva a intentarlo. " << endl;
                break;
            }

        enterParaContinuar();
        }
    while(op != '0');
    }

void MenuAgentes::agregarAgente() {
    /**Nombre nombre;
        Turno horarioTrabajo;
        string numeroDeEmpleado;
        string numeroDeExtension;
        Hora horasExtrasTrabajadas;
        string especialidad;
        ListaLlamadas listaLlamadas;*/
    char op;

    Nombre nom;             // nombre
    Hora hor,horInic,horFin;// horario de trabajo, horas extras
    Turno turn;             // horario de trabajo
    string miCadena = "";   // numEmpleado, numExtension, especialidad
    Agente agent;           //   El nuevo AGENTE
    AgenteNodo* pos;        // si existe alguien con ese nombre;

    cout << "\t\tAGREGAR AGENTE" << endl;
    cout << "Ingrese los datos del agente."  << endl;
    // -- Pedir el nombre INICIO
    cout << "Nombre: ";
    getline(cin,miCadena);
    transform(miCadena.begin(), miCadena.end(), miCadena.begin(), ::toupper);
    nom.ponNombre(miCadena);

    cout << "Apellido: ";
    getline(cin,miCadena);
    transform(miCadena.begin(), miCadena.end(), miCadena.begin(), ::toupper);
    nom.ponApellido(miCadena);

    agent.ponerNombre(nom);
    // -- Pedir el nombre FIN
    // -- Ver si existe ya alguien con ese nombre INICIO
    pos = listaRef->encontrarAgente(agent);
    if(pos != nullptr) {
        cout << endl << " Ya existe un agente con el mismo nombre, intentelo de nuevo. " << endl;
        cout << " Regresando al menu..." << endl;
        return;
        }
    // -- Ver si existe ya alguien con ese nombre FIN

    //  --- horario de trabajo (TURNO) INICIO
    cout << " Hora de inicio del turno (HH:MM:SS): ";
    getline(cin,miCadena,':');
    horInic.ponerHora(stoi(miCadena));
    getline(cin,miCadena,':');
    horInic.ponerMinutos(stoi(miCadena));
    getline(cin,miCadena);
    horInic.ponerSegundos(stoi(miCadena));
    turn.ponerHoraInicio(horInic);

    cout << " Hora de fin del turno (HH:MM:SS): ";
    getline(cin,miCadena,':');
    horFin.ponerHora(stoi(miCadena));
    getline(cin,miCadena,':');
    horFin.ponerMinutos(stoi(miCadena));
    getline(cin,miCadena);
    horFin.ponerSegundos(stoi(miCadena));
    turn.ponerHoraFinal(horFin);

    agent.ponerHorarioDeTrabajo(turn);
    //  --- horario de trabajo (TURNO) FIN

    // -- numero de empleado INICIO
    cout << " Numero de empleado: ";
    getline(cin,miCadena);
    //cin.ignore();
    agent.ponerNumeroEmpleado(miCadena);
    // -- numero de empleado FIN

    // -- numero de extension INICIO
    cout << " Numero de extension: ";
    getline(cin,miCadena);
    //cin.ignore();
    agent.ponerNumeroExtension(miCadena);
    // -- numero de extension FIN

    // -- horas extras INIICIO
    cout << " Horas extras trabajadas (HH:MM:SS): ";
    getline(cin,miCadena,':');
    hor.ponerHora(stoi(miCadena));
    getline(cin,miCadena,':');
    hor.ponerMinutos(stoi(miCadena));
    getline(cin,miCadena);
    hor.ponerSegundos(stoi(miCadena));

    agent.ponerHorasExtrasTrabajadas(hor);
    // -- horas extras FIN

    // -- especialidad INICIO
    // Servidores, De escritorio, Portátiles, Linux, Impresoras, Redes.
    cout << endl << endl << " ESPECIALIDADES. "<< endl;
    cout << " (1) Servidores" << endl;
    cout << " (2) Escritorio" << endl;
    cout << " (3) Portatiles" << endl;
    cout << " (4) Linux" << endl;
    cout << " (5) Impresoras" << endl;
    cout << " (6) Redes" << endl;
    cout << "Elige la nueva especialidad: ";
    cin>> op;
    if(op == '1') {
        miCadena = "Servidores";
        agent.ponerEspecialidad(miCadena);
        }
    else if(op == '2') {
        miCadena = "Escritorio";
        agent.ponerEspecialidad(miCadena);
        }
    else if(op == '3') {
        miCadena = "Portatiles";
        agent.ponerEspecialidad(miCadena);
        }
    else if(op == '4') {
        miCadena = "Linux";
        agent.ponerEspecialidad(miCadena);
        }
    else if(op == '5') {
        miCadena = "Impresoras";
        agent.ponerEspecialidad(miCadena);
        }
    else if(op == '6') {
        miCadena = "Redes";
        agent.ponerEspecialidad(miCadena);
        }
    else {
        cout << endl <<"Opcion invalida, Quedara como REDES hasta que se modifique el agente." << endl;
        miCadena = "Redes";
        agent.ponerEspecialidad(miCadena);
        }
    // -- especialidad FIN

    // -- lista de llamadas INICIO
    do {
        cout << endl << " Desea agregar llamadas al agente? (S/N): ";
        cin>> op;
        cin.ignore();
        op = toupper(op);
        if(op != 'S' and op != 'N') {
            cout << endl << " opcion invalida, intentelo de nuevo. " << endl;
            }
        }
    while(op != 'S' and op != 'N');
    if(op == 'S') {
        try {
            new MenuLlamadas(&agent.dameListaLlamadas());
            }
        catch (const ListaExcepcion& ex) {
            /// Hacer algo
            throw ListaExcepcion(ex.what());
            }
        }
    // -- lista de llamadas FIN
    try {
        listaRef->insertaAgente(agent);
        }
    catch (const ListaExcepcion& ex) {
        /// Hacer algo
        throw ListaExcepcion(ex.what());
        }
    cout << endl << "Agente agregado exitosamente... " << endl;

    }

void MenuAgentes::eliminarAgente() {
    string miCadena = "";
    Nombre nom;
    Agente agent;
    AgenteNodo* pos;

    cout << "\t\tELIMINAR AGENTE" << endl;
    cout << "Datos del agente a eliminar. " << endl;
    cout << " Nombre: ";
    getline(cin,miCadena);
    transform(miCadena.begin(), miCadena.end(), miCadena.begin(), ::toupper);
    nom.ponNombre(miCadena);

    cout << " Apellido: ";
    getline(cin,miCadena);
    transform(miCadena.begin(), miCadena.end(), miCadena.begin(), ::toupper);
    nom.ponApellido(miCadena);

    agent.ponerNombre(nom);

    try {
        pos = listaRef->encontrarAgente(agent);

        if(pos == nullptr) {
            cout << "No se encontro el agente, intente nuevamente... " << endl;
            return;
            }

        listaRef->eliminaAgente(pos);
        }
    catch(const ListaExcepcion& ex) {
        throw ListaExcepcion(ex.what());
        }
    cout << endl << "Agente eliminado exitosamente... " << endl;
    }

void MenuAgentes::eliminarListaAgentes() {
    char op;
    cout << endl << "\t\tELIMINAR TODOS LOS AGENTES" << endl;
    do {
        cout << endl << "Esta usted seguro de elminar toda la lista? (S/N): ";
        cin >>op;
        cin.ignore();
        op = toupper(op);
        if(op != 'S' and op != 'N') {
            cout << endl << " Opcion invalida, intentelo de nuevo... " << endl;
            }
        }
    while(op != 'S' and op != 'N');

    if(op == 'S') {
        try {
            listaRef->eliminarTodosAgentes();
            }
        catch(const ListaExcepcion& ex) {
            throw ListaExcepcion(ex.what());
            }
        cout << endl << "Lista eliminada con exito..." << endl;
        }
    else {
        cout << endl << "No se eliminaron los agentes, lista intacta... " << endl;
        }
    }

void MenuAgentes::mostrarAgentes() {
    char op;
    cout << "\t\tMOSTRAR AGENTES" << endl << endl;

    do {
        cout << "Desea ver agentes con su lista de llamadas? (S/N): ";
        cin>> op;
        cin.ignore();
        op = toupper(op);
        if(op != 'S' and op != 'N') {
            cout << endl << "   Opcion invalida, Intente de nuevo... " << endl << endl;
            }
        }
    while(op != 'S' and op != 'N');

    if(op == 'S') {
        cout << listaRef->aCadena(true);
        }
    else {
        cout << listaRef->aCadena(false);
        }

    }

void MenuAgentes::mostrarAgentesFiltrados()
{
    char op;
    string miCadena = "";

    cout << "\t\tMOSTRAR AGENTES FILTRADOS POR ESPECIALIDAD" << endl << endl;

    cout << "Por que especialidad desea filtrar?" << endl;

    cout << endl << " ESPECIALIDADES. "<< endl;
    cout << " (1) Servidores" << endl;
    cout << " (2) Escritorio"<< endl;
    cout << " (3) Portatiles"<< endl;
    cout << " (4) Linux"<< endl;
    cout << " (5) Impresoras"<< endl;
    cout << " (6) Redes"<< endl;
    cout << "Elige especialidad: ";
    cin>> op;
    cin.ignore();

    if(op == '1') {
        miCadena = "Servidores";
        //llama a la funcion que filtra agentes
        }
    else if(op == '2') {
        miCadena = "Escritorio";
        //llama a la funcion que filtra agentes
        }
    else if(op == '3') {
        miCadena = "Portatiles";
        //llama a la funcion que filtra agentes
        }
    else if(op == '4') {
        miCadena = "Linux";
        //llama a la funcion que filtra agentes
        }
    else if(op == '5') {
        miCadena = "Impresoras";
        //llama a la funcion que filtra agentes
        }
    else if(op == '6') {
        miCadena = "Redes";
        //llama a la funcion que filtra agentes
        }
    else {
        cout << endl <<"Opcion invalida." << endl;
        return;
        }

    do {
        cout << endl << "Desea ver agentes con su lista de llamadas? (S/N): ";
        cin>> op;
        cin.ignore();
        op = toupper(op);
        if(op != 'S' and op != 'N') {
            cout << endl << "   Opcion invalida, Intente de nuevo... " << endl << endl;
            }
        }
    while(op != 'S' and op != 'N');

    if(op == 'S') {
        //llama a la funcion que filtra agentes
        //cout << listaRef->aCadena(true);
        cout << listaRef->filtrarEspecialidad(true,miCadena);
        }
    else {
        //llama a la funcion que filtra agentes
        //cout << listaRef->aCadena(false);
        cout << listaRef->filtrarEspecialidad(false,miCadena);
        }
}


void MenuAgentes::ordenarAgentePorNombre() {
    cout << "\t\tORDENAR POR NOMBRE" << endl;
    try {
        listaRef->ordenarPorNombre();
        cout << endl << "lista ordenada exitosamente..." << endl;
        }
    catch(const ListaExcepcion& ex) {
        throw ListaExcepcion(ex.what());
        }
    }
//listaRef->ordenarPorNombre();

void MenuAgentes::ordenarAgentePorEspecialidad() {
    cout << "\t\tORDENAR POR ESPECIALIDAD" << endl;
    try {
        listaRef->ordenarPorEspecialidad();
        cout << endl << "lista ordenada exitosamente..." << endl;
        }
    catch(const ListaExcepcion& ex) {
        throw ListaExcepcion(ex.what());
        }
    }

void MenuAgentes::modificarAgente() {
    char op;

    string miCadena = "";
    Agente agent;
    Nombre nom;
    Hora hor,horInic,horFin;
    Turno turn;
    AgenteNodo* pos;

    cout << "\t\tMODIFICAR AGENTE" << endl;

    /// ---> VER SI EXISTE EL AGENTE

    cout << "Nombre y apellido del agente a modificar." << endl;

    cout << " Nombre: ";
    getline(cin,miCadena);
    transform(miCadena.begin(), miCadena.end(), miCadena.begin(), ::toupper);
    nom.ponNombre(miCadena);

    cout << " Apellido: ";
    getline(cin,miCadena);
    transform(miCadena.begin(), miCadena.end(), miCadena.begin(), ::toupper);
    nom.ponApellido(miCadena);

    agent.ponerNombre(nom);

    pos = listaRef->encontrarAgente(agent);
    if(pos == nullptr) {
        cout << endl << " No se encontro el agente, intente de nuevo... " << endl;
        return;
        }
    cout << pos->dameAgentePtr()->aCadena(false);
    /// ---> HASTA AQUI SOLO SE VE SI EXISTE EL AGENTE
    /// ---> SELECCIONA QUE DATO DESEA MODIFICAR Y LO MODIFICAMOS

    cout << endl << " Dato a modificar? " << endl;
    cout << " (1) Nombre                  " << endl;
    cout << " (2) Numero de empleado      " << endl;
    cout << " (3) Numero de extension     " << endl;
    cout << " (4) Horas extras trabajadas " << endl;
    cout << " (5) Especialidad            " << endl;
    cout << " (6) Horario de trabajo      " << endl;
    cout << " (7) Lista de llamadas       " << endl;
    cout << " (8) Nada, regresar.         " << endl;
    cout << "Eliga una opcion: ";
    cin>> op;
    cin.ignore();

    switch(op) {
        case '1': // NOMBRE
            cout << "Nuevo nombre: ";
            getline(cin,miCadena);
            transform(miCadena.begin(), miCadena.end(), miCadena.begin(), ::toupper);
            nom.ponNombre(miCadena);

            cout << "Nuevo apellido: ";
            getline(cin,miCadena);
            transform(miCadena.begin(), miCadena.end(), miCadena.begin(), ::toupper);
            nom.ponApellido(miCadena);

            pos->dameAgentePtr()->ponerNombre(nom);
            break;
        case '2': // NUMERO DE EMPLEADO
            cout << endl << " Nuevo numero de empleado: ";
            getline(cin,miCadena);

            pos->dameAgentePtr()->ponerNumeroEmpleado(miCadena);
            break;
        case '3': // NUMERO DE EXTENSION
            cout << endl << " Nuevo numero de extension: ";
            getline(cin,miCadena);

            pos->dameAgentePtr()->ponerNumeroExtension(miCadena);
            break;
        case '4': // HORAS EXTRAS
            cout << endl << "Ingrese las nuevas horas extras (HH:MM:SS): ";
            getline(cin,miCadena,':');
            hor.ponerHora(stoi(miCadena));
            getline(cin,miCadena,':');
            hor.ponerMinutos(stoi(miCadena));
            getline(cin,miCadena);
            hor.ponerSegundos(stoi(miCadena));

            pos->dameAgentePtr()->ponerHorasExtrasTrabajadas(hor);
            break;
        case '5': // ESPECIALIDAD
            // Servidores, De escritorio, Portátiles, Linux, Impresoras, Redes.
            cout << endl << " ESPECIALIDADES. "<< endl;
            cout << " (1) Servidores" << endl;
            cout << " (2) Escritorio"<< endl;
            cout << " (3) Portatiles"<< endl;
            cout << " (4) Linux"<< endl;
            cout << " (5) Impresoras"<< endl;
            cout << " (6) Redes"<< endl;
            cout << "Elige la nueva especialidad: ";
            cin>> op;
            cin.ignore();

            if(op == '1') {
                miCadena = "Servidores";
                pos->dameAgentePtr()->ponerEspecialidad(miCadena);
                }
            else if(op == '2') {
                miCadena = "Escritorio";
                pos->dameAgentePtr()->ponerEspecialidad(miCadena);
                }
            else if(op == '3') {
                miCadena = "Portatiles";
                pos->dameAgentePtr()->ponerEspecialidad(miCadena);
                }
            else if(op == '4') {
                miCadena = "Linux";
                pos->dameAgentePtr()->ponerEspecialidad(miCadena);
                }
            else if(op == '5') {
                miCadena = "Impresoras";
                pos->dameAgentePtr()->ponerEspecialidad(miCadena);
                }
            else if(op == '6') {
                miCadena = "Redes";
                pos->dameAgentePtr()->ponerEspecialidad(miCadena);
                }
            else {
                cout << endl <<"Opcion invalida." << endl;
                return;
                }
            break;
        case '6': // HORARIO DE TRABAJO
            cout << endl << "Ingrese la nueva hora de inicio de turno (HH:MM:SS): ";
            getline(cin,miCadena,':');
            horInic.ponerHora(stoi(miCadena));
            getline(cin,miCadena,':');
            horInic.ponerMinutos(stoi(miCadena));
            getline(cin,miCadena);
            horInic.ponerSegundos(stoi(miCadena));
            turn.ponerHoraInicio(horInic);// PARA TURNO SE PONE HORA INICIO

            cout << endl << "Ingrese la nueva hora en que termina el turno (HH:MM:SS): ";
            getline(cin,miCadena,':');
            horFin.ponerHora(stoi(miCadena));
            getline(cin,miCadena,':');
            horFin.ponerMinutos(stoi(miCadena));
            getline(cin,miCadena);
            horFin.ponerSegundos(stoi(miCadena));
            turn.ponerHoraFinal(horFin);


            pos->dameAgentePtr()->ponerHorarioDeTrabajo(turn);
            break;
        case '7' : // LISTA LLAMADAS
            new MenuLlamadas(&pos->dameAgentePtr()->dameListaLlamadas());
            break;
        case '8' : // NADA, REGRESANDO
            cout << endl << " Regresando al menu." << endl;
            return;
            break;
        default:
            cout << endl << " Opcion invalida... " << endl;
            cout << endl << " Regresando al menu." << endl;
            return;
            break;
        }
    }

void MenuAgentes::regresar() {
    char op;
    string miCadena = "";
    Agente agent;
    Nombre nom;
    AgenteNodo* pos;

    cout << "\t\tBUSCAR AGENTE" << endl;

    cout << "Nombre y apellido del agente a buscar." << endl;

    cout << " Nombre: ";
    getline(cin,miCadena);
    transform(miCadena.begin(), miCadena.end(), miCadena.begin(), ::toupper);
    nom.ponNombre(miCadena);

    cout << " Apellido: ";
    getline(cin,miCadena);
    transform(miCadena.begin(), miCadena.end(), miCadena.begin(), ::toupper);
    nom.ponApellido(miCadena);

    agent.ponerNombre(nom);

    do {
        cout << "Desea ver al agente con su lista de llamadas? (S/N): ";
        cin>> op;
        cin.ignore();
        op = toupper(op);
        if(op != 'S' and op != 'N') {
            cout << endl << "   Opcion invalida, Intente de nuevo... " << endl << endl;
            }
        }
    while(op != 'S' and op != 'N');

    if(op == 'S') {
        pos = listaRef->encontrarAgente(agent);
        if(pos == nullptr) {
            cout << endl << " Agente no encontrado... " << endl;
            return;
            }
        cout << endl << pos->dameAgente().aCadena(true);
        } // pos->dameAgente().aCadena(op == 'S');
    else {
        pos = listaRef->encontrarAgente(agent);
        if(pos == nullptr) {
            cout << endl << " Agente no encontrado... " << endl;
            return;
            }
        cout << endl << pos->dameAgente().aCadena(false);
        }
    }


void MenuAgentes::escribirEnDisco() {
    cout << "\t\tESCRIBIR EN DISCO" << endl;

    try {
        listaRef->escribirDisco("lista.agentes");
        }
    catch(const ListaExcepcion& ex) {
        throw ListaExcepcion(ex.what());
        }

    cout << endl << "Escrito exitosamente..." << endl;
    }

void MenuAgentes::leerDelDisco() {
    cout << "\t\tLEER DEL DISCO" << endl;

    try {
        listaRef->leerDisco("lista.agentes");
        }
    catch(const ListaExcepcion& ex) {
        throw ListaExcepcion(ex.what());
        }

    cout << endl << "Lectura exitosa..." << endl;
    }

void MenuAgentes::limpeaPantalla() {
    system(LIMPEA_PANTALLA);
    }

void MenuAgentes::enterParaContinuar() {
    cout << endl << endl << " Presiona [ENTER] para continuar... ";
    cin.get();
    }

MenuAgentes::~MenuAgentes() {}
