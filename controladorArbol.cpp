#include "controladorArbol.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

ControladorArbol::ControladorArbol(){
    this->derecho = Arbol();
    this->inverso = Arbol();
};

Arbol ControladorArbol::getDerecho(){
    return this->derecho;
}
Arbol ControladorArbol::getInverso(){
    return this->inverso;
}

void ControladorArbol::cargarArbol(string nombre_archivo, int tipo){
    //Variables necesarias para lectura
    string linea; 
    ifstream archivo(nombre_archivo);
    int i;
    //Variables para el envío 
    bool cumple = true; 
    //Variable para verificar qeu no haya estado inicializado antes
    vector<string> asignar; 

    bool permite_cargar; 

    if(tipo == 1){
        permite_cargar = this->derecho.verificarPreCarga(nombre_archivo);
    }
    else{
        permite_cargar = this->inverso.verificarPreCarga(nombre_archivo);
    }

    //Si se permite la carga
    if(permite_cargar){
        //Si logra abrir el archivo
        if(archivo.is_open()){
            //Mientras el archivo siga abierto
            while(getline(archivo, linea)){
                //Se carga la linea a una variable para comprobar que no haya caracteres prohibidos
                for (i = 0; i < linea.length(); i++) {
                    if(linea[i] == '1' || linea[i] == '2' || linea[i] == '3' || linea[i] == '4' || linea[i] == '5' || linea[i] == '6' || linea[i] == '7' || linea[i] == '8' || linea[i] == '9'){
                        cumple = false;
                        break;
                    }
                    else if(linea[i] == '.' || linea[i] == '-' || linea[i] == ',' || linea[i] == '\'' || linea[i] == ';' || linea[i] == '&' || linea[i] == '/' || linea[i] == '$' || linea[i] == '#' || linea[i] == '(' || linea[i] == ')' || linea[i] == '"'){
                        cumple = false; 
                        break;
                    }
                }
                if(cumple){//Si cumple con no incluir caracteres prohibidos 
                    if(tipo == 1){//Agregar al derecho
                        asignar.push_back(linea);
                    }
                    else{//Agregar al reves
                        reverse(linea.begin(), linea.end());
                        asignar.push_back(linea);
                    }
                }
                else{
                    cumple = true;
                }
            }
            if(tipo == 1){
                Nodo* raiz = new Nodo(0);
                raiz->convertirToArbol(asignar);
                this->derecho.setRaiz(raiz);
                cout<<"El arbol del diccionario se ha inicializado correctamente."<<endl;
            }
            else{
                Nodo* raiz = new Nodo(0);
                raiz->convertirToArbol(asignar);
                this->inverso.setRaiz(raiz);
                cout<<"El arbol del diccionario inverso se ha inicializado correctamente."<<endl;
            }
        }
        //Si no se logra abrir el archivo
        else{
            cout<<"El archivo "<<nombre_archivo<<" no existe o no puede ser leido"<<endl;
        }
    }
    else{
        if(tipo == 1)
            cout<<"El arbol del diccionario ya ha sido inicializado."<<endl;
        else
            cout<<"El arbol del diccionario inverso ya ha sido inicializado"<<endl;
    }
};
int ControladorArbol::calcularPuntaje(string palabra){
    int i;
    unsigned int puntaje = 0;// Variable incialmente en cero
    for (i = 0; i < palabra.length(); i++) {//Por cada letra y su mayúscula se suma el puntaje según el criterio del enunciado
        if(palabra[i] == 'e' || palabra[i] == 'a' || palabra[i] == 'i' || palabra[i] == 'o' || palabra[i] == 'n' || palabra[i] == 'r' || palabra[i] == 't' || palabra[i] == 'l' || palabra[i] == 's' || palabra[i] == 'u' 
        || palabra[i] == 'E' || palabra[i] == 'A' || palabra[i] == 'I' || palabra[i] == 'O' || palabra[i] == 'N' || palabra[i] == 'R' || palabra[i] == 'T' || palabra[i] == 'L' || palabra[i] == 'S' || palabra[i] == 'U'){
            puntaje += 1;
        }
        else if(palabra[i] == 'd' || palabra[i] == 'g'
        || palabra[i] == 'D' || palabra[i] == 'G'){
            puntaje += 2;
        }
        else if(palabra[i] == 'b' || palabra[i] == 'c' || palabra[i] == 'm' || palabra[i] == 'p'
        || palabra[i] == 'B' || palabra[i] == 'C' || palabra[i] == 'M' || palabra[i] == 'P'){
            puntaje += 3;
        }
        else if(palabra[i] == 'f' || palabra[i] == 'h' || palabra[i] == 'v' || palabra[i] == 'w' || palabra[i] == 'y'
        || palabra[i] == 'F' || palabra[i] == 'H' || palabra[i] == 'V' || palabra[i] == 'W' || palabra[i] == 'Y'){
            puntaje += 4;
        }
        else if(palabra[i] == 'k'
        || palabra[i] == 'K'){
            puntaje += 5;
        }
        else if(palabra[i] == 'j' || palabra[i] == 'x'
        || palabra[i] == 'J' || palabra[i] == 'X'){
            puntaje += 8;
        }
        else if(palabra[i] == 'q' || palabra[i] == 'z'
        || palabra[i] == 'Q' || palabra[i] == 'Z'){
            puntaje += 10;
        }
    }
    return puntaje; //Retorna el resultado de la sumatoria
};
void ControladorArbol::busquedaPrefijo(string prefijo){
    queue<string> palabras = this->derecho.getRaiz()->buscar(prefijo);
    if(!palabras.empty()){
        cout<<"Las palabras que inician con este prefijo son:"<<endl<<endl;
        while(!palabras.empty()){
            string palabra = palabras.front();   
            palabras.pop();     
            cout<<palabra<<" - longitud: "<<palabra.length()<<" - puntaje: "<<this->calcularPuntaje(palabra)<<endl;
        }
    }
    else{
        cout<<"Prefijo "<<prefijo<<" no pudo encontrarse en el diccionario"<<endl;
    }
};
void ControladorArbol::busquedaSufijo(string sufijo){
    reverse(sufijo.begin(), sufijo.end());
    queue<string> palabras = this->inverso.getRaiz()->buscar(sufijo);
    if(!palabras.empty()){
        cout<<"Las palabras que terminan con este sufijo son:"<<endl<<endl;
        while(!palabras.empty()){
            string palabra = palabras.front();  
            reverse(palabra.begin(), palabra.end()); 
            palabras.pop();     
            cout<<palabra<<" - longitud: "<<palabra.length()<<" - puntaje: "<<this->calcularPuntaje(palabra)<<endl;
        }
    }
    else{
        reverse(sufijo.begin(), sufijo.end());
        cout<<"Sufijo "<<sufijo<<" no pudo encontrarse en el diccionario"<<endl;
    }
};


