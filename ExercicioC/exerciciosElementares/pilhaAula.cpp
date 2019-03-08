#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define tamanho 100

struct pilha {
	int item[tamanho];
	int topo;
};
void inicializa(struct pilha *ps) {
	ps->topo = -1;
}
int cheia(struct pilha *ps) {
	if(ps->topo == tamanho-1)
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
	else {
		ps->topo = ps->topo + 1;
		ps->item[ps->topo] = x;
	}
}
int pop(struct pilha *ps) {
	int x;
	if(vazia(ps)) {
		printf("\nPilha vazia");
		getchar();
		return -1;
	}
	else
		x = ps->item[ps->topo];
		ps->topo = ps->topo - 1;
		return x;
}
main() {
	struct pilha s;
	inicializa(&s);
	push(&s, 3);
	push(&s, 10);
	push(&s, 11);
	printf("\nElemento retirado da pilha: %d", pop(&s));
	printf("\n\n\nFim do programa");
	getchar();
	
}
