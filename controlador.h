#ifndef __CONTROLADOR__H__
#define __CONTROLADOR__H__
#include <vector>

using namespace std; 

class Controlador{
    protected: 
        //Datos
        vector<string> derecho; 
        vector<string> reves;
        string archivoDerecho;
        string archivoReves;
    public: 
        //Funciones
        Controlador(); 
        Controlador(vector<string> derecho, vector<string> reves); 
        vector<string> getDerecho(); 
        vector<string> getReves();
        void setDerecho(vector<string> derecho);
        void setReves(vector<string> reves);
        bool agregarDerecho(string palabra);
        bool agregarReves(string reves); 
        void cargarDiccionario(string nombre_archivo, int tipo);
        void puntajePalabra(string palabra);
        int calcularPuntaje(string palabra);
        bool verificarNoRedundancia(string, int);
};

#endif