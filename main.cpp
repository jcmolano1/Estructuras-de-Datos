/*
Pontificia Universidad Javeriana
Facultad de Ingeniería
Carrera de Ingniería de Sistemas
Estructuras de Datos
Docente: Andrea del Pilar Rueda Olarte
Presentado por: José Carlos Molano, Andrés Felipe Otálora y Juan Carlos Suárez
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "interfaz.h"
#include "controlador.h"

using namespace std;


/*
Funcion principal del programa

Inicia un ciclo infinito en el que recibe y tokeniza el input desde consola del usuario
y llama a otras funciones para procesarlo.  
*/

int main() {
    Interfaz* interfaz = new Interfaz(); 
    //Prepara el ciclo infinito y el arreglo para recibir input del usuario
    char linea[100];
    bool correr = true;
    //Primer mensaje explicativo, comando ayuda
    cout<<"En cualquier momento escriba ayuda para desplegar la lista de opciones disponibles"<<endl;
    cout<<"Para recibir ayuda de un comando en especifico, escriba 'ayuda <comando>'"<<endl;

    //Inicia el ciclo infito
    while (correr)
    {
        //Impresión del caracter de línea de comando
        cout << "$ " ; 
        //Captura de los datos ingresados
        cin.getline(linea,100);
        //Tokenización del input ingresado
        char* tokens = strtok(linea, " ");
        char* comando; //Primer argumento recibido
        char* complemento;//Segundo argumento recibido
        comando = tokens;   
        if (tokens != NULL) {             
            complemento = strtok(NULL, " "); 
        } 
        //Se envían los tokens respectivos para realizar las acciones solicitadas por el usuario
        correr = interfaz->interfaz(comando, complemento);
    }
}