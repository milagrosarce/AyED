//ingresar un valor n (<25) generar un vector de n componentes en el cual las mismas contengan
// los primeros numeros naturales pares e  imprimirlo 

#include <iostream>
using namespace std;

int main(){

    int valor;
    int vec[valor];   

    cout << "Ingresar un valor: " << endl;
    cin >> valor; 

    for(int i=0; i < valor; i++){
        vec[i] = 2*i;
        i++;
    }

    mostrar(vec, valor);
}


void mostrar(int vec[], int len){
    for(int i=0; i<len; i++){
        cout << vec[i] << endl;
    }
}