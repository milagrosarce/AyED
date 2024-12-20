#include <iostream>

using namespace std;

/*
Desarrolle una funcion que retorne una lista ordenada a partir de la interseccion de 1 pila y 1 lista.
*/

struct Nodo{
    int info;
    Nodo *sgte;
};

Nodo *interseccionPilaLista(Nodo *pila, Nodo *lista){


    Nodo * nuevaLista = NULL;

    Nodo * aux = lista;
    while(pila !=NULL){ //pila 

        int valor = pop(pila); //saco un valor 
        
        aux = lista;
        while(aux!=NULL){ //busco en la lista si hay un valor que coincida si es asi interseccion a nueva lista
            if(aux->info == valor){
                insertarOrdenado(nuevaLista, valor);
                break; //para que no siga buscando digamos pero bueno detallito diria
            }
            aux = aux->sgte;
        }
    }
    return nuevaLista;
}

/*--------------------------------EJERCICIO 2----------------------------------------------

Se tiene un vector de Saldos de las cuentas bancarias de una empresa, que contiene los siguientes campos
-Numero de cuenta
-Cantidad de transacciones
-Saldo
Ademas se cuenta con una lista que contiene las ultimas transacciones, cada node de la lista contiene:
-numero de cuenta
-monto 
Se pide actualizar el vector Saldos con la informacion que hay en la lista, considerando que debe actualizar
el saldo y actualizar la cantidad de transacciones por cuenta. Maximo hay 150 cuentas.
*/

struct datosVector{
    int numero_cuenta;
    int cant_transacciones;
    int saldo;
};

struct datosLista{
    int numero_cuenta;
    int monto;
};

struct Nodo{
    datosLista info;
    Nodo *sgte;
};

int main(){

    datosVector saldos[150];
    Nodo *lista; //damos por hecho que ya estarian inicializados

    Nodo *aux=lista; //por las dudas un aux, por si llega  a pasar algo durante la ejecucion del programa y pierdo la lista

    while(aux != NULL){ //la recorro 

        for(int i=0;i<150;i++){
            if(aux->info.numero_cuenta == saldos[i].numero_cuenta){
                saldos[i].cant_transacciones += 1;
                saldos[i].saldo = saldos[i].saldo - aux->info.monto;
            }
        }
        aux = aux->sgte;
    }

    return 0;
}
