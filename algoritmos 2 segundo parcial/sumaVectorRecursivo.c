#include<stdio.h>
#define MAX 5
typedef int tVector[MAX];
tVector vector;
float sumarVector(tVector, int);

int main( ){
	vector [0]=10.50;
	vector [1]=2.50;
	vector [2]=12.50;
	vector [3]=5.20;
	vector [4]=32.10;
	printf("suma es: %.2f", sumarVector(vector, 0));
	return 0;
}

float sumarVector(tVector pVector, int i){
	if (i < MAX){
		return vector[i]+sumarVector(pVector,i+1);
	}
}

