/*
Pontificia Universidad Javeriana
Facultad de Ingeniería
Carrera de Ingniería de Sistemas
Estructuras de Datos
Docente: Andrea del Pilar Rueda Olarte
Presentado por: José Carlos Molano, Andrés Felipe Otálora y Juan Carlos Suárez
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
#include "interfaz.h"
#include <algorithm>
#include "arbol.h"

using namespace std;

Interfaz::Interfaz(){
    Controlador controlador;
    this->controlador = controlador;
}
//Función que imprime todos los comandos disponibles en el sistema
void Interfaz::print_menu(){
    //Imprime las posibles opciones del menú
    cout<<"Comandos del sistema"<<endl;
    cout<<"inicializar <nombre_archivo>"<<endl;
    cout<<"iniciar_inverso <nombre_archivo>"<<endl;
    cout<<"puntaje <palabra>"<<endl;
    cout<<"iniciar_arbol <nombre_archivo>"<<endl;
    cout<<"iniciar_arbol_inverso <nombre_archivo>"<<endl;
    cout<<"palabras_por_prefijo <prefijo>"<<endl;
    cout<<"palabras_por_sufijo <sufijo>"<<endl;
    cout<<"grafo_de_palabras"<<endl;
    cout<<"posibles_palabras <letras>"<<endl;
}
/*
*Función que analiza el input enviado por el usuario y realiza las acciones solicitadas
*
*char* comando es el comando principal, el primer argumento enviado por el usuaior
*char* complemento, son los valores adicionales que requieren algunos comandos, el segundo argumento enviado por consola
*
*retorna true para que el programa siga corriendo, para salir y detener la ejecución retorna false
*/
bool Interfaz::interfaz(char* comando, char* complemento){
    //Impresión del mensaje de ayuda
    if(strcmp(comando,"ayuda")==0)
    {          
        //En caso de que envie el comando ayuda por si solo
        if(complemento == NULL)
            print_menu();
        //Si desea ayuda sobre un comando especifico
        else{
            if(strcmp(complemento, "inicializar") == 0){
                cout<<"El comando tiene la forma 'inicializar <nombre_archivo>'"<<endl;
                cout<<"Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras aceptadas en el idioma ingles (idioma original del juego)"<<endl<<endl;
            }
            else if(strcmp(complemento, "iniciar_inverso") == 0){
                cout<<"El comando tiene la forma 'iniciar_inverso <nombre_archivo>'"<<endl;
                cout<<"Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras aceptadas en el idioma ingles (idioma original del juego). A diferencia del comando inicializar, este comando almacena las palabras en sentido inverso (leídas de derecha a izquierda), teniendo en cuenta que sea facil recuperarlas posteriormente"<<endl<<endl;
            }
            else if(strcmp(complemento, "puntaje") == 0){
                cout<<"El comando tiene la forma 'puntaje <palabra>'"<<endl;
                cout<<"El comando permite conocer la puntuacion que puede obtenerse con una palabra dada, de acuerdo a la tabla de puntuacion de cada letra presentada anteriormente. Sin embargo, el comando debe verificar que la palabra sea valida"<<endl<<endl;
            }
            else if(strcmp(complemento, "iniciar_arbol") == 0){
                cout<<"El comando tiene la forma 'iniciar_arbol <nombre_archivo>'"<<endl;
                cout<<"Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras aceptadas en el idioma ingles (idioma original del juego). Este comando almacena las palabras en uno o mas arboles de letras (como se considere conveniente)."<<endl<<endl;
            }
            else if(strcmp(complemento, "iniciar_arbol_inverso") == 0){
                cout<<"El comando tiene la forma 'iniciar_arbol_inverso <nombre_archivo>'"<<endl;
                cout<<"Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras aceptadas en el idioma ingles. Este comando almacena las palabras en uno o mas arboles de letras, pero en sentido inverso (leidas de derecha a izquierda)"<<endl<<endl;
            }
            else if(strcmp(complemento, "palabras_por_prefijo") == 0){
                cout<<"El comando tiene la forma 'palabras_por_prefijo <prefijo>'"<<endl;
                cout<<"Dado un prefijo de pocas letras, el comando recorre el arbol de letras para ubicar todas las palabras posibles a construir a partir de ese prefijo. Se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada una y la puntuación que cada una puede obtener."<<endl<<endl;
            }
            else if(strcmp(complemento, "palabras_por_sufijo") == 0){
                cout<<"El comando tiene la forma 'palabras_por_sufijo <sufijo>'"<<endl;
                 cout<<"Dado un sufijo de pocas letras, el comando recorre el arbol de letras para ubicar todas las palabras posibles a construir que terminan con ese sufijo. Se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada una y la puntuacion que cada una puede obtener."<<endl<<endl;
            }
            else if(strcmp(complemento, "grafo_de_palabras") == 0){
                cout<<"El comando tiene la forma 'grafo_de_salir'"<<endl;
                cout<<"Con las palabras ya almacenadas en el diccionario, el comando construye un grafo de palabras, en donde cada palabra se conecta a las demas si y solo si difieren en un unica letra"<<endl<<endl;
            }
            else if(strcmp(complemento, "posibles_palabras") == 0){
                cout<<"El comando tiene la forma 'posibles_palabras <letras>'"<<endl;
                cout<<"Dadas ciertas letras en una cadena de caracteres (sin importar su orden), el comando debe presentar en pantalla todas las posibles palabras validas a construir, indicando la longitud de cada una y la puntuacion que se puede obtener con cada una."<<endl<<endl;
            }
            else if(strcmp(complemento, "salir") == 0){
                cout<<"El comando tiene la forma 'salir'"<<endl;
                cout<<"Termina la ejecucion del sistema"<<endl<<endl;
            }
            else{
                cout<<"Comando invalido"<<endl;
                print_menu(); 
            }               
        }
    }
    //Permite salir del programa 
    else if(strcmp(comando,"salir")==0)
    {
        cout<<"Fin del programa."<<endl;
        return false;
    }
    //Comando empleado para inicializar el diccionario
    else if(strcmp(comando,"inicializar")==0)
    {
        if(complemento != NULL){
            cout<<"Comando correcto para inicializar diccionario"<<endl;
            this->controlador.cargarDiccionario(complemento, 1);
        }
        else{
            cout<<"Numero incorrecto de parametros"<<endl;
            cout<<"El comando correcto es 'inicializar <nombre_archivo>'"<<endl;
        }         
    }
    //Inicializa el diccionario en forma inversa
    else if(strcmp(comando,"iniciar_inverso")==0)
    {
        if(complemento != NULL){
            cout<<"Comando correcto para inicializar diccionario inverso"<<endl;
            this->controlador.cargarDiccionario(complemento, 2);
        }
        else{
            cout<<"Numero incorrecto de parametros"<<endl;
            cout<<"El comando correcto es 'iniciar_inverso <nombre_archivo>'"<<endl;
        }         
    }
    //Permite conocer el puntaje que otorga una palabra dada
    else if(strcmp(comando,"puntaje")==0)
    {
        if(complemento != NULL){
            cout<<"Comando correcto para conocer el puntaje de una palabra dada"<<endl;
            this->controlador.puntajePalabra(complemento);

        }
        else{
            cout<<"Numero incorrecto de parametros"<<endl;
            cout<<"El comando correcto es 'puntaje <palabra>'"<<endl;
        }   

    }
    //Inicializa el árbol del diccionario
    else if(strcmp(comando,"iniciar_arbol")==0)
    {
        if(complemento != NULL){
            cout<<"Comando correcto para iniciar el arbol"<<endl;
            this->controladorArbol.cargarArbol(complemento, 1);
        }
        else{
            cout<<"Numero incorrecto de parametros"<<endl;
            cout<<"El comando correcto es 'iniciar_arbol <nombre_archivo>'"<<endl;
        }   

    }
    //Inicializa el árbol inverso del diccionario
    else if(strcmp(comando,"iniciar_arbol_inverso")==0)
    {
        if(complemento != NULL){
            cout<<"Comando correcto para iniciar el arbol inverso"<<endl;
            this->controladorArbol.cargarArbol(complemento, 2);
        }
        else{
            cout<<"Numero incorrecto de parametros"<<endl;
            cout<<"El comando correcto es 'iniciar_arbol_inverso <nombre_archivo>'"<<endl;
        }   
    }
    //Permite encontrar palabras con un determinado prefijo
    else if(strcmp(comando,"palabras_por_prefijo")==0)
    {
        if(complemento != NULL){
            cout<<"Comando correcto para buscar palabras con cierto prefijo"<<endl;
            this->controladorArbol.busquedaPrefijo(complemento);
        }
        else{
            cout<<"Numero incorrecto de parametros"<<endl;
            cout<<"El comando correcto es 'palabras_por_prefijo <prefijo>'"<<endl;
        }   
    }
    //Permite encontrar palabras con un determinado sufijo
    else if(strcmp(comando,"palabras_por_sufijo")==0)
    {
        if(complemento != NULL){
            cout<<"Comando correcto para buscar palabras con cierto sufijo"<<endl;
            this->controladorArbol.busquedaSufijo(complemento);
        }
        else{
            cout<<"Numero incorrecto de parametros"<<endl;
            cout<<"El comando correcto es 'palabras_por_sufijo <sufijo>'"<<endl;
        }   
    }
    else if(strcmp(comando,"grafo_de_palabras")==0)
    {
        cout<<"Comando correcto para el grafo de palabras"<<endl;

    }
    //Permite determinar qué palabras se puede armar con cierta combinación
    else if(strcmp(comando,"posibles_palabras")==0)
    {
        if(complemento != NULL){
            cout<<"Comando correcto para buscar las palabras que se pueden formar con ciertas letras"<<endl;
        }
        else{
            cout<<"Numero incorrecto de parametros"<<endl;
            cout<<"El comando correcto es 'posibles_palabras <letras>'"<<endl;
        }   

    }
    //Manejo de comandos no reconocidos
    else
    {
        cout<<"Comando no reconocido"<<endl;
        cout<<"Los comandos validos son las siguientes: "<<endl;
        print_menu(); 
    }
    cout<<endl;
    return true; 
}
