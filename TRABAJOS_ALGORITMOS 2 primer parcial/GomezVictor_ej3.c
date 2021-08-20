/* 	Este programa realiza el corte sobre una archivo de una cola de impresion, 
	ordenado según el campo de control correspondiente al ip de cada pc */
	/* 	Integrantes del grupo: Gomez Victor Agustin
						   Romero Enzo
						   Peñaloza Facundo */
	
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

/* Tipos de datos personalizados */

typedef char tString[50];
typedef struct {	    

    tString ip;
    float tamanioBytes;
    tString nombreDoc;
    int tipoDoc;
}tRegistroImpresora; 

/* Declaración de prototipos */

void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unDocumento();
void finCorte();



/* Declaración de variables */

tRegistroImpresora impresora;
FILE * archivoImpresora;

tString ipAnt;
float tamanioTotalKb, tamanioTotalBytes, tamanioTotalImagenes, tamanioImagenes;
int cantDocumentosPorPc, totalDocumentos, cantDocImg, cantDocImgTotal;
char * tipoDocumentoString( int );


/* Bloque principal */
int main() {		

	system("color 03"); /* Funcion para colores :D*/
	setlocale(LC_ALL, "spanish"); /* Implementación de caracteres del teclado español */
	inicializacion();	
	procesoCorte();		
	finalizacion();
}

/* Implementación de funciones */

void inicializacion() {
	/*	Actividades al inicio del programa:	
		1. Abrir archivo en modo lectura
		2. Leer el primer registro
		3. Guardar campo de control anterior
		4. Inicializar contadores/acumuladores generales/totales 
		5. Escribir titulos */
			
	archivoImpresora = fopen("Impresora.dat", "rb");			
    fread(&impresora, sizeof(tRegistroImpresora), 1, archivoImpresora);    
	strcpy( ipAnt, impresora.ip);	
	
	
	
	cantDocImgTotal	= 0;
	totalDocumentos = 0;
	tamanioTotalKb = 0.0;
	tamanioTotalImagenes = 0.0;
	printf("-------------------------------------------------------\n");
	printf("||||||||||||||IMPRESORA HP LASER JET 1020||||||||||||||\n");
	printf("-------------------------------------------------------\n");
	printf("\tIP\tDOCUMENTO\tTAMAÑO ARCHIVO\n");
	printf("-------------------------------------------------------\n");
}

void procesoCorte() {
	/* Recorrer el archivo hasta el final (feof) */
	while (!feof(archivoImpresora)) { 
		principioCorte(); 
		
		/* Con este while trabajamos con cada grupo  */
	    while(!feof(archivoImpresora) && strcmp(ipAnt, impresora.ip)==0) { 
			unDocumento();
			fread(&impresora, sizeof(tRegistroImpresora), 1, archivoImpresora);
		} 
		/* Cuando termina este while significa que terminó un grupo entonces realizamos las actividades del corte */
		
		finCorte();
	}
	/* Cuando termina este while significa que se terminó de recorrer el archivo */
}

void principioCorte() {
	/* 	Actividades antes de recorrer los grupos:
			1. Inicializar los contadores/acumuladores parciales */			
	cantDocumentosPorPc = 0;
	tamanioTotalBytes = 0.0;
	tamanioImagenes	= 0.0;
	cantDocImg = 0;			
}

char * tipoDocumentoString( int pCodTipoDocumento ) {
	char * tipoDoc;
	
	tipoDoc = ( char * ) malloc( sizeof( char * ) );
	
	/* 1-docx 2-pdf 3-jpg 4-png 5-xlsx */	
	switch ( pCodTipoDocumento ) {
		case 1: strcpy( tipoDoc, "docx");
				break;
		case 2: strcpy( tipoDoc, "pdf");
				break;
		case 3: strcpy( tipoDoc, "jpg");
				break;
		case 4: strcpy( tipoDoc, "png");
				break;
		case 5: strcpy( tipoDoc, "xlsx");
				break;
		default: strcpy( tipoDoc, "error");
	}
	return tipoDoc;
}

void unDocumento(){
	/* Actividades por grupo
			1. Actualizar contadores/acumuladores parciales
			2. Mostrar la línea del detalle en el caso que sea necesario
			3. Buscar el mayor/menor del grupo (parcial) en el caso que sea necesario
			4. Leer otro registro (leerRegistro) */
	cantDocumentosPorPc = cantDocumentosPorPc + 1; 
	tamanioTotalBytes = tamanioTotalBytes + impresora.tamanioBytes;	
	
		if( impresora.tipoDoc == 3 || impresora.tipoDoc == 4 ) {
				cantDocImg++;
				tamanioImagenes = tamanioImagenes + impresora.tamanioBytes;
							}
	printf("%s\t%s.%s\t%.2fB\n", impresora.ip, impresora.nombreDoc, tipoDocumentoString( impresora.tipoDoc ), impresora.tamanioBytes);							
}

void finCorte(){      		
	/* 	Actividades por fin de corte de control
			1. Mostrar subtotales (línea de totales del grupo en el caso que el ejercicio lo solicite)
			2. Guardar la clave anterior(campo de control), en este caso codCarrera 		
			3. Calcular promedios/porcentajes parciales en el caso que el problema lo requiera
			4. Actualizar contadores/acumuladores generales			
			5. Buscar el mayor/menor (general) en el caso que el problema lo requiera */ 		
	
	tamanioTotalKb = tamanioTotalKb + tamanioTotalBytes/1024;
	tamanioTotalImagenes = tamanioTotalImagenes + tamanioImagenes;
	totalDocumentos = totalDocumentos + cantDocumentosPorPc;
	cantDocImgTotal = cantDocImgTotal + cantDocImg;
	

				
	printf("\nCantidad de\ndocumenntos\nimpresos PC\n%s", ipAnt);
	printf("\t%d", cantDocumentosPorPc);
	printf("\t\t%.2f KB\n", tamanioTotalBytes/1024);
	printf("-------------------------------------------------------\n");
	
	strcpy( ipAnt, impresora.ip);	
}

void finalizacion(){
	/* 	Actividades al finalizar
			1. Mostrar totales
			3. Cerrar el archivo */
			printf("Total de\narchivos de\nimagenes\nimpresos\t%d\t\t%.2f KB\n", cantDocImgTotal, tamanioTotalImagenes/1024);
			printf("Total de\ndocumentos\nimpresos\t%d\t\t%.2f KB\n", totalDocumentos, tamanioTotalKb);
	
	fclose(archivoImpresora);      
}
