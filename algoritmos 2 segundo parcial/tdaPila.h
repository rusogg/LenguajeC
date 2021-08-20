#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Tipos de datos personalizados */

typedef char tString [50];

typedef struct {
	int dni;
	tString nombreApellido;
	tString email;
	int codigoCat;
	float montoAbonado;
	
}tDatos;

typedef struct nodo {
	tDatos data;
	struct nodo * siguiente;
}tPilaEstudiantes;

/* Declaración de prototipos */

void inicializarPila(tPilaEstudiantes *);
void apilar( tPilaEstudiantes *, tDatos );

void inicializarPila(tPilaEstudiantes * pPila) {
	pPila = NULL;
	printf("Pila creada!\n");
}


void apilar( tPilaEstudiantes * pPila, tDatos pData ) {
	tPilaEstudiantes * nuevoNodo;
	
	nuevoNodo = ( tPilaEstudiantes * ) malloc( sizeof( tPilaEstudiantes ) );
	
	nuevoNodo->data = pData;
	
	nuevoNodo->siguiente = pPila;
	
	pPila = nuevoNodo;
	
	printf("\nElemento insertado!\n");
}
