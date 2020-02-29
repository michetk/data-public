/*
ACESSANDO AS VARI�VEIS DE DENTRO DA ESTRUTURA
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cadastro {
	char nome[45];
	int idade;
	char rua[50];
	int numero;
};

int main() {
	struct cadastro c;
	
	strcpy(c.nome, "Miguel");
	c.idade = 28;
	strcpy(c.rua, "Miragaia mmdc");
	c.numero = 712;
	
	system("pause");
	return 0;
}
