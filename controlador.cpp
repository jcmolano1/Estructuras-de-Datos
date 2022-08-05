#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "controlador.h"

Controlador::Controlador(){
    
}; 
Controlador::Controlador(vector<string> derecho, vector<string> reves){
    this->derecho = derecho; 
    this->reves = reves; 
} 
vector<string> Controlador::getDerecho(){
    return this->derecho; 
}
vector<string> Controlador::getReves(){
    return this->reves;
}
void Controlador::setDerecho(vector<string> derecho){
    this->derecho = derecho; 
}
void Controlador::setReves(vector<string> reves){
    this->reves = reves; 
}
bool Controlador::agregarDerecho(string palabra){
    this->derecho.push_back(palabra);
    return true;
}
bool Controlador::agregarReves(string reves){
    this->reves.push_back(reves);
    return true; 
}
/*Función que carga tanto el diccionario al derecho como al revés
*
*string nombre_archivo, es el nombre del archivo que contiene las palabras a cargar
*int tipo, 1 si se desea cargar el diccionario al derecho, 2 para al revés
*
*retorna nulo, pero imprime el resultado de la operación en pantalla
*/
void Controlador::cargarDiccionario(string nombre_archivo, int tipo){//Tipo 1 es al derecho, 2 es al revés
    //Variables necesarias para lectura
    string linea; 
    ifstream archivo(nombre_archivo);
    int i;
    //Variables para el envío 
    bool cumple = true; 
    //Variable para verificar qeu no haya estado inicializado antes
    bool permitido = this->verificarNoRedundancia(nombre_archivo, tipo);

    vector<string> asignar; 

    //Si no está inicializado
    if(permitido){
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
            if(tipo == 1){//Asigna al TAD
                sort(asignar.begin(), asignar.end());//Ordena
                this->derecho = asignar;
                cout<<"El diccionario se ha inicializado correctamente"<<endl;
            }
            else{//Asigna al TAD
                sort(asignar.begin(), asignar.end());//Ordena
                this->reves = asignar;
                cout<<"El diccionario inverso se ha inicializado correctamente"<<endl;
            }
        }
        //Si no se logra abrir el archivo
        else{
            cout<<"El archivo "<<nombre_archivo<<" no existe o no puede ser leido"<<endl;
        }
    }
    //Si ya estaba inicializado
    else{
        if(tipo == 1){
            cout<<"El diccionario ya ha sido inicializado"<<endl;
        }
        else{
            cout<<"El diccionario inverso ya ha sido inicializado"<<endl;
        }
    }
}
/*Función que verifica si una palabra ingresada por el usuario existe y cumple con el set de caracteres permitos y siendo así imprime su puntaje
*
*string palabra, palabra a verificar y cuyo puntaje se desea conocer
*
*retorna nulo, pero imprime el resultado de la operación en pantalla
*/
void Controlador::puntajePalabra(string palabra){
    bool cumple = true, existe = false; 
    int i; 
    unsigned int puntaje; 
    //Se comprueba que no haya caracteres prohibidos
    for (i = 0; i < palabra.length(); i++) {
        if(palabra[i] == '1' || palabra[i] == '2' || palabra[i] == '3' || palabra[i] == '4' || palabra[i] == '5' || palabra[i] == '6' || palabra[i] == '7' || palabra[i] == '8' || palabra[i] == '9'){
            cumple = false;
            break;
        }
        else if(palabra[i] == '.' || palabra[i] == '-' || palabra[i] == ',' || palabra[i] == '\''){
            cumple = false; 
            break;
        }
    }
    //Si no tiene caracteres prohibidos
    if(cumple){
        //Se revisa que exista en palabras al derecho
        vector<string>::iterator it = find(this->derecho.begin(), this->derecho.end(), palabra); 
        if(it != this->derecho.end()){
            int indice = it - this->derecho.begin();
            existe = true;
            puntaje = this->calcularPuntaje(this->derecho[indice]);//Se calcula el puntaje 
        }        
        if(!existe){//Se revisa si existe en palabras al revés
            vector<string>::iterator itr = find(this->reves.begin(), this->reves.end(), palabra);
            if(itr != this->reves.end()){
                int indice = itr - this->reves.begin();
                existe = true;
                puntaje = this->calcularPuntaje(this->reves[indice]);//Se calcula el puntaje
            }   
        }
        if(existe){//Si existe
            cout<<"La palabra tiene un puntaje de "<<puntaje<<endl;
        }
        else{//Si no existe
            cout<<"La palabra no existe en el diccionario."<<endl;
        }
    }
    else{//Si tiene caracteres prohibidos
        cout<<"La palabra contiene simbolos invalidos."<<endl;
    }
}
/*Función que carga tanto el diccionario al derecho como al revés
*
*string palabra, palabra ya validad cuyo puntaje se desea conocer
*
*retorna el valor del puntaje
*/
int Controlador::calcularPuntaje(string palabra){
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
bool Controlador::verificarNoRedundancia(string archivo, int tipo){
    bool existe = false;
    if(tipo == 1){
        if(archivo.compare(this->archivoDerecho) == 0){
            return false;
        }
        else{
            this->archivoDerecho = archivo;
            return true;
        }
    }
    else{
        if(archivo.compare(this->archivoReves) == 0){
            return false;
        }
        else{
            this->archivoReves = archivo;
            return true;
        }
    }
}

