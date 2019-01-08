/* Ler a nota de n alunos e armazenar num vetor (float). 
Após a leitura, calcular e mostrar:
  
  a) A qtde de aprovados (média mínima = 6.0)
  
  b) A média aritmética dos aprovados.
*/

#include <stdio.h>
#include <stdlib.h>

float fqtdeAprovados(float fvet[], int ftam) {
	float qtde;
	int i;
	qtde = 0;
	for (i = 0; i < ftam; i++) {
		if (fvet[i] >= 6)
			qtde++;
	}
	return qtde;
}

float fmediaAritimetica (float fvet[], int ftam, float fmedia) {
	float ma, soma;
	int i, qtde;
	soma = qtde = 0;
	for (i = 0; i < ftam; i++) {
		if (fvet[i] >= fmedia) {
			soma += fvet[i];
			qtde++;
		}
		ma = soma / qtde;
	}
	return ma;
}

main () {
	float vet[10], qtde, ma, media;
	int i, tam;
	tam = 10;
	media = 6;
	do {
		system ("cls");
		
		printf("_____MEDIA ARITIMETICA_____\n\n\n");
		
		for (i = 0; i < tam; i++) {
		printf("Nota Aluno[%d]: ", i + 1);
		scanf("%f", &vet[i]);
		}
	
		qtde = fqtdeAprovados(vet, tam);
		ma = fmediaAritimetica(vet, tam, media);
		
		printf("\n\nQTDE Aprovados: %.1f", qtde);
		printf("\nMedia Aritimetica dos Aprovados: %.1f", ma);
		
		printf("\n\n\nENTER PARA SAIR...");
		
		getchar();
		getchar();
		
		}while(1);
}
