#ifndef __NODO__H__
#define __NODO__H__
#include <vector>
#include <queue>
#include <string>

using namespace std;
class Nodo{
    protected:
        char letra;
        Nodo* hijos[80];//26 mayusculas y 26 minusculas + margen de seguridad
        int numHijos; 
        bool esPalabra;
    public: 
        Nodo();
        Nodo(char);
        char getLetra();
        Nodo** getHijos();
        int getNumHijos();
        void setLetra(char);
        void setNumHijos(int);
        Nodo* convertirToArbol(vector<string>);
        void agregarHijo(Nodo*);
        queue<string> buscar(string);
        void siEsPalabra();
};
#endif