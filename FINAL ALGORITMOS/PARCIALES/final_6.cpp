#include <iostream>

using namespace std;

int main(){

    return 0;
}

/*--------------------EJERCICIO 1----------------------
Desarrolle una funcion que retorne una lista ordenada a partir de la Union de 1 cola y 1 pila.
*/

struct Nodo{
    int info;
    Nodo *sgte;
};

Nodo *unionaPila(Nodo *cfte, Nodo *cfin, Nodo *pila){

    Nodo *lista = NULL;
    int valor;

    while(cfte !=NULL){ 
        valor = suprimir(cfte, cfin);
        insertarOrdenado(lista, valor);
    }

    while(pila !=NULL){
        valor = pop(pila);
        insertarOrdenado(lista, valor);
    }

    return lista;
}

//------------------------EJERCICIO 2--------------------------------------

/*
Se tiene un vector de Notas de los alumnos de Algoritmos y Estructuras de Datos del 2023,
que contiene los siguientes campos:
-legajo
-nota 1 parcial
-nota 2 parcial 

Ademas, se cuenta con una lista que contiene las ultimas notas de los recuperatorios del 2do parcial, 
cada nodo de la lista contiene:
-Legajo
-Nota Recuperatorio 2 parcial

Se pide: actualizar el vector Notas con la informacion que hay en la lista, considerando que si aprobo(6 o mas)
debe pisar la nota que se encuentra en el vector. Si no aprobo debe mantenerse la original.
Maximo 1500 alumnos
*/

struct datosVector{
    int legajo;
    int nota1;
    int nota2;
};

struct datosLista{
    int legajo;
    int recu_nota2;
};

struct Nodo{
    datosLista info;
    Nodo *sgte;
};

void ActualizarNotas(datosVector notas[], int lenA, Nodo*lista){

    Nodo * aux=lista;

    while(aux !=NULL){ //recorro lista
        for(int i=0;i<lenA; i++){ //recorro el vector
            if(aux->info.legajo == notas[i].legajo){ //cuando encuentro mismo legajo 
                if(aux->info.recu_nota2 >= 6){ //si la nota mayor a 6 listo modifico 
                    notas[i].nota2 = aux->info.recu_nota2;
                }
            }
        }
    aux = aux->sgte;
    }
}

