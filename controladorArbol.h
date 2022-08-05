#ifndef __CONTROLADORARBOL__H__
#define __CONTROLADORARBOL__H__
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "arbol.h"

using namespace std;

class ControladorArbol{
    private:
        Arbol derecho;
        Arbol inverso; 
    public:
        ControladorArbol();
        void cargarArbol(string, int);
        Arbol getDerecho();
        Arbol getInverso();
        int calcularPuntaje(string);
        void busquedaPrefijo(string);
        void busquedaSufijo(string);

};

#endif