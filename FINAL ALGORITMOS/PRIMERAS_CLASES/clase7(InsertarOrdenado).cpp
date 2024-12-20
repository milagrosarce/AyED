#include <iostream>

using namespace std;

int buscar(int vec[], int len, int valor);
void insertar(int vec[], int &len, int valor, int pos);
void insertarOrdenado(int vector[], int &len, int valor);
void eliminar(int vec[], int &len, int pos);

int main(){

    int n;
    int len = 10;
    int vector[len];
    int numero;
    int resultado;

    cout << "ingrese un valor o cero para finalizar" << endl;
    cin >> n;

    while(n!=0){
        insertarOrdenado(vector, len, n);
        cout << "ingrese un valor o cero para finalizar" << endl;
        cin >> n;
    }


    cout << "Ingrese el numero que quiere buscar" << endl;
    cin >> numero; 

    resultado = buscar(vector, len, numero);
    
    if(resultado == -1){
        cout << "El numero no se encuentra en el vector" << endl;
    }else{
        cout << "El numero es" << vector[resultado] << " y se encuentra en la posicion " << resultado << endl;


}
}


//INSERTAR (vector (siempre pasan por referencia no hay que poner &), largo, valor, posicion)

//void insertar(int vect[], int &len, int valor, int pos); 

void insertar(int vec[], int &len, int valor, int pos){

    for(int i=len; i>pos; i--){ //quiero hacer que bajen los valores
        vec[i] = vec[i-1];
    }
    vec[pos] = valor; //una vez que ya llegue a donde queria
    len++; //aumento el largo
}


//PARA AGREGAR UN VALOR ORDENADO A UN VECTOR ORDENADO DE MENOR A MAYOR
void insertarOrdenado(int vector[], int &len, int valor){
	
 //1 donde voy a cargar el valor
 int i=0; 
 while(i<len && vector[i]<= valor){
 	i++;	
 }
 
 //2 CARGAR EL VALOR
 if(i==len){ //si llegue al final
 	vector[len]= valor;
 	len++; 
 }else insertar(vector, len, valor, i); 

}

//BUSCAR UN VALOR EN LOS VECTORES 

int buscar(int vec[], int len, int valor){

    for(int i=0; i<len; i++){
        if(vec[i]==valor){
            return i;
        }
    }
    return -1;
}

//ELIMINAR CIERTA POSICION DE UN VECTOR 

void eliminar(int vec[], int &len, int pos){
    

    for(int i=pos; i<len-1; i++){
        vec[i] = vec[i+1];
    }
    len--;
}


void sumarVec(int vec[], int len){

    int resultado = 0;

    for(int i=0; i<len; i++){
        resultado += vec[i];
    }

    cout << "La suma total de todos los valores del vector es: " << resultado << endl; 
}

