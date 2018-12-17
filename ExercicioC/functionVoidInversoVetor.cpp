/*	Criar uma função para inverter os valores de um vetor de 
inteiros passado como parâmetro, juntamente com seu tamanho.
O main deve ler um vetor qualquer (ex. 5 valores), chamar a
função e mostrar o vetor no final para ver se os valores foram
invertidos.

void inverter(int pvet[], int ptam)
{

}

*/

#include <stdio.h>

void finverte(int pvet[], int ptam) {
	int i, auxvet[ptam];
	for (i = 1; i <= ptam; i++) {
		auxvet[ptam - i] = pvet[i - 1];
	}
	for (i = 0; i < ptam; i++) {
		pvet[i] = auxvet[i];
	}
}

main() {
	int i, vet[] = {1, 2, 3, 4, 5};
	
	finverte(vet, 5);
	
	printf("Vet: ");
	for (i = 0; i < 5; i++) {
		printf("%d" , vet[i]);
	}
	
	getchar();
	getchar();
}
