/* 	Este programa permite cargar datos de un listado de documentos para una impresora en un archivo .dat */
/* 	Integrantes del grupo: Gomez Victor Agustin
						   Romero Enzo
						   Peñaloza Facundo */
	
#include <stdio.h> 
#include <string.h>
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
void iniciarProceso();
void grabarArchivoImpresora();
void finalizarProceso();
void ingresarDatos();

/* Declaración de variables */
tRegistroImpresora impresora;
FILE * archivoImpresora;

/* Bloque principal */
int main() {
system("color 03"); /* Funcion para colores :D*/
setlocale(LC_ALL, "spanish"); /* Implementación de caracteres del teclado español */
iniciarProceso();
grabarArchivoImpresora();
finalizarProceso();
return 0;
}

/* Implementación de funciones */

void iniciarProceso() {
	/* Se crea el archivo para almacenar registros */
archivoImpresora = fopen("impresora.dat", "ab");
printf("|||||||||||||||||IMPRESORA HP LASERJET 1020||||||||||||||||\n");
printf( "\tArchivo creado! \n" );
}

void grabarArchivoImpresora() {
	/* Llama a la funcion ingresarDatos y pregunta si quiere seguir cargando datos */
char opcion = 's';
while (opcion !='n') {
ingresarDatos();

fwrite( &impresora, sizeof( tRegistroImpresora ), 1, archivoImpresora );
printf( "\tDocumento agregado a cola de impresion!\n" );

printf("Cargar otro? s-n: ");
opcion=getch();
system("cls");
printf("|||||||||||||||||IMPRESORA HP LASERJET 1020||||||||||||||||\n");
}
}

void ingresarDatos() {
	/* Pide al usuario los respectivos registros para almacenarlos en el .dat */
printf("Ingrese datos por favor: \n");
printf("\tIP de la pc: ");
fflush(stdin);
scanf("%[^\n]s", &impresora.ip);

printf("\tNombre del documento: ");
fflush(stdin);
scanf("%[^\n]s", &impresora.nombreDoc);


printf("\tTipo de documento (1. docx - 2.pdf - 3.jpg - 4.png - 5.xlsx): ");
scanf("%i", &impresora.tipoDoc);

printf("\tTamaño del documento en Bytes: ");
fflush(stdin);
scanf("%f", &impresora.tamanioBytes);
}

void finalizarProceso() {
/* Cierra el .dat para no perder ningun dato */
fclose(archivoImpresora);
system("cls");
printf("|||||||||||||||||HASTA LUEGO|||||||||||||||||");
}
