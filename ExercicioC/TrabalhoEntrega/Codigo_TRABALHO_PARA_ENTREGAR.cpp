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
#define NOMEALUNO 50


struct listaDisciplina{
	int codigo;
	char nome[NOMEALUNO];
	float nota;
	float frequencia;
	struct listaDisciplina *proximo;
};
struct listaAluno{
	int codigo;
	char nome[NOMEALUNO];
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
struct listaAluno *insereOrdenadoAluno(struct listaAluno *paluno, int x, char n[50]) {
	struct listaAluno *p, *q;
	if(paluno == NULL || x < paluno->codigo) {
		return insereInicioAluno(paluno, x, n);
	}
	p = paluno;
	q = p;
	while((q != NULL) && (q->codigo < x)){
		p = q;
		q = p->proximo;
	}
	if((q == NULL) || (q->codigo > x)) {
		insereDepoisAluno(p, x, n);
	}
	else {
		printf("\nAluno ja cadastrado!");
	}
	return paluno;
}
struct listaAluno *removeInicioAluno(struct listaAluno *paluno) {
	struct listaAluno *aux;
	aux = paluno;
	paluno = paluno->proximo;
	free(aux);
	return paluno;
}
void removeDepoisAluno(struct listaAluno *paluno) {
	struct listaAluno *aux;
	aux = paluno->proximo;
	paluno->proximo = aux->proximo;
	free(aux);
}
struct listaAluno *removeOrdenadoAluno(struct listaAluno *paluno, int x) {
	struct listaAluno *p, *q;
	if(paluno == NULL) {
		printf("\nRegistro Vazio!");
		getch();
		return paluno;
	}
	if(x == paluno->codigo) {
		return (removeInicioAluno(paluno));
	}
	p = paluno;
	q = p;
	while(q != NULL && q->codigo < x) {
		p = q;
		q = p->proximo;
	}
	if(q != NULL && q->codigo == x) {
		removeDepoisAluno(p);
	}
	else {
		printf("\nAluno nao cadastrado!");
	}
	return paluno;
}
struct listaAluno *alteraAluno(struct listaAluno *paluno, int x) {
	char nome[NOMEALUNO];
	struct listaAluno *p, *q;
	if(paluno == NULL) {
		printf("\nRegistro vazio!");
		getch();
		return paluno;
	}
	if(x == paluno->codigo) {
		printf("\nDigite o nome do aluno: ");
		fflush(stdin);
		gets(nome);
		strcpy(paluno->nome, nome);
	}
	return paluno;
}
void opcao(int *op) {
	do{
		system("cls");
		printf("\n1. Buscar");
		printf("\n2. Inserir");
		printf("\n3. Alterar");
		printf("\n4. Mostar");
		printf("\n5. Excluir");
		printf("\nDigite a opcao: ");
		scanf("%d", op);
	}while(*op < 1 || *op > 5);
}
void mostraAluno(struct listaAluno *paluno) {
	struct listaAluno *aux;
	aux = paluno;
	while(aux != NULL) {
		printf("\nAluno[%d] :::: Nome: %s", aux->codigo, aux->nome);
		aux = aux->proximo;
	}
	getch();
}


int main() {
	int op;
	int codigo;
	char nome[NOMEALUNO];
	struct listaAluno *al;
	al = NULL;
	
	al = insereOrdenadoAluno(al, 11, "Barros");
	al = insereOrdenadoAluno(al, 9, "Miguel");
	al = insereOrdenadoAluno(al, 10, "Sousa");
	al = insereOrdenadoAluno(al, 12, "Lucas");
	
	/*mostraAluno(al);
	
	al = removeOrdenadoAluno(al, 10);
	
	printf("\n");
	mostraAluno(al);*/
	
	do{
		opcao(&op);
		
		switch(op) {
			case 1:
				break;
			case 2:
				printf("\nDigite o codigo do aluno: ");
				scanf("%d", &codigo);
				printf("\nDigite o nome do aluno: ");
				fflush(stdin);
				gets(nome);
				al = insereOrdenadoAluno(al, codigo, nome);
				break;
			case 3:
				printf("\nCodigo do aluno que deseja alterar: ");
				scanf("%d", &codigo);
				al = alteraAluno(al, codigo);
				break;
			case 4:
				mostraAluno(al);
				break;
			case 5:
				printf("\nCodigo do aluno que deseja remover: ");
				scanf("%d", &codigo);
				al = removeOrdenadoAluno(al, codigo);
				break;
			default:
				break;
		}
	}while(1);
	
	
	
	//mostraAluno(al);
	
	
	printf("\n\n\nFIM DO PROGRAMA!!!");
	getch();
	return 0;
}



