#include <stdio.h> 
#include <stdlib.h> 
//#include<conio.h> //Esta libreria solo sirve para güindous.
#include <ncurses.h> //Esta es la libreria que sustituye a conio en Linux
#include <math.h>

// Aqui creamos la matriz con los valores dados
int **crearMatriz (int tam){

	int **matriz = (int **) malloc (tam * sizeof (int *)); 

	for (int i = 0; i < tam; i++) { 
		matriz [i] = (int *) malloc (tam * sizeof (int)); 
	} 

	return matriz; 
}

//Imprime en forma bonita las matrises que le demos
void imprimir (int **matriz, int tam){

	for (int i = 0; i < tam; i++){ 
		for (int j = 0; j < tam; j++){ 
			printf ("%d ", matriz [i][j]); 
		} 
		printf ("\n"); 
	} 
}

bool esSimetrica (int **matriz, int tam){ 
	
	for (int i = 0; i < tam; i++){ 
		for (int j = 0; j < tam; j++){ 
			if (matriz [i] [j] != matriz [j] [i]){ 
				return false; 
			} 
		} 
	} 

	return true; 
} 


int main (){ 

	//Estamos declarando e inicializando variables.
	int uno = 1;
	int w = 0;
	int tam = 0;

	//Aqui le vamos a pedir al usuario que nos diga de que tamaño quiere la matriz.
	printf("Define de que tamaño va a ser tu matriz: ");
	scanf("%d",&w);
	tam = w;

	//Le decimos que cree la matriz con el tamaño dado por el usuario
	int **matriz = crearMatriz (tam); 

	//Aquí le estamos diciendo los valores que van a quedar dentro de la matriz
	//Es como recorrer un arreglo y asignar valores
	printf ("Ingresa los numeros que van a ir dentro de la matriz\n\n"); 

	for (int i = 0; i < tam; i++){
		for (int j = 0; j < tam; j++){ 
			printf ("Fila [%d] Columna [%d]: ", i + 1, j + 1); 
			scanf ("%d", &matriz [i][j]); 
		} 
	}

	//Aqui imprimimos la matriz ordenadamente bien
	printf("\n");
	printf ("Ok Aquí está tu matriz: \n\n"); 
	imprimir (matriz, tam); 
	printf ("\n");

	//Aqui vemos Si la matriz es simetrica
	if (esSimetrica (matriz, tam)){ 
		printf ("La matriz es simetrica.\n"); 
	} 
	else{
		printf ("La matriz no es simetrica.\n");
	}

	//Aqui vamos a convertir los valores 
	for (int i = 0; i < tam; i++){ 
		for (int j = 0; j < tam; j++){ 
			if (matriz [i] [j] != 0 && matriz [i] [j] !=1){
				printf("\n");
				printf("Vamos a convertir la matriz en 1 y 0\n");
				printf("\n");
				matriz[i][j] = 1;
			}
		} 
	}
	//Aqui imprimimos la matriz con lo valores convertidos
	printf("\n");
	printf ("Gracias, aquí está tu matriz: \n\n"); 
	imprimir (matriz, tam); 
	printf ("\n");

	//Aqui le estoy diciendo que me lo haga simetrica
	printf("\n");
	printf("Haciendola simetrica");
		for (int i = 0; i < tam; i++){ 
			for (int j = 0; j < tam; j++){ 
				if (i == j){
					printf("\n");
					matriz[i][j] = 0;
			}
		} 
	}

	//Imprime la matriz con la diagonal de ceros
	printf("\n");
	printf ("Gracias, aquí está tu matriz Simetrica: \n\n"); 
	imprimir (matriz, tam); 
	printf ("\n");

}