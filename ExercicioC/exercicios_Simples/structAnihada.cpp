/*
*ESTRUTURA ANINHADA
*/

#include<stdio.h>

struct endereco {
	char rua[50];
	int numero;
};

struct cadastro {
	char nome[50];
	int idade;
	struct endereco ender;
};

int main() {
	struct cadastro c;
	
	gets(c.nome);
	scanf("%d", &c.idade);
	gets(c.ender.rua);
	scanf("%d", &c.ender.numero);
	
	getchar();
	
	return 0;
}
