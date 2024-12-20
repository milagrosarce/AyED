#include <iostream>

using namespace std;

//dado un lote de numeros que ingrese el usuario despues mostrarlo a la inversa

void push(Nodo *&pila, int valor);
int pop(Nodo *&pila); 

struct Nodo{
    int info;
    Nodo *sgte;
};

int main(){

    Nodo *pila= NULL;
    int numero;
    int retorno;

    cout << "Ingrese un numero, 0 para finalizar " << endl;
    cin >> numero; 

    while(numero != 0){

        push(pila,numero);

        cout << "Ingrese un numero, 0 para finalizar" << endl;
        cin >> numero;  
    }

    while(pila != NULL){
        retorno = pop(pila);
        cout << retorno << endl;
    }

    return 0;
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