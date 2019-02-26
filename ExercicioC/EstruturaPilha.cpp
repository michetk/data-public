/*
ESTRUTURA DE DADOS MODELO PILHA
*/

#include<stdio.h>
#include<stdlib.h>

#define TAMANHO 100

void inicializar(struct pilha *ps);
int cheia(struct pilha *ps);
int vazia(struct pilha *ps);
void push(struct pilha *ps, int x);
int pop(struct pilha *ps);
int quantidade(struct pilha *ps);
int mostraPilha(struct pilha *ps);
void menu(int *op);
int pilhasIguais(struct pilha *pa, struct pilha *pb);
int pilhasIguais(struct pilha *pa, struct pilha *pb);


struct pilha {
	int topo;
	int item[TAMANHO];
};
int main() {
	struct pilha s, p;
	int op, valorS, valorP;
	inicializar(&s);
	inicializar(&p);
	do {
		system("cls");
		menu(&op);
		switch(op) {
			case 1:
				printf("\nDigite o inteiro para pilha 'S': ");
				scanf("%d", &valorS);
				printf("\nDigite o inteiro para pilha 'P': ");
				scanf("%d", &valorP);
				push(&s, valorS);
				push(&p, valorP);
				break;
			default:
				break;
		}
		/*push(&s, 1);
		push(&s, 2);
		push(&s, 3);
		push(&s, 4);
		
		push(&p, 1);
		push(&p, 2);
		push(&p, 3);
		push(&p, 4);*/
		printf("\nTopo 'S' ANTES do pop: %d", s.item[s.topo]);
		printf("\nTopo 'P' ANTES do pop: %d", p.item[p.topo]);
		//pop(&s);
		//printf("\nTopo DEPOIS do pop: %d", s.item[s.topo]);
		printf("\nQuantidade de itens na pilha 'S': %d", quantidade(&s));
		printf("\nQuantidade de itens na pilha 'P': %d", quantidade(&p));
		mostraPilha(&s);
		printf("\n\n");
		mostraPilha(&p);
		
		printf("\n\n\nFIM DO PROGRAMA");
		getchar();
		getchar();
	}while(1);
	getchar();
	return 0;
}
void inicializar(struct pilha *ps) {
	ps->topo = -1;
}
int cheia(struct pilha *ps) {
	if(ps->topo == TAMANHO -1)
		return 1;
	else
		return 0;
}
int vazia(struct pilha *ps) {
	if(ps->topo == -1)
		return 1;
	else
		return 0;
}
void push(struct pilha *ps, int x) {
	if(cheia(ps)) {
		printf("\nPilha cheia");
		getchar();
	}
	else
		ps->item[++(ps->topo)] = x;
}
int pop(struct pilha *ps) {
	if(vazia(ps)) {
		printf("\nPilha vazia");
		getchar();
		return -1;
	}
	else
		return ps->item[ps->topo--];
}
int quantidade(struct pilha *ps) {
	struct pilha aux;
	int x;
	int qtde = 0;
	inicializar(&aux);
	if(vazia(ps))
		return 1;
	while(!vazia(ps)) {
		x = pop(ps);
		push(&aux, x);
	}
	while(!vazia(&aux)) {
		x = pop(&aux);
		qtde++;
		push(ps, x);
	}
	return qtde;
}
int mostraPilha(struct pilha *ps) {
	struct pilha aux;
	int x;
	inicializar(&aux);
	if(vazia(ps))
		return 1;
	while(!vazia(ps)) {
		x = pop(ps);
		push(&aux, x);
	}
	while(!vazia(&aux)) {
		x = pop(&aux);
		printf("\nITEM na pilha: %d", x);
		push(ps, x);
	}
}
void menu(int *op) {
	int aux = 0;
	*op = -1;
	do {
		system("cls");
		if(aux == 0) {
			printf("\n___ESCOLHA AS OPCOES___");
			printf("\n1. PUSH");
			printf("\n2. POP");
			printf("\n\n\nDigite a opcao: ");
			scanf("%d", op);
			printf("\n\n______________________________\n");
		}
		if(aux == 1) {
			printf("\n___ESCOLHA AS OPCOES___");
			printf("\n1. PUSH");
			printf("\n2. POP");
			printf("\n\nOPCAO INVALIDA! ..tente novamente..");
			printf("\nDigite a opcao: ");
			scanf("%d", op);
			printf("\n\n______________________________\n");
		}
		aux = 1;
	}while(*op < 1 || *op > 2);
	aux = 2;
	if(aux == 2) {
		system("cls");
		printf("\n___ESCOLHA AS OPCOES___");
		printf("\n1. PUSH");
		printf("\n2. POP");
		printf("\n\n\nDigite a opcao: %d", *op);
		printf("\n\n______________________________\n");
	}
	aux = 0;
}
int pilhasIguais(struct pilha *pa, struct pilha *pb) {
	int avalor, bvalor;
	int retorno = 1;
	struct pilha auxa, auxb;
	if(quantidade(pa) != quantidade(pb))
		return 0;
	inicializar(&auxa);
	inicializar(&auxb);
	while(!vazia(pa) && !vazia(pb)) {
		avalor = pop(pa);
		bvalor = pop(pb);
		push(&auxa, avalor);
		push(&auxb, bvalor);
		if(avalor != bvalor) {
			while(!vazia(&auxa)) {
				avalor = pop(&auxa);
				bvalor = pop(&auxb);
				push(pa, avalor);
				push(pb, bvalor);
			}
			return 0;
		}
	}
	while(!vazia(&auxa) && !vazia(&auxb)) {
		avalor = pop(&auxa);
		bvalor = pop(&auxb);
		push(pa, avalor);
		push(pb, bvalor);
	}
	return 1;
	
}

// OUTRO MODELO PARA DESCOBRIR SE AS PILHAS SÃO IGUAIS.

/*int pilhasIguais(struct pilha *pa, struct pilha *pb) {
	int avalor, bvalor;
	int retorno = 1;
	struct pilha auxa, auxb;
	if(quantidade(pa) != quantidade(pb))
		return 0;
	inicializar(&auxa);
	inicializar(&auxb);
	while(!vazia(pa) && !vazia(pb)) {
		avalor = pop(pa);
		bvalor = pop(pb);
		push(&auxa, avalor);
		push(&auxb, bvalor);
		if(avalor != bvalor) {
			retorno = 0;
			break;
		}
	}
	while(!vazia(&auxa)) {
		avalor = pop(&auxa);
		push(pa, avalor);
	}
	while(!vazia(&auxb)) {
		bvalor = pop(&auxb);
		push(pb, bvalor);
	}
	return retorno;
}*/
