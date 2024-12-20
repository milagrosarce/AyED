#include <iostream>

using namespace std;


int main(){


    return 0;
}
void insertarOrdenado(Nodo *&lista, int valor);
int suprimir(Nodo *&cfte, Nodo *&cfin);

/*EJERCICIO 1

Desarrolle una funcion que retorne una lista ordenada a partir de la union de 1 cola y 1 pila.
Defina ustedes las precondiciones y estructuras de los nodos de la manera que consdiere mas conveniente y detallar.
*/

Nodo *unionColaPila(Nodo *cfte, Nodo*cfin, Nodo *pila){

    Nodo *lista= NULL;
    int valor;

    while(cfte!=NULL){
        valor = suprimir(cfte, cfin);
        insertarOrdenado(lista, valor);
    }

    while(pila != NULL){
        valor = pop(pila);
        insertarOrdenado(lista, valor);
    }

    return lista;
}

int suprimir(Nodo *&cfte, Nodo *&cfin){

    int ret;
    ret = cfte->info;
    Nodo *aux=cfte;
    cfte=aux->sgte;
    if(cfte==NULL){
        cfin = NULL;
    }
    delete(aux);
    return ret;
}

void insertarOrdenado(Nodo *&lista, int valor){

    //creo el nodo y le pongo valor

    Nodo *nuevo= new Nodo();
    nuevo->info = valor;
    nuevo->sgte= NULL;

    //creamos los punteros
    Nodo *aux=lista;
    Nodo *ant=NULL;

    //caminamos sobre la lista
    while(aux!=NULL && aux->info < valor){
        ant=aux;
        aux=aux->sgte;

    }

    if(ant==NULL){
        lista = nuevo;
        nuevo->sgte=lista;
    }else{
        ant->sgte = nuevo;
        nuevo->sgte = aux;
    }

}

int pop(Nodo *&pila){

    //guardar el valor re retorno 
    int retorno;
    retorno = pila->info;

    Nodo *aux=pila;
    pila = aux->sgte; //pila = pila->sgte; 

    delete(aux);

    return retorno;
}

/*--------------------------EJERCICIO 2-------------------------------

Se tiene un vector de Balance de las cuentas de inversion de un set de clientes, que contiene los siguientes
campos: 
-Numero de Cliente
-Numero de Cuenta
-Saldo 
-Ultimo movimiento 

Ademas, se cuenta con una lista que contiene las ultimas transacciones de intereses generador(1 nodo 1 transaccion)
-Numero de Cuenta
-Monto del interes(positivo o negativo).

Se pide actualizar el vector Balance con la informacion que hay en la lista, considerando 
que debe actualizar el saldo y el valor del ultimo movimiento por cuenta.
Maximo 200 cuentas
*/
struct datoVector{
    int numero_cliente;
    int numero_cuenta;
    int saldo;
    int ultimo_movimiento;
};

struct datoLista{
    int numero_cuenta;
    int monto; 
};

struct Nodo{
    datoLista info;
    Nodo *sgte;
};


int main(){

    datoVector vector[200]; //tengo el vector
    Nodo *lista;  //tengo la lista

    Nodo *aux=lista; //la recorro con un aux mejor para no perder nada
    while(aux!=NULL){ //voy recorriendo la lista
        for(int i=0 ; i<200; i++){ //busco dentro del vector la cuenta
            if(aux->info.numero_cuenta == vector[i].numero_cuenta){ //si coincide
                vector[i].ultimo_movimiento = aux->info.monto;
                vector[i].saldo += aux->info.monto; 
            }
        }
        aux= aux->sgte;
    }
    

    return 0;
}