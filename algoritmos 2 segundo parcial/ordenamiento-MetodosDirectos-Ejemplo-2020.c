#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 7

typedef int tVector [MAX];	

tVector A, B, C, D;

void generarVector( tVector );
void verVector( tVector );
void SeleccionDirecta( tVector );
void InsercionDirecta( tVector );
void OrdenacionPorIntercambio( tVector );
void OrdenacionBurbujaMejorada( tVector );

int main() {
	printf("\nIngrese A:\n");
	generarVector(A);	
	printf("\nA:");
	verVector(A);
	SeleccionDirecta(A);
	printf("\nVector A luego de la ordenacion por seleccion directa: ");	
	verVector(A);
	
	printf("\nIngrese B:\n");
	generarVector(B);	
	printf("\nB:");
	verVector(B);
	InsercionDirecta(B);
	printf("\nVector B luego de la ordenacion por insercion directa: ");	
	verVector(B);

	printf("\nIngrese C:\n");
	generarVector(C);	
	printf("\nC:");
	verVector(C);
	OrdenacionPorIntercambio(C);
	printf("\nVector C luego de la ordenacion por intercambio directo: ");	
	verVector(C);
	
	printf("\nIngrese D:\n");
	generarVector(D);	
	printf("\nD:");
	verVector(D);
	OrdenacionBurbujaMejorada(D);
	printf("\nVector D luego de la ordenacion por intercambio mejorado: ");	
	verVector(D);
		
	return 0;
}

void generarVector( tVector pVector ) {
	pVector[0] = 4;
	pVector[1] = 5;
	pVector[2] = 7;
	pVector[3] = 9;
	pVector[4] = 8;
	pVector[5] = 2;
	pVector[6] = 1;
	/*int i;
	for (i = 0; i < MAX; i++) {
		printf("Ingrese un numero: ");
		scanf("%d", &pVector[i]); fflush(stdin);
	}*/
}

void verVector( tVector pVector ) {
	int i;
	printf("\nContenido del vector:\n");
	for (i = 0; i < MAX; i++) 	{
		printf("%d\t", pVector[i]);
	}
	printf("\n");
}

/* Obtención sucesiva de menores */
void SeleccionDirecta( tVector pVector ) {
	// Efecto: se ordena v ascendentemente
	int i, j, posMenor;
	int valMenor, aux;
	
	for ( i = 0; i < MAX-1; i++ ) { // n-1 pasadas
		valMenor = pVector[i];
		posMenor = i;
		
		for ( j = i+1; j < MAX; j++ ) { // el número de comparaciones decrece
			if ( pVector[j] < valMenor ) {
				//se actualiza el nuevo valor menor y la posición donde se encuentra
				valMenor = pVector[j];
				posMenor = j;
			}
		}
		if ( posMenor != i ) {
			//Si el menor no es pVector[i], se intercambian los valores
			aux = pVector[i];
			pVector[i] = pVector[posMenor];
			pVector[posMenor] = aux;
		}		
	}
}

void InsercionDirecta( tVector pVector ) {
	int i, j;
	int aux;

	for ( i = 1; i < MAX; i++ ) {
		/* 	i corresponde a la posición del elemento que se desea ubicar 
			en la posición correcta respecto de los anteriores */
		aux = pVector[i]; /* En aux se asigna el valor del elemento que se desea colocar en su posición correcta */		
		j = i - 1;	/* j inicia con el valor de la posición del elemento anterior al que se desea colocar en su posición correcta */	
		while ( (j >= 0) && (pVector[j] > aux) ) {
			pVector[j+1] = pVector[j];
			//Desplazamiento de los valores mayores que pVector[i]
			j = j-1;											
		}
		pVector[j+1] = aux;		
	}
}

void OrdenacionPorIntercambio( tVector pVector ) {
	//Efecto: se ordena v ascendentemente 
	int i, j;
	int aux;	
	
	for ( i = 0; i < MAX-1; i++ ) { //n-1 pasadas
		for ( j = 0; j < MAX-1; j++ ) { //n-1 comparaciones
		//for (j = 1; j < MAX-i; j++) //->opcion2			
			if (pVector[j] > pVector[j+1]) { 
				//intercambio
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux;			
			}
					
		}		
	}
}

void OrdenacionBurbujaMejorada( tVector pVector ) {
	//Efecto: se ordena v ascendentemente
	int i, j;
	int aux;
	bool bandera;

	bandera = false;
	i = 0;
	while ( ( bandera == false ) && ( i < MAX ) ) {
		bandera = true;	
		for ( j = 0; j < MAX-1; j++ )	{
			//Se busca el menor desde atras y se situa en vi
			if ( pVector[j] > pVector[j+1] ) {
				//intercambio
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux;
				bandera = false;
			}
		}
		i = i+1;				
	}
}
