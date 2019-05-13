/*
:::: TRABALHO ESTRUTURA DE DADOS I ::::

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
#define NOMEDISCIPLINA 50


struct listaAluno{
	int codigo;
	char nome[NOMEALUNO];
	struct listaAluno *proximo;
	struct listaDisciplina *disc;
};
struct listaDisciplina{
	int codigo;
	char nome[NOMEALUNO];
	float nota;
	float frequencia;
	struct listaDisciplina *proximo;
};

//Funções da estrutura aluno
struct listaAluno *insereInicioAluno(struct listaAluno *paluno, int px, char pn[NOMEALUNO]) {
	struct listaAluno *aux;
	aux = (listaAluno*)malloc(sizeof(listaAluno));
	aux->codigo = px;
	strcpy(aux->nome, pn);
	aux->disc = NULL;
	aux->proximo = paluno;
	paluno = aux;
	return paluno;
}
void insereDepoisAluno(struct listaAluno *paluno, int px, char pn[NOMEALUNO]) {
	struct listaAluno *aux;
	aux = (listaAluno*)malloc(sizeof(listaAluno));
	aux->codigo = px;
	strcpy(aux->nome, pn);
	aux->disc = NULL;
	aux->proximo = paluno->proximo;
	paluno->proximo = aux;
}
struct listaAluno *insereOrdenadoAluno(struct listaAluno *paluno, int px, char pn[NOMEALUNO]) {
	struct listaAluno *p, *q;
	if(paluno == NULL || px < paluno->codigo) {
		return insereInicioAluno(paluno, px, pn);
	}
	p = paluno;
	q = p;
	while(q != NULL && q->codigo < px){
		p = q;
		q = p->proximo;
	}
	if(q == NULL || q->codigo > px) {
		insereDepoisAluno(p, px, pn);
	}
	else {
		printf("\nAluno ja cadastrado!");
	}
	return paluno;
}
struct listaAluno *removeInicioAluno(struct listaAluno *paluno) {
	struct listaAluno *aux;
	if(paluno == NULL) {
		printf("nLista aluno vazia!");
		getch();
		return paluno;
	}
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
struct listaAluno *removeOrdenadoAluno(struct listaAluno *paluno, int px) {
	struct listaAluno *p, *q;
	if(paluno == NULL) {
		printf("\nNao ha aluno cadastrado!");
		getch();
		return paluno;
	}
	if(px == paluno->codigo) {
		return (removeInicioAluno(paluno));
	}
	p = paluno;
	q = p;
	while(q != NULL && q->codigo < px) {
		p = q;
		q = p->proximo;
	}
	if(q != NULL && q->codigo == px) {
		removeDepoisAluno(p);
	}
	else {
		printf("\nAluno nao cadastrado!");
	}
	return paluno;
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
struct listaAluno *consultaAluno(struct listaAluno *paluno, int px) {
	struct listaAluno *p, *q;
	p = paluno;
	if(p == NULL) {
		printf("\nLista vazia!");
		getch();
		return p;
	}
	if(p->codigo == px) {
		printf("\nAluno[%d] :::: Nome: %s", p->codigo, p->nome);
		getch();
		return p;
	}
	q = p;
	while(q != NULL && q->codigo < px) {
		p = q;
		q = p->proximo;
	}
	if(q != NULL && q->codigo == px) {
		printf("\nAluno[%d] :::: Nome: %s", q->codigo, q->nome);
		getch();
	}
	else {
		printf("\nAluno nao cadastrado!");
		getch();
	}
	return q;
}
void alteraAluno(struct listaAluno *paluno, int px) {
	struct listaAluno *aux;
	aux = consultaAluno(paluno, px);
	if(aux->codigo == px) {
		printf("\nDigite o nome do aluno: ");
		fflush(stdin);
		gets(aux->nome);
	}
}

//Funções da estrutura disciplina
struct listaDisciplina *insereInicioDisciplina(struct listaDisciplina *pdisc, int px, char pn[NOMEDISCIPLINA], float pnt, float pf) {
	struct listaDisciplina *aux;
	aux = (struct listaDisciplina*)malloc(sizeof(struct listaDisciplina));
	aux->codigo = px;
	strcpy(aux->nome, pn);
	aux->nota = pnt;
	aux->frequencia = pf;
	aux->proximo = pdisc;
	pdisc = aux;
	return pdisc;
}
void insereDepoisDisciplina(struct listaDisciplina *pdisc, int px, char pn[NOMEDISCIPLINA], float pnt, float pf) {
	struct listaDisciplina *aux;
	aux = (struct listaDisciplina*)malloc(sizeof(struct listaDisciplina));
	aux->codigo = px;
	strcpy(aux->nome, pn);
	aux->nota = pnt;
	aux->frequencia = pf;
	aux->proximo = pdisc->proximo;
	pdisc->proximo = aux;
}
struct listaDisciplina *insereOrdenadoDisciplina(struct listaDisciplina *pdisc, int px, char pn[NOMEDISCIPLINA], float pnt, float pf) {
	struct listaDisciplina *p, *q;
	if(pdisc == NULL || px < pdisc->codigo) {
		return insereInicioDisciplina(pdisc, px, pn, pnt, pf);
	}
	p = pdisc;
	q = p;
	while(q != NULL && q->codigo < px) {
		p = q;
		q = p->proximo;
	}
	if(q != NULL && q->codigo > px) {
		insereDepoisDisciplina(p, px, pn, pnt, pf);
	}
	else {
		printf("\nDisciplina ja cadastrada!");
	}
	return pdisc;
}
struct listaDisciplina *removeInicioDisciplina(struct listaDisciplina *pdisc) {
	struct listaDisciplina *aux;
	if(pdisc == NULL) {
		printf("\nLista disciplina vazia!");
		getch();
		return pdisc;
	}
	pdisc = pdisc->proximo;
	return pdisc;
}
void removeDepoisDisciplina(struct listaDisciplina *pdisc) {
	struct listaDisciplina *aux;
	aux = pdisc->proximo;
	pdisc->proximo = aux->proximo;
	free(aux);
}
struct listaDisciplina *removeOrdenadoDisciplina(struct listaDisciplina *pdisc, int px) {
	struct listaDisciplina *p, *q;
	if(pdisc == NULL) {
		printf("\nNao ha disciplina cadastrada!");
		getch();
		return pdisc;
	}
	if(pdisc->codigo == px) {
		return removeInicioDisciplina(pdisc);
	}
	p = pdisc;
	q = p;
	while(p != NULL && p->codigo < px) {
		p = q;
		q = p->proximo;
	}
	if(q != NULL && p->codigo == px) {
		removeDepoisDisciplina(p);
	}
	else {
		printf("\nDisciplina nao cadastrada!");
	}
	return pdisc;
	
}
void mostraDisciplina(struct listaDisciplina *pdisc) {
	struct listaDisciplina *aux;
	if(pdisc == NULL) {
		printf("\nLista disciplina vazia!");
		getch();
	}
	aux = pdisc;
	while(aux != NULL) {
		printf("\nDisciplina[%d] :::: Nome: %s", aux->codigo, aux->nome);
		aux = aux->proximo;
	}
	getch();
}
struct listaDisciplina *consultaDisciplina(struct listaDisciplina *pdisc, int px) {
	struct listaDisciplina *p, *q;
	p = pdisc;
	if(p == NULL) {
		printf("\nLista disciplina vazia!");
		getch();
		return p;
	}
	if(p->codigo == px) {
		printf("\nDisciplina[%d] :::: Nome: %s", p->codigo, p->nome);
		getch();
		return p;
	}
	q = p;
	while(q != NULL && q->codigo < px) {
		p = q;
		q = p->proximo;
	}
	if(q != NULL && q->codigo == px) {
		printf("\nDisciplina[%d] :::: Nome: %s", q->codigo, q->nome);
		getch();
	}
	else {
		printf("\nDisciplina nao cadastrada!");
		getch();
	}
	return q;
}
void alteraDisciplina(struct listaDisciplina *pdisc, int px) {
	struct listaDisciplina *aux;
	aux = consultaDisciplina(pdisc, px);
	if(aux->codigo == px) {
		printf("\nDigite o nome da Disciplina: ");
		fflush(stdin);
		gets(aux->nome);
	}
}

//Funções genericas
void opcao(int *op) {
	do{
		system("cls");
		printf("\n1. Buscar");
		printf("\n2. Inserir");
		printf("\n3. Alterar");
		printf("\n4. Mostar");
		printf("\n5. Excluir");
		printf("\n6. Sair");
		printf("\nDigite a opcao: ");
		scanf("%d", op);
	}while(*op < 1 || *op > 6);
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
				printf("\nCodigo do aluno para consulta: ");
				scanf("%d", &codigo);
				consultaAluno(al, codigo);
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
				alteraAluno(al, codigo);
				break;
			case 4:
				mostraAluno(al);
				break;
			case 5:
				printf("\nCodigo do aluno que deseja remover: ");
				scanf("%d", &codigo);
				al = removeOrdenadoAluno(al, codigo);
				break;
			case 6:
				exit(0);
			default:
				break;
		}
	}while(1);
	
	
	
	//mostraAluno(al);
	
	
	printf("\n\n\nFIM DO PROGRAMA!!!");
	getch();
	return 0;
}



