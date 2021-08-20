/*Escribir un TDA para cargar y mostrar los elementos de una pila estática de elementos de tipo cadena de
caracteres. Luego desarrolle un programa para probar dicho TDA*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef char tString[25];

typedef tString tListaString[MAX];

typedef struct {
	tListaString pilaString;
	int tope;
} tPilaCadenaCaracteres;

void crearPilaVacia( tPilaCadenaCaracteres * );
bool pilaVacia( tPilaCadenaCaracteres );
bool pilaLlena( tPilaCadenaCaracteres );
void cargar( tPilaCadenaCaracteres *, tString );

void mostrar( tPilaCadenaCaracteres, tString );

void crearPilaVacia( tPilaCadenaCaracteres * pPila ) {	
    pPila->tope = -1;
    printf("Se inicializo la pila!\n");
}

bool pilaVacia( tPilaCadenaCaracteres pPila ){
    return ( pPila.tope == -1 ); 
}

bool pilaLlena( tPilaCadenaCaracteres pPila ){
	return ( pPila.tope == MAX-1 );
}

void cargar( tPilaCadenaCaracteres * pPila, tString pElem){
	if ( !pilaLlena( *pPila ) ) {
		pPila->tope = pPila->tope + 1; 
		strcpy( pPila->pilaString[pPila->tope], pElem ); 
		printf("Elemento insertado!\n");
	} else {
		printf("No hay lugar para mas caracteres!\n");
	}
}

void mostrar( tPilaCadenaCaracteres pPila, tString pTitulo ){
	printf( "\n\nPila de %s \n", pTitulo );
	int i;
	
	if (!pilaVacia( pPila )) {
	
		for ( i=0; i <= pPila.tope; i++) {
			printf("%s |  ", pPila.pilaString[i]);
		}
	} else {
		printf("No hay elementos en la pila!\n");
	}
}
