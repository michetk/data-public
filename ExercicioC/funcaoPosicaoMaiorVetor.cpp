/*
Implementar a função PosicaoMaior que determina (e devolve)
a posição/índice do maior valor de um vetor X com n valores
reais.
*/

#include<stdio.h>
#include<stdlib.h>

void lerVetor(int n, float *v);
int posicaoMaior(float *v, int t);

int main() {
	do{
		system("cls");
		
		int i, t, pos;
		
		printf("QTDE posicoes Vet: ");
		scanf("%d", &t);
		
		float v[t];
		
		lerVetor(t, v);
		pos = posicaoMaior(v, t);
		
		printf("\nPosicao do maior valor no Vet: %d\n\n", pos);
		
		system("pause");
	}while(1);
	return 0;
}

int posicaoMaior(float *v, int t) {
	int i, pos;
	float maior;
	
	maior = v[0];
	pos = 0;
	for (i = 1; i < t; i++) {
		if(v[i] > maior) {
			maior = v[i];
			pos = i;
		}
	}
	return pos;
}
void lerVetor(int n, float *v) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Digite o valor do Vet[%d]: ", i);
		scanf("%f", &v[i]);
	}
}
