
#include "menullamadas.hpp"


MenuLlamadas::MenuLlamadas(ListaLlamadas* l)
{
    listaLlamadas = l;
    menuPrincipal();
}

void MenuLlamadas::menuPrincipal()
{
    char op;
    do{
        limpeaPantalla();
        cout << endl << "\t\tMENU DE LLAMADAS " << endl << endl;
        cout << "(1) agregar una llamada" << endl;
        cout << "(2) mostrar todas las llamadas" << endl;
        cout << "(3) modificar duracion" << endl;
        cout << "(4) eliminar una llamada" << endl;
        cout << "(5) eliminar todas las llamadas" << endl;
        cout << "(6) salir" << endl;
        cout << " Elija una opcion: " ;
        cin >> op;
        cin.ignore();

        limpeaPantalla();

        switch(op){
            case '1':
                agregarLlamada();
                break;
            case '2':
                muestraLista();
                break;
            case '3':
                modificarDuracion();
                break;
            case '4':
                eliminarLlamada();
                break;
            case '5':
                eliminaTodo();
                break;
            case '6':
                cout << endl << " REGRESANDO... " << endl;
                break;
            default:
                cout << endl << " Opcion invalida, vuelva a intentarlo. " << endl;
                break;
        }

        enterParaContinuar();
    }while(op != '6');
}

void MenuLlamadas::agregarLlamada()
{
    string miStr;

    Nombre nom;
    Cliente client;
    Hora hor;

    Llamada llam;
    LlamadaNodo* pos;

    cout << endl << "\t\tAGREGAR LLAMADA" << endl << endl;
    cout << " Hora de atencion (HH:MM:SS):      ";
    getline(cin,miStr,':');
    hor.ponerHora(stoi(miStr));
    getline(cin,miStr,':');
    hor.ponerMinutos(stoi(miStr));
    getline(cin,miStr);
    hor.ponerSegundos(stoi(miStr));
    llam.ponerHoraAtencion(hor);
    //cout << endl << hor.aCadena()<< endl;
    pos = listaLlamadas->encontrarLlamada(llam);
    if( pos != nullptr){
        cout << endl << " La hora de atencion existe en otra llamada. " << endl;
        cout << " Regresando al menu... " << endl;
        return;
    }


    cout << " Duracion llamada (HH:MM:SS):      ";
    getline(cin,miStr,':');
    hor.ponerHora(stoi(miStr));
    getline(cin,miStr,':');
    hor.ponerMinutos(stoi(miStr));
    getline(cin,miStr);
    hor.ponerSegundos(stoi(miStr));

    llam.ponerDuracionLlamada(hor);
    //cout << endl << hor.aCadena()<< endl;
    // ---------
    cout << " Nombre cliente:                   ";
    getline(cin,miStr);
    transform(miStr.begin(), miStr.end(), miStr.begin(), ::toupper);
    nom.ponNombre(miStr);
    cout << " Apellido cliente:                 ";
    getline(cin,miStr);
    transform(miStr.begin(), miStr.end(), miStr.begin(), ::toupper);
    nom.ponApellido(miStr);

    client.ponerNombre(nom);

    cout << " Numero de cuenta:                 ";
    getline(cin,miStr);
    client.ponerNumeroCuenta(miStr);

    cout << " Numero de telefono:               ";
    getline(cin,miStr);
    client.ponerNumeroTelefono(miStr);

    llam.ponerCliente(client);
    // Cliente listo


    // Llamada lista
    try{
        listaLlamadas->insertaOrdenado(llam);
    }catch (const ListaExcepcion& ex) {
        cout << endl << "Hubo un error..." << endl;
        cout << "el error reportado es: " << ex.what() << endl;
        cout << "si esto sucede a menudo, informe a sistemas" << endl;
        return;
    }
    cout << endl << " Llamada agregada exitosamente..." << endl;
}

void MenuLlamadas::modificarDuracion()
{
    Llamada miLlamada;
    Hora hor;
    Hora nvaDura;
    string miStr;
    LlamadaNodo* pos;

    cout << endl << "\t\tMODIFICAR DURACION LLAMADA" << endl << endl;

    cout << "Hora de atencion de llamada a modificar(HH:MM:SS): ";
    getline(cin,miStr,':');
    hor.ponerHora(stoi(miStr));
    getline(cin,miStr,':');
    hor.ponerMinutos(stoi(miStr));
    getline(cin,miStr);
    hor.ponerSegundos(stoi(miStr));

    miLlamada.ponerHoraAtencion(hor);

    pos = listaLlamadas->encontrarLlamada(miLlamada);

    if(pos == nullptr){
        cout << endl << "Llamada no existente intente de nuevo, regresando..." << endl;
        return;
    }
    cout << endl << endl << pos->dameLlamada().aCadena() << endl << endl;
    cout << "Ingresa la nueva duracion (HH:MM:SS): ";
    getline(cin,miStr,':');
    nvaDura.ponerHora(stoi(miStr));
    getline(cin,miStr,':');
    nvaDura.ponerMinutos(stoi(miStr));
    getline(cin,miStr);
    nvaDura.ponerSegundos(stoi(miStr));

    // manda a modificar
    listaLlamadas->modificarDuracion(miLlamada,nvaDura);
    // muestra si se pudo o no

}


void MenuLlamadas::eliminarLlamada()
{
    Llamada miLlamada;
    Hora hor;
    string miStr;
    LlamadaNodo* pos;

    char op;

    cout << endl << "\t\tELIMINAR LLAMADA" << endl << endl;

    cout << "Hora de atencion (HH:MM:SS): ";
    getline(cin,miStr,':');
    hor.ponerHora(stoi(miStr));
    getline(cin,miStr,':');
    hor.ponerMinutos(stoi(miStr));
    getline(cin,miStr);
    hor.ponerSegundos(stoi(miStr));

    miLlamada.ponerHoraAtencion(hor);

    pos = listaLlamadas->encontrarLlamada(miLlamada);

    if(pos == nullptr){ /// No esta la llamada en la lista
        cout << endl << " Error!!, esa hora no existe en la lista." << endl;
        enterParaContinuar();

        return;
    }

    cout << endl << "Llamada localizada..." << endl << endl;

    cout << listaLlamadas->recuperar(pos).aCadena() << endl << endl;
    do{
        cout << "Esta seguro de eliminar esa llamada? (S/N): ";
        cin >> op;
        cin.ignore();
        op = toupper(op);

    }while(op != 'N' and op != 'S');

    if(op == 'S'){
        listaLlamadas->eliminaLlamada(pos);

        cout << endl << "Llamada eliminada!!" << endl;
    }
    else{
        cout << endl << "La llamada no se elimino" << endl;
    }
}

void MenuLlamadas::muestraLista()
{
    cout << endl << "\t\tLISTADO DE LLAMADAS " << endl << endl;
    cout << "\t NOMBRE                          APELLIDO                        NUM. CUENTA     TELEFONO     DURACION   HORA ATENCION" << endl << endl;
    cout << listaLlamadas->aCadena() << endl;

}

void MenuLlamadas::eliminaTodo()
{

    char op;
    do{
        cout << endl << "\t\tELIMINAR TODO" << endl;
        cout << "Esta muy seguro de eliminar toda la lista? (S/N): ";
        cin >> op;
        cin.ignore();

        op = toupper(op);
    }while(op != 'N' and op != 'S');

    if(op == 'S'){
        listaLlamadas->eliminarTodasLlamadas();

        cout << endl << " La lista se ha limpiado por completo. " ;

    }
    else{
        cout << endl << " La lista se mantiene como estaba. ";
    }

    cout << endl << endl;
}

void MenuLlamadas::enterParaContinuar()
{
    cout << endl << " Presiona [ENTER] para continuar... " ;
    cin.get();
}

void MenuLlamadas::limpeaPantalla()
{
    system(LIMPEA_PANTALLA);
}


MenuLlamadas::~MenuLlamadas()
{

}
