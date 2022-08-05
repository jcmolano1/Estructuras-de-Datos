#include "arbol.h"
#include <stdio.h>
#include <string.h>

using namespace std;

Arbol::Arbol(){
    this->setRaiz(new Nodo('0'));
    this->inicializado = false;
};
Nodo* Arbol::getRaiz(){
    return this->raiz; 
};
void Arbol::setRaiz(Nodo* nodo){
    this->raiz = nodo;
};
bool Arbol::verificarPreCarga(string archivo){
    bool existe = false; 
    if(archivo.compare(this->archivo_cargado) == 0){
        return false;
    }
    else{
        this->archivo_cargado = archivo; 
        return true;
    }
}
