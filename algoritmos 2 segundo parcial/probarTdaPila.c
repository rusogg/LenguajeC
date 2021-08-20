#include "tdaPila.h"

tPilaEstudiantes * pila;

int main() {
	tDatos datos;
	inicializarPila(pila);
	datos.dni = 11111111;
	datos.codigoCat = 1;
	datos.montoAbonado = 200;
	strcpy( datos.nombreApellido, "Gomez VIctor" );
	strcpy( datos.email, "aaa@gmail.com" );
	apilar( pila, datos );
	
	return 0;
} 
