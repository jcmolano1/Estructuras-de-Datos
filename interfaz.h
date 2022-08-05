/*
Pontificia Universidad Javeriana
Facultad de Ingeniería
Carrera de Ingniería de Sistemas
Estructuras de Datos
Docente: Andrea del Pilar Rueda Olarte
Presentado por: José Carlos Molano, Andrés Felipe Otálora y Juan Carlos Suárez
*/
//Definción de funciones encargadas del manejo de la interfaz de usuario
//Para ver mayor detalle de estas funciones, ver interfaz.cpp
#ifndef __INTERFAZ__H__
#define __INTERFAZ__H__
#include "controlador.h"
#include "controladorArbol.h"

class Interfaz{
    protected:
        Controlador controlador;
        ControladorArbol controladorArbol;
    public:
        Interfaz();
        void print_menu();
        bool interfaz(char* comando, char* complemento);
};
#endif