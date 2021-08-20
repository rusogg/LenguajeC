#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20

typedef char tString[50];

typedef tString tArregloString[MAX];

typedef struct {
	tArregloString lista;
	int frente, final;
}tColaClinica;

int cantidadTurnosDisponibles( tColaClinica );
void inicializarCola();
void pedirPacientes();
void agregarPaciente( tString );
void suprimirPrimerElemFrenteMovil();
void verListaPacientes( tColaClinica );
void verTurnosDisponibles( tColaClinica );
void menu();
void menuSiguiente();

tColaClinica colaClinica;

int main() {
    system("color 03"); /* Funcion para colores :D*/ 
	inicializarCola();
	menu();
	
	return 0;
}

void inicializarCola() {
	colaClinica.frente = -1;
	colaClinica.final = -1;
}

bool colaVacia( tColaClinica pCola) {
	return ( pCola.frente == -1 && pCola.final == -1 );
}

bool colaLlena( tColaClinica pCola) {
	return ( pCola.final == (MAX - 1) );
}

void pedirPacientes(){
		tString elem = " ";
		printf("Ingrese nombre del paciente nuevo (x para terminar): ");
		fflush(stdin);
		scanf("%[^\n]s", &elem);
		system("cls");
		while( strcmp(elem, "x") != 0 ){				
			agregarPaciente(elem);
			printf("Ingrese nombre del paciente nuevo (x para terminar): ");
			fflush(stdin);
			scanf("%[^\n]s", &elem);
			system("cls");	
			}
	
}

void agregarPaciente( tString pElemento ) {
	if ( colaLlena( colaClinica ) ) {
		printf("---------------------------------------\n");
		printf("    Ya no hay turnos disponibles!\n");
		printf("---------------------------------------\n\n");
		menu();
	}else {
		/* NO está llena, entonces se puede insertar */
		
		/* Actualizar el final */
		colaClinica.final = colaClinica.final + 1;
		
		/* Grabar el elemento en la lista */
		strcpy( colaClinica.lista[colaClinica.final], pElemento);
		
		if( colaClinica.final == 0 ) { 
			/* 	si colaClinica.final == 0 significa que se está insertando el primer elemento,
				entonces hay que actualizar también el frente */
			colaClinica.frente = 0;
		}
		printf("---------------------------------------\n");
		printf( "Se inserto %s!\n", pElemento );
		printf( "Su numero de turno es: %i\n", colaClinica.final+1 );
		printf("---------------------------------------\n\n");
	}
}

void suprimirPrimerElemFrenteMovil() {
	tString elementoSuprimir;
	if( colaVacia( colaClinica ) ) {
		printf("---------------------------------------\n");
		printf("  Ya no hay mas pacientes por atender\n");
		printf("---------------------------------------\n\n");
	}else {
		strcpy( elementoSuprimir, colaClinica.lista[colaClinica.frente]);
		strcpy( colaClinica.lista[colaClinica.frente], " ");
		if( colaClinica.frente == colaClinica.final ) {
			/* 	se está por eliminar el único elemento de la cola, entonces
				hay que inicializar la cola */
				colaClinica.frente = -1;
				colaClinica.final  = -1;
		} else {
			colaClinica.frente = colaClinica.frente + 1;
		}
		printf("------------------LLAMADO PARA---------------------\n");
		printf("            -------->%s<--------\n", elementoSuprimir);
		printf("---------------------------------------------------\n");
		if( !colaVacia( colaClinica ) ){
		printf("\n\n");	
		printf("------------------PROXIMO PACIENTE-----------------\n");
		printf("            -------->%s<--------\n", colaClinica.lista[colaClinica.frente]); }
		printf("---------------------------------------------------\n");
	}
}

int cantidadTurnosDisponibles( tColaClinica pCola) {
	int cantPacientes=0;
	int total = 0;
	int i;
	for( i = pCola.frente; i <= pCola.final; i++ ) {
		
			cantPacientes++;
		}
		total=MAX-cantPacientes;

		return total;
}

void verListaPacientes( tColaClinica pCola) {
	int i;
	
	if( colaVacia( pCola ) ) {
		printf("---------------------------------------\n");
		printf("   No existen pacientes por atender\n");
		printf("---------------------------------------\n\n");
	} else {
		printf("------Pacientes que esperan por atencion------\n");	
		for( i = pCola.frente; i <= pCola.final; i++ ) {
			printf("| %s |\n", pCola.lista[i]);
				
		}
		printf("------Pacientes que esperan por atencion------\n");
		printf("\n\n");
	}
}

void verTurnosDisponibles( tColaClinica pCola ){
	
		printf("-----------------TURNOS DISPONIBLES----------------\n");
		printf("                     %s\n", colaLlena(pCola) ? "NO" : "SI");	
		printf("---------------------------------------------------\n");
			if( !colaVacia( pCola ) ){
		printf("\n");	
		printf("------------------TOTAL-----------------\n");
		printf("          -------->%i<--------\n", cantidadTurnosDisponibles( colaClinica ));
		printf("------------------TOTAL-----------------\n\n");
				
	
}}

void menu() {	
	int opcion;
	printf("****** SECRETARIA DE CLINICA DEL SOL ******\n\n");	
	printf("|Seleccione una opcion por favor|\n");
	printf("->1- Agregar paciente\n->2- Llamar proximo paciente\n->3- Mostrar turnos disponibles\n");
	printf("->4- Mostrar pacientes del dia\n->5- Salir \n");	
	printf("|Seleccione una opcion por favor|\n");
	opcion = getch();
	system("cls");
	switch (opcion) {
		case 49:
			pedirPacientes();
		    break;
		case 50:		    
		    suprimirPrimerElemFrenteMovil();
			menuSiguiente();
			return;
			break;		
		case 51:
			verTurnosDisponibles( colaClinica );
			break;
		case 52:		 								
			verListaPacientes( colaClinica );				
			break;
		case 53:
			printf("----------HASTA LA PROXIMA----------"); return ;
        	break;
	}
opcion=0;
	printf("|Seleccione una opcion por favor|");
    printf("\n->1-Volver al menu\n->2-Salir\n ");
    printf("|Seleccione una opcion por favor|\n");
    opcion = getch();
    system("cls");
    switch ( opcion ){
   
   		case 49: 
				menu();
                break;
        case 50: printf("----------HASTA LA PROXIMA----------"); return;
                break;}
}

void menuSiguiente(){
	int opcion=0;
			printf("|Seleccione una opcion por favor|");
		 	printf("\n->1-Llamar otro paciente\n->2-Volver al menu\n->3-Salir\n ");
 		    printf("|Seleccione una opcion por favor|\n");
 	  	   opcion = getch();
 	   system("cls");
 	   switch ( opcion ){
				    case 49: 
						suprimirPrimerElemFrenteMovil();
						menuSiguiente();
       		         break;
    			    case 50: 
						menu();
         		       break;
    			    case 51: printf("----------HASTA LA PROXIMA----------"); return ;
         		       break;}
	
}
