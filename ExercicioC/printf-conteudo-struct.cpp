/*
PRINTF DOS CONTEUDO DA STRUCT
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cadastro {
	char nome[50];
	int idade;
	char rua[50];
	int numero;
};

int main() {
	struct cadastro c;
	
	strcpy(c.nome, "Miguel");
	c.idade = 28;
	strcpy(c.rua, "Miragaia MMDC");
	c.numero = 172;
	
	printf("Nome: %s\n", c.nome);
	printf("Idade: %d\n", c.idade);
	printf("Rua: %s\n", c.rua);
	printf("Numero: %d\n", c.numero);
	
	system("pause");
	return 0;
}
