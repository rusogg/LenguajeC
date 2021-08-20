#include<stdio.h>
#include <windows.h>
void cuentaRegresiva(int);



int main() {
	cuentaRegresiva(10);
	
	return 0;
}

void cuentaRegresiva(int pTiempo){
	if (pTiempo != 0){
		printf("%i\n", pTiempo);
		Sleep(1000);
		system("cls");
		cuentaRegresiva(pTiempo-1);	
	}else{
	
	printf("Cuenta finalizada");}
}
