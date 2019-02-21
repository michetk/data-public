/*
*ABERTURA E FECHAMENTO DE ARQUIVO, TESTE DE VALIDAÇÃO.
*/

#include<stdio.h>

int main() {
	FILE *p;
	int resposta;
	p = fopen("arquivo.txt", "w");
	if(p == NULL)
		printf("\nErro na abertura!");
	else {
		printf("\nSucesso na abertura");
		resposta = fclose(p);
		if(resposta == 0)
			printf("\nSucesso no fechamento");
		else
			printf("\nErro no fechamento!");
	}
	getchar();
	return 0;
}
