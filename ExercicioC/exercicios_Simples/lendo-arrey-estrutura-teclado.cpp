/*
* LENDO UM ARRAY DE ESTRUTURA DO TECLADO
*/

#include<stdio.h>
#include<stdlib.h>

struct cadastro {
	char nome[50];
	int idade;
	char rua[50];
	int numero;
};

int main() {
	struct cadastro c[4];
	int i;
	
	for(i = 0; i < 4; i++) {
		printf("Nome: ");
		gets(c[i].nome);
		printf("Idade: ");
		scanf("%d", &c[i].idade);
		printf("Rua: ");
		gets(c[i].rua);
		printf("Numero: ");
		scanf("%d", &c[i].numero);
		printf("\n");
	}
	
	system("pause");
	return 0;
}
