/* 	Este programa permite cargar datos de pacientes en una cola dinamica con punteros */
/* 	Integrantes del grupo: Gomez Victor Agustin
						   Romero Enzo
						   Peñaloza Facundo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

/* Tipos de datos personalizados */

typedef char tString [25];

typedef struct{
	tString nobmreYApellido;
	int numeroHisopado;
	int codigoLocalidad; /* 1.Capital, 2.Richuelo, 3.Santa Ana, 4.Paso de la Patria, 5.San Cosme */
} tHisopado;

typedef struct nodoHisopado {
	tHisopado hisopado;		
    struct nodoHisopado * siguiente;    
} tNodoHisopado;

typedef struct {
	tNodoHisopado * principio;
	tNodoHisopado * final;
} tColaHisopados;

/* Declaración de prototipos */

void inicializarColaHisopados();
bool colaVacia( tColaHisopados );
void agregarHisopado( tHisopado ); /* insertar un elemento */
void quitarHisopado(); /* quitar un elemento */
void visualizarHisopados( tColaHisopados );
void solicitarProvincia();
void menu();
void menuSiguiente();

char * provinciaString( int );
int testsTotal(tColaHisopados);
char * informarSiFaltanTest();
int testsPorProvincia( int );;


/* Declaración de variables */

tColaHisopados hisopados;

/* Bloque principal */

int main() {
	system("color 03"); /* Funcion para colores :D*/
	setlocale(LC_ALL, "spanish"); /* Implementación de caracteres del teclado español */		
	inicializarColaHisopados();
	menu();

	return 0;
}

/* Implementación de funciones */

void inicializarColaHisopados() {
	hisopados.principio = NULL;
	hisopados.final = NULL;
}

bool colaVacia( tColaHisopados pHisopados ) {
	return ( pHisopados.principio == NULL && pHisopados.final == NULL );
}

void agregarHisopado( tHisopado pHisopado ) {
	tNodoHisopado * nuevoHisopado;
	
	nuevoHisopado = ( tNodoHisopado * ) malloc( sizeof( tNodoHisopado ) );
	
	nuevoHisopado->hisopado = pHisopado;
	
	nuevoHisopado->siguiente = NULL;
	
	if( colaVacia( hisopados ) ) {
		hisopados.principio = nuevoHisopado;
		hisopados.final = nuevoHisopado;
	}else{
		hisopados.final->siguiente = nuevoHisopado;
		hisopados.final = nuevoHisopado;
	}
	printf("----------------------------------------------------------------\n" );
	printf("               Se agrego el test de un nuevo paciente!\n");
	printf("----------------------------------------------------------------\n" );
}

void quitarHisopado() {
	tNodoHisopado * hisopadoSuprimir;
	tNodoHisopado * hisopadoSiguiente;
	if( colaVacia( hisopados )) {
		printf("----------------------------------------------------------------\n" );
		printf("                 No hay mas test por realizar!\n");
		printf("----------------------------------------------------------------\n" );
	}else{
		hisopadoSuprimir = hisopados.principio;
		
		if( hisopados.principio == hisopados.final ) {
			hisopados.principio = NULL;
			hisopados.final = NULL;
		}else{
			hisopados.principio = hisopadoSuprimir->siguiente;
			hisopadoSiguiente = hisopados.principio;			
		}
		printf("----------------------------------------------------------------\n" );
		printf("      Llamado a relizarse el test para-> %s!             \n", hisopadoSuprimir->hisopado.nobmreYApellido );
		printf("----------------------------------------------------------------\n\n" );
		if( !colaVacia( hisopados )){
		printf("----------------------------------------------------------------\n" );
		printf("      El proximo a realizarse el test es-> %s!             \n", hisopadoSiguiente->hisopado.nobmreYApellido );
		printf("----------------------------------------------------------------\n" );
		}
		free( hisopadoSuprimir );
		hisopadoSuprimir = NULL;
	}
}

void visualizarHisopados( tColaHisopados pHisopados )  {
	tNodoHisopado * aux;		
	
	printf("\n               *** TEST PENDIENTES DE ANALISIS *** \n");
	if( colaVacia( pHisopados ) ) {
		printf("----------------------------------------------------------------\n" );
		printf("         Ya se realizaron todos los test programados!\n");
		printf("----------------------------------------------------------------\n" );
	}else{
		aux = pHisopados.principio;
			printf("NUMERO\tPACIENTE\tCODIGO DE LOCALIDAD\tNOMBRE DE LOCALIDAD\n" );
			printf("----------------------------------------------------------------------------------------------------------\n" );
		while( aux != NULL) {
							
			printf("%i\t%s\t%i\t\t\t%s\n", aux->hisopado.numeroHisopado, aux->hisopado.nobmreYApellido, aux->hisopado.codigoLocalidad, provinciaString( aux->hisopado.codigoLocalidad ) );
			
			aux = aux->siguiente;
		}
			printf("----------------------------------------------------------------------------------------------------------\n" );
		
	}
}


char * provinciaString( int pCodTipoDocumento ) {
	char * tipoProv;
	
	tipoProv = ( char * ) malloc( sizeof( char * ) );
	
	/* 1.Capital, 2.Richuelo, 3.Santa Ana, 4.Paso de la Patria, 5.San Cosme */	
	switch ( pCodTipoDocumento ) {
		case 1: strcpy( tipoProv, "Capital");
				break;
		case 2: strcpy( tipoProv, "Richuelo");
				break;
		case 3: strcpy( tipoProv, "Santa Ana");
				break;
		case 4: strcpy( tipoProv, "Paso de la Patria");
				break;
		case 5: strcpy( tipoProv, "San Cosme");
				break;
		default: strcpy( tipoProv, "error");
	}
	return tipoProv;
}

char * informarSiFaltanTest(){
	char * faltantes;
	int opt = 0;
	opt = colaVacia( hisopados );
	faltantes = ( char * ) malloc( sizeof( char * ) );
	
	switch ( opt ) {
		case 1: strcpy( faltantes, "NO QUEDAN\n");
				break;
		case 0: strcpy( faltantes, "TODAVIA QUEDAN\n");
				break;
		default: strcpy( faltantes, "error");
	}
	

	return faltantes;
}



int testsTotal(tColaHisopados pHisopados){
	int cantFaltantes = 0;
	tNodoHisopado * aux;		
	

		aux = pHisopados.principio;
		
		while( aux != NULL) {
			cantFaltantes++;
			aux = aux->siguiente;
		}
	return cantFaltantes;	
	}
	
	
	
	int testsPorProvincia(int pCodProvincia){
	int cantFaltantes = 0;
	tNodoHisopado * aux;		
	

		aux = hisopados.principio;
		
		while( aux != NULL) {
			switch ( pCodProvincia ) {
		case 1: if (aux->hisopado.codigoLocalidad == 1){
		
				cantFaltantes++;}
				break;
		case 2: if (aux->hisopado.codigoLocalidad == 2){
				cantFaltantes++;}
				break;
		case 3: if (aux->hisopado.codigoLocalidad == 3){		
				cantFaltantes++;}
				break;
		case 4: if (aux->hisopado.codigoLocalidad == 4){	
				cantFaltantes++;}
				break;
		case 5: if (aux->hisopado.codigoLocalidad == 5){
				cantFaltantes++;}
				break;
	}
			aux = aux->siguiente;
		}
	return cantFaltantes;	
	}
	




void solicitarDatos(){
    tHisopado his;
    char opcion = 's';
    while (opcion !='n'){

    printf("Ingrese datos por favor: \n");
    
        printf("\tNumero de hisopado: ");
   		scanf("%i", &his.numeroHisopado);
    
    printf("\tNombre y apellido del Paciente: ");
    fflush(stdin);
    scanf("%[^\n]s", &his.nobmreYApellido);



    printf("\tCodigo de localidad(1.Capital, 2.Richuelo, 3.Santa Ana, 4.Paso de la Patria, 5.San Cosme): ");
    scanf("%i", &his.codigoLocalidad);
    agregarHisopado( his );

    printf("Cargar otro? s-n: ");
    opcion=getch();
    system("cls");

    }


}

void solicitarProvincia(){
	int opcion = 0;
    printf("Ingrese el codigo de localidad que desea mostrar el total de test faltantes\n(1.Capital, 2.Richuelo, 3.Santa Ana, 4.Paso de la Patria, 5.San Cosme): ");
    scanf("%i", &opcion);
	system("cls");
	printf("-----------------------------------------------------------------------\n" );
    printf("      Cantidad total de test faltantes para %s : %i\n", provinciaString( opcion ), testsPorProvincia(opcion));
    printf("-----------------------------------------------------------------------\n" );
}


void menu() {
int opcion;
    int k = 0;
    printf("---------------------------------------------\n");
    printf("        INSTITUTO SANITARIO DEL NORDESTE\n");
    printf("---------------------------------------------\n");
    printf("        **  Programa de hisopados **\n\n");
    printf("|Seleccione una opcion por favor|\n");
    printf("->1- Registrar hisopados\n->2- Llamar paciente\n->3- Total de test que faltan analizar\n");
    printf("->4- Visualizar test que faltan analizar\n->5- Ver si quedan test por analizar \n->6- Ver cuantos test de una provincia especifica faltan\n->7- Salir \n");
    printf("|Seleccione una opcion por favor|\n");
    opcion = getch();
    system("cls");
    switch (opcion) {
        case 49:
            solicitarDatos();
           break;
        case 50:
            quitarHisopado();
			menuSiguiente();
			return;
        break;
        case 51:
        	printf("----------------------------------------------------------------\n" );
            printf("          Cantidad total de test faltantes: %i\n", testsTotal( hisopados ));
            printf("----------------------------------------------------------------\n" );
        break;
        case 52:
        	visualizarHisopados(hisopados);
        break;
        case 53:
        	printf("----------------------------------------------------------------\n" );
        	printf("                           %s", informarSiFaltanTest());
        	printf("----------------------------------------------------------------\n" );
        break;
        case 54:
            solicitarProvincia() ;
        break;
        case 55:
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
				quitarHisopado();
				menuSiguiente();
                break;
       case 50:
				menu();
                break;
       case 51: printf("----------HASTA LA PROXIMA----------"); return ;
                break;}

}
