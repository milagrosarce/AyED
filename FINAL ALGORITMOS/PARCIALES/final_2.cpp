#include <iostream>

using namespace std;

/*----------------EJERCICIO 1-------------------------------------

desarrolle una funcion que retorne una lista ordenada a partir de la union de 1 cola y 1 vector.
Defina usted las precondiciones y estructuras de los nodos de la manera que considere mas conveniente
y detallar.
*/

struct Nodo{
    int info;
    Nodo *sgte;
};

Nodo *funcion(Nodo *cfte, Nodo *cfin, int vector[], int len){

    int valor;
    Nodo *lista = NULL;

    while(cfte!=NULL){
        valor = suprimir(cfte, cfin);
        insertarOrdenado(lista, valor);
    }

    for(int i=0; i<len; i++){
        insertarOrdenado(lista, vector[i]);
    }

    return lista;
}

/*----------------------EJERCICIO 2-------------------------------

se tiene un vector de los productos de un almacen STOCK, que contiene todos los
productos que se tienen disponibles a la venta, con los siguientes campos:
-id del producto
-tipo P, N
-unidades
ademas se cuenta con una lista ordenada que contiene los ultimos pedidos al almacen que deben ser entregados
a los clientes finales. La lista contiene el ID del producto y las unidades.
se pide actualizar el vector STOCK con la informacion que hay en la lista, SOLO para el campo UNIDADES.

-maximo hay 50 productos.

*/

struct datoVector{
    int id;
    char tipo;
    int unidades;
};

struct datoLista{
    int id;
    int unidades;
};

struct Nodo{
    datoLista info;
    Nodo *sgte;
};

int main(){

    datoVector vector[50];
    Nodo *lista; 

    Nodo *aux=lista;

    while(aux !=NULL){
        for(int i=0;i<50;i++){
            if(aux->info.id == vector[i].id){
                if(vector[i].unidades - aux->info.unidades >= 0){
                    vector[i].unidades = vector[i].unidades - aux->info.unidades;
                }else{
                    vector[i].unidades = 0; 
                }
            }
        }
        aux=aux->sgte;
    }

    return 0;
}

int recursivo (int n){

    if (n == 0) return 1;
    return n + recursivo (n-1);
}

int main(){
    
    int resultado = recursivo(5);
    cout << resultado << endl;
    return 0; 
}
