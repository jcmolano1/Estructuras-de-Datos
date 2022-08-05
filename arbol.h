#ifndef __ARBOL__H__
#define __ARBOL__H__
#include "nodo.h"
#include <vector>
class Arbol{
    protected:
        Nodo* raiz;
        bool inicializado; 
        string archivo_cargado;
    public:
        Arbol();
        Nodo* getRaiz();
        void setRaiz(Nodo*);
        bool verificarPreCarga(string);
};
#endif