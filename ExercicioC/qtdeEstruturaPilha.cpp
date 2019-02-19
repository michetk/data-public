/*
1. USANDO AS PRIMITIVAS PARA MANIPULAÇÃO DE PILHAS, ESCREVER UMA FUNÇÃO EM C DEFINIDA COMO INT QUANTIDADE(STUCT PILHA *PS) QUE RETORNA A QUANTIDADE DE ELEMENTOS DA PILHA PASSADA
COMO PARANMETRO. APÓS A EXECUÇÃO DA FUNÇÃO A PILHA ORIGINAL MANTEM SEUS ELEMENTOS NAS MESMAS POSIÇÕES.
*/

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
		ps->item[++(ps->topo)] = x;
		//ps->topo = ps->topo + 1;
		//ps->item[ps->topo] = x;
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
		return ps->item[ps->topo--];
		//x = ps->item[ps->topo];
		//ps->topo = ps->topo - 1;
		//return x;
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
main() {
	struct pilha s;
	int i, x;
	inicializa(&s);
	push(&s, 3);
	push(&s, 10);
	push(&s, 11);
	
	printf("\nElemento retirado da pilha: %d", pop(&s));
	printf("\nQTDE Elementos: %d", quantidade(&s));
	printf("\n\n\nFim do programa");
	getchar();
	
}
