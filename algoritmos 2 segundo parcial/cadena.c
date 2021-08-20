#include "cadenaChar.h"

tString cadena;
tPilaCadenaCaracteres pilaNombres, pilaApellidos;

void menu();

int main() {
	printf("\n\n\t ********Cadena de Caracteres***********\n");
    
    crearPilaVacia( &pilaNombres );   
	crearPilaVacia( &pilaApellidos );   
	   
    printf( "Esta vacia? %d\n", pilaVacia( pilaNombres ) );
    
    cargar( &pilaNombres, "Agustina" );
    cargar( &pilaApellidos, "Acosta Company" );
    cargar( &pilaNombres, "Mariano" );
    cargar( &pilaApellidos, "Company Fa" );
    
    printf( "Esta vacia? %d\n\n", pilaVacia( pilaNombres ) );
    
    mostrar( pilaNombres, "Nombres" );
    mostrar( pilaApellidos, "Apellidos" );
	return 0;
}


