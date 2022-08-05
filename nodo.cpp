#include "nodo.h"
#include <iostream>
#include <queue>

Nodo::Nodo(){
    this->numHijos = 0;
    this->esPalabra = false;
};
Nodo::Nodo(char letra){
    this->numHijos = 0;
    this->letra = letra;
    this->esPalabra = false;
};
char Nodo::getLetra(){
    return this->letra;
};
Nodo** Nodo::getHijos(){
    return this->hijos;
};
int Nodo::getNumHijos(){
    return this->numHijos;
};
void Nodo::setLetra(char letra){
    this->letra = letra;
};
void Nodo::setNumHijos(int num){
    this->numHijos = num;
};
Nodo* Nodo::convertirToArbol(vector<string> palabras){//Se ejecuta siempre en la raiz en primera interacion
    string palabra;
    Nodo* actual = this;
    queue<Nodo*> hijos;
    bool existente = false;
    for(int i=0; i<palabras.size(); i++){
        actual = this;
        palabra = palabras[i];
        for(char& cara:palabra){
            for(int j=0; j<actual->getNumHijos(); j++){
                hijos.push(actual->getHijos()[j]);
            }
            while (!hijos.empty()){
                if(cara == hijos.front()->getLetra()){
                    //Si ya hay un hijo con la letra
                    existente = true;
                    actual = hijos.front();
                    while(!hijos.empty()){
                        hijos.pop();
                    }
                }
                if(!existente)
                    hijos.pop();
            }
            if(!existente){
                //Si ninguno de los hijos del nodo era la letra requerida
                Nodo* nuevo = new Nodo(cara);
                actual->agregarHijo(nuevo);
                actual = nuevo;
            }
            else{
                existente =false;
            }
        }
        actual->siEsPalabra();
    }
    return this;
};
void Nodo::agregarHijo(Nodo* hijo){
    this->hijos[this->numHijos] = hijo;
    this->numHijos = (this->numHijos)+1;
};
queue<string> Nodo::buscar(string prefijo){
    queue<string> retornar;
    queue<Nodo*> hijos;
    Nodo* actual = this;
    bool encontrado = false;

    queue<string> armador;
    armador.push(prefijo);
    
    while(!armador.empty()){
        prefijo = armador.front();
        armador.pop();
        actual = this;

        for(char& cara:prefijo){
            for(int j=0; j<actual->getNumHijos(); j++){
                hijos.push(actual->getHijos()[j]);
            }
            while (!hijos.empty()){
                if(cara == hijos.front()->getLetra()){
                    //Si ya hay un hijo con la letra
                    encontrado = true;
                    actual = hijos.front();
                    while(!hijos.empty()){
                        hijos.pop();
                    }
                }
                if(!encontrado)
                    hijos.pop();
            }
            if(!encontrado){
                //Si ninguno de los hijos del nodo era la letra requerida
                return retornar;
            }
            else{
                encontrado = false;
            }
        }

        if(actual->getNumHijos() > 0){
            for(int j=0; j<actual->getNumHijos(); j++){
                hijos.push(actual->getHijos()[j]);
            }
            while(!hijos.empty()){
                string acumulador = prefijo;
                acumulador += hijos.front()->getLetra();
                hijos.pop();
                armador.push(acumulador);
            }
        }
        if(actual->esPalabra){
            retornar.push(prefijo);
        }
    }
    return retornar;
};
void Nodo::siEsPalabra(){
    this->esPalabra = true;
}