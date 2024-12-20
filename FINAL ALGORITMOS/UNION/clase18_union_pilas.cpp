#include <iostream>

using namespace std;

//dada DOS PILAS DE ENTEROS A Y B
//generar la UNION de ambas en pila C

void unionPila(Nodo *pilaA, Nodo *pilaB, Nodo *&pilaC); 
void push(Nodo *&pila, int valores); 
int pop(Nodo *&pila); 

struct Nodo{
    int info;
    Nodo *sgte;
};

int main(){

    return 0;
}

void unionPila(Nodo *&pilaA, Nodo *&pilaB, Nodo *&pilaC){

    int valor;

    while(pilaA!=NULL){
        valor = pop(pilaA);
        push(pilaC, valor);
    }

    while(pilaB != NULL){
        valor = pop(pilaB);
        push(pilaC, valor);
    }
}

void push(Nodo *&pila, int valores){

    Nodo *nuevo = new Nodo(); //creamos digamos el bloquecito
    nuevo->info = valores; //cargamos el bloquecito
    nuevo->sgte = pila; //hacemos que apunte al que antes tenia pila 
    pila = nuevo; //y ahora hacmemos que el puntero "principal" apunte a este que recien lelgo 
}

int pop(Nodo *&pila){

    //guardar el valor re retorno 
    int retorno;
    retorno=pila->info;

    Nodo *aux=pila;
    pila = aux->sgte; //pila = pila->sgte; 

    delete(aux);

    return retorno;
}