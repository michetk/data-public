/*
ESTRUTURA DE DADOS MODELO PILHA
*/

#include<stdio.h>
#include<stdlib.h>

#define TAMANHO 100
struct pilha {
	int topo;
	int item[TAMANHO];
};
void inicializa(struct pilha *ps) {
	ps->topo = -1;
}
int vazia(struct pilha *ps) {
	if(ps->topo == -1)
		return (1);
	else
		return (0);
}
int cheia(struct pilha *ps) {
	if(ps->topo == 99)
		return (1);
	else
		return (0);
}
void push(struct pilha *ps, int x) {
	if(cheia(ps))
		printf("Pilha cheia\n");
	else
		ps->item[++(ps->topo)] = x;
}
int pop(struct pilha *ps) {
	if(vazia(ps)) {
		printf("Pilha vazia\n");
		return -1;
	}
	else
		return (ps->item[ps->topo--]);
		
}
void opcao(int *op) {
	printf("1 - PUSH\n");
	printf("2 - POP\n");
	printf("Escolha a Opcao: ");
	scanf("%d", op);
}
int quantidade(struct pilha *ps) {
	int x;
	int contador = 0;
	struct pilha aux;
	inicializa(&aux);
	if(vazia(ps))
		return 0;
	while(!vazia(ps)) {
		x = pop(ps);
		contador++;
		push(&aux, x);
	}
	while(!vazia(&aux)) {
		x = pop(&aux);
		push(ps, x);
	}
	return contador;
}
void mostraPilha(struct pilha *ps) {
	int x;
	struct pilha aux;
	inicializa(&aux);
	if(vazia(ps)) {
		printf("\nPilha vazia");
		getchar();
		return;
	}
	while(!vazia(ps)) {
		x = pop(ps);
		push(&aux, x);
	}
	while(!vazia(&aux)) {
		x = pop(&aux);
		printf("\nElemento na pilha %d", x);
		push(ps, x);
	}
}

int main() {
	struct pilha p;
	inicializa(&p);
	int op, x;
	op = -1;
	do{
		do{
			system("cls");
			opcao(&op);
		}while(op < 1 || op > 2);
		switch(op) {
			case 1:
				cheia(&p);
				printf("\nDigite o Inteiro para a PILHA: ");
				scanf("%d", &x);
				push(&p, x);
				printf("\nPOSICAO-TOP atual: %d\n", p.topo);
				printf("VALOR-TOP atual: %d\n", p.item[p.topo]);
				printf("QTDE Elementos: %d", quantidade(&p));
				mostraPilha(&p);
				break;
			case 2:
				vazia(&p);
				pop(&p);
				printf("\nTOP atual: %d\n", p.topo);
				printf("VALOR-TOP atual: %d\n", p.item[p.topo]);
				printf("QTDE Elementos: %d", quantidade(&p));
				mostraPilha(&p);
				break;
			default:
				printf("\nERRO! (in switch)\n");
		}
		printf("\n\n...ENTER PARA NOVA OPCAO...");
		getchar();
		getchar();
	}while(1);
	
	getchar();
	getchar();
	return 0;
}
