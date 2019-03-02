/*
Implementar a funcao LerVetor que preenche um vetor com n valores reais (n .
1)
*/

#include<stdio.h>
#include<stdlib.h>

void lerVetor(int n, float *v);

int main () {
	do{
		system("cls");
		
		int n;
		printf("Digite o tamanho do vetor: ");
		scanf("%d", &n);
		
		float vet[n];
		
		lerVetor(n, vet);
		
		system("pause");
	}while(1);
	return 0;
}

void lerVetor(int n, float *v) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Digite o valor do Vet[%d]: ", i+1);
		scanf("%f", &v[i]);
	}
}

