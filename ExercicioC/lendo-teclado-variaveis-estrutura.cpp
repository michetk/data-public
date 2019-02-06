/*
LENDO DO TECLADO AS VARIÁVEIS DA ESTRUTURA
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
	struct cadastro c;
	
	gets(c.nome);
	scanf("%d", &c.idade);
	gets(c.rua);
	scanf("%d", &c.numero);
	
	printf("Nome: %s\n", c.nome);
	printf("Idade: %d\n", c.idade);
	printf("Rua: %s\n", c.rua);
	printf("Numero: %d\n", c.numero);
	
	system("pause");
	return 0;
}
