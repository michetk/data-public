/*
:::: TRABALHO ESTRUTURA DE DADOS I ::::

*Pode ser desenvolvido em até duas pessoas
______________________________________________


:::: DADA AS SEGUINTES ESTRUTURAS ::::

struct listaDisciplina {
	int codigo; //codigo nunca pode ser o mesmo
	char nome[50];
	float nota;
	float frequencia;
	struct listaDisciplina *proximo;
};

struct listaAluno {
	int codigo;
	char nome[50];
	struct listaAluno *proximo;
	struct listaDisciplina *disc;
};


-> Escrever um programa em C que contenha funcoes p/ 
INSERIR ELEMENTOS NA LISTA DE ALUNOS,
ALTERAR ELEMENTOS NA LISTA DE ALUNOS,
EXCLUIR ELEMENTOS DA LISTA DE ALUNOS,
MOSTRAR ELEMENTOS DA LISTA DE ALUNOS.
	Na inclusao de elementos na lista de alunos, atribuir NULL para o 
campo disc. Criar menu com as opcoes. Essa descrição contempla a primeira 
parte do trabalho.

-> Na segunda parte do trabalho, escrever funções p/
INSERIR,
ALTERAR,
EXCLUIR,
MOSTRAR ELEMENTOS NA LISTA DE DISCIPLINA.
	Cada aluno vai ter uma lista de disciplina associada. O ponteiro 
disc da listaAluno será o ponteiro inicio da lista de disciplina.
	O programa deverá mostrar os alunos e suas respectivas disciplinas, 
inidando se foi aprovado ou reprovado em alguma delas. Para ser aprovado a 
nora precisa ser maior ou igual a 6.0 e a frequencia ser maior ou igual a 
75.

-> VALIDACOES
	Um aluno so pode ser excluido se nao existir disciplina associada a 
ele, ou seja, disc deve ter o valor igual a NULL.
	Um aluno terá um código chave.
*/


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


struct listaDisciplina{
	int codigo;
	char nome[50];
	float nota;
	float frequencia;
	struct listaDisciplina *proximo;
};
struct listaAluno{
	int codigo;
	char nome[50];
	struct listaAluno *proximo;
	struct listaDisciplina *disc;
};

//funcões Aluno
//funcões de INSERÇÃO
struct listaAluno *insereInicioAluno(struct listaAluno *paluno, int x, char n[50]) {
	struct listaAluno *aux;
	aux = (listaAluno*)malloc(sizeof(listaAluno));
	aux->codigo = x;
	strcpy(aux->nome, n);
	aux->disc = NULL;
	aux->proximo = paluno;
	paluno = aux;
	return paluno;
}
void insereDepoisAluno(struct listaAluno *paluno, int x, char n[50]) {
	struct listaAluno *aux;
	aux = (listaAluno*)malloc(sizeof(listaAluno));
	aux->codigo = x;
	strcpy(aux->nome, n);
	aux->disc = NULL;
	aux->proximo = paluno->proximo;
	paluno->proximo = aux;
}
void mostraAluno(struct listaAluno *paluno) {
	struct listaAluno *aux;
	aux = paluno;
	while(aux != NULL) {
		printf("\nAluno: [%d] :::: Nome: %s", aux->codigo, aux->nome);
		aux = aux->proximo;
	}
}


int main() {
	struct listaAluno *al;
	al = (listaAluno*)malloc(sizeof(listaAluno));
	
	//al->codigo = 5;
	//al->nome[0] = 'a';
	
	al = insereInicioAluno(al, 10, "Barros");
	
	mostraAluno(al);
	
	printf("\n\n\nFIM DO PROGRAMA!!!");
	getch();
	return 0;
}



