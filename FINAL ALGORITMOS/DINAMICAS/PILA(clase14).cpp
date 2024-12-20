#include <iostream>

//-------------------------PILA----------------------------
using namespace std;

void push(Nodo *&pila, datos valores);
datos pop(Nodo *&pila);

struct datos{
    int legajo;
    int nota;
};

struct Nodo{
    datos info;
    Nodo *sgte;
};

int main(){

    Nodo * pila = NULL; 
    datos updates;
    datos sacamosA;
    datos rdo;
    datos carga;

    push(pila, updates); 
    sacamosA = pop(pila);

    while(pila != NULL){ // mientras la pila NO este vacia
        rdo = pop(pila); //saco un elemento y lo muestro en pantalla
        cout << rdo.legajo << endl; 
        cout << rdo.nota << endl;
    }

    while(carga.legajo != 0){ //si tendria que usar algo como que decirle al usuario que me ingrese datos e ir agregandolos a la pila 
        push (pila, carga);
    }
    
    return 0;
}

void push(Nodo *&pila, datos valores){

    Nodo *nuevo = new Nodo(); //creamos digamos el bloquecito
    nuevo->info = valores; //cargamos el bloquecito
    nuevo->sgte = pila; //hacemos que apunte al que antes tenia pila 
    pila = nuevo; //y ahora hacmemos que el puntero "principal" apunte a este que recien lelgo 
}

datos pop(Nodo *&pila){

    //guardar el valor re retorno 
    datos retorno;
    retorno=pila->info;

    Nodo *aux=pila;
    pila = aux->sgte; //pila = pila->sgte; 

    delete(aux);

    return retorno;
}
