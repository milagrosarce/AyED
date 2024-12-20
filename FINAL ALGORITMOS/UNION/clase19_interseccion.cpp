#include <iostream>

using namespace std;

/*
Interseccion de dos vectores en un vector
*/

int main(){

    return 0;
}

void interseccion(int vectorA[], int lenA, int vectorB[], int lenB, int vectorC[], int &lenC){

    for(int i=0;i<lenA;i++){
        for(int j=0;j<lenB;j++){
            if(vectorA[i] == vectorB[j]){
                vectorC[lenC] = vectorA[i]; 
                lenC++; //para ir aumentado el tamaño del vector 
            }
        }
    }
}

