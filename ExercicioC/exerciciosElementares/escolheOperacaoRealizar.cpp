/*
Programa que permite escolher qual operação será realizada
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void lerVetor(float *v, int t);
void mostrarVetor(float *v, int t);
int posicaoMaior(float *v, int t);

int main() {
	do{
		system("cls");
		int op, aux, i, t, pos;
		char mensagemOpcao[] = "OPCAO NAO CONFERE >> TENTE NOVAMENTE";
		
		printf("___ESCOLHA A OPERACAO___\n\n");
		printf("1. Funcao LerVetorRea\n");
		printf("2. Funcao MostrarVetor\n");
		printf("3. Funcao PosicaoMaiorVetor\n");
		
		aux = 0;
		do {
			if (aux > 0) {
				system("cls");
				printf("___ESCOLHA A OPERACAO___\n\n");
				printf("1. Funcao LerVetorRea\n");
				printf("2. Funcao MostrarVetor\n");
				printf("3. Funcao PosicaoMaiorVetor\n");
				printf("\n%s", mensagemOpcao);
			}
			printf("\n\nEscolha a opcao: ");
			scanf("%d", &op);
			if (op >= 1 && op <= 3) {
				system("cls");
				printf("___ESCOLHA A OPERACAO___\n\n");
				printf("1. Funcao LerVetorRea\n");
				printf("2. Funcao MostrarVetor\n");
				printf("3. Funcao PosicaoMaiorVetor\n");
				printf("\n\nOPCAO ESCOLHIDA: %d\n\n", op);
			}
			else
				aux += 1;
		}while(op < 1 || op > 3);
		
		if (op == 1) {
			printf("Digite o tamanho do vetor: ");
			scanf("%d", &t);
			
			float vet[t];
			
			lerVetor(vet, t);
			printf("\n");
		}
		else if (op == 2) {
			printf("Digite a o tamanho do Vet: ");
			scanf("%d", &t);
		
			float vet[t];
			
			lerVetor(vet, t);
			printf("\n");
			mostrarVetor(vet, t);
			printf("\n");
		}
			else {
				printf("QTDE posicoes Vet: ");
				scanf("%d", &t);
				
				float v[t];
				
				lerVetor(v, t);
				pos = posicaoMaior(v, t);
				
				printf("\nPosicao do maior valor no Vet: %d\n\n", pos);
			}
		
		system("pause");
	}while(1);
	
	return 0;
}

void lerVetor(float *v, int t) {
	int i;
	for (i = 0; i < t; i++) {
		printf("Digite o valor do Vet[%d]: ", i);
		scanf("%f", &v[i]);
	}
}
void mostrarVetor(float *v, int t) {
	int i;
	for (i = 0; i < t; i++) {
		printf("Vet[%d]: %.2f\n", i, v[i]);
	}
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
