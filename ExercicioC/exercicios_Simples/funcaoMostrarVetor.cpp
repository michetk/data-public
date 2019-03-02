/*
Implementar a funcao MostrarVetor que mostra um vetor com n valores reais (n >= 1)
*/

#include<stdio.h>
#include<stdlib.h>

void mostrarVetor(float *v, int t);
void lerVetor(float *v, int t);

int main () {
	do{
		system("cls");
		
		int t;
		
		printf("Digite a o tamanho do Vet: ");
		scanf("%d", &t);
	
		float vet[t];
		
		lerVetor(vet, t);
		printf("\n");
		mostrarVetor(vet, t);
		
		system("pause");
	}while(1);
	
	return 0;
}

void mostrarVetor(float *v, int t) {
	int i;
	for (i = 0; i < t; i++) {
		printf("Vet[%d]: %f\n", i+1, v[i]);
	}
}
void lerVetor(float *v, int t) {
	int i;
	//float vet[n];
	for (i = 0; i < t; i++) {
		printf("Digite o valor do Vet[%d]: ", i+1);
		//scanf("%f", &vet[i]);
		scanf("%f", &v[i]);
	}
}
