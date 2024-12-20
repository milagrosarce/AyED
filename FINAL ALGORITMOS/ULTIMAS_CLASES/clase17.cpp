#include <iostream>

using namespace std;

/*
Dado un vector de registros de 20 posiciones que contiene: id_prod, Unidades en stock.
Ademas se cuenta con una lista de los nuevos pedidos que ingresaron (id_prod y unidades que entraron). 
Se pide actualizar el vector con los nuevos ingresos. 
*/

struct dato{
    int id_prod;
    int unidades;
};

struct Nodo{
    dato info;  
    Nodo *sgte;
};

int main(){

    dato vector[20];

    Nodo *lista; 
    Nodo *aux=lista;

    while(aux!=NULL){

        bool encontrado = false; //para cortar sino quedaria en loop 

        for(int i=0 ; i < 20; i++){ 

            if(aux->info.id_prod == vector[i].id_prod){
                vector[i].unidades += aux->info.unidades;
                encontrado = true;
                break;
            }
        }

        if(!encontrado){
            cout << "No se encuentro el id" << endl;
        }

        aux=aux->sgte;
    }

    //liberar(lista);

    return 0;
}