#include <iostream> 

using namespace std;

/*---------------------ARCHIVOS----------------------------------*/

//1. definir el puntero al archivo
//2. abrir el archivo. para leer o para escribir
//3. lectura del archivo (si lo estoy abriendo para leer)
//4. proceso/calculos/o lo que me pidan
//5. cerrar el archivo


/* MODOS DE APERTURA
-rb _lectura
-wb _escritura
-rb+ _primero leeo y despues escribo 
-wb+ _primero escribo y luego leo 
*/

struct alumno{

    int nota1;
    int nota2;
}; 

int main(){

    int sumatoria = 0;

    FILE* archivo;  // SIEMPRE QUE SE TRABAJA CON ARCHIVOS PRIMERO HAY QUE HACER UN PUNTERO 
	archivo = fopen("datos.dat", "wb"); // AHORA ABRIMOS SI O SI EL ARCHIVO 
	
	alumno raux; // DECLARAMOS UNA VARIABLE AUXILIAR PARA PODER TRABAJAR ESOS DATOS QUE ESTAN EN EL ARCHIVO 
	
	fread(&raux, sizeof(alumno),1,archivo); // el nombre del registro auxiliar, tipo de variable de ese registro, 1, puntero. 
	
	while(!feof(archivo)){ //MIENTRAS NO SEA EL FINAL DEL ARCHIVO...
			
		sumatoria = sumatoria + raux.nota1; 	
			
			
		fread (&raux, sizeof(alumno), 1, archivo); // TAMBIEN
	}
	fclose(archivo); 
	
	// TODO LO DE ARRIBA FUE SOLAMENTE PARA LEER UN ARCHIVO 
	
	cout << sumatoria << endl; 

    return 0; 
}