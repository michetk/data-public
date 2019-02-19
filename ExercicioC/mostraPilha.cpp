/*2. Utilizando as funções primitivas para manipulção de pilha, escrever uma função denomimada de "void mashaPilha(stuct pilha *ps)" que mostra o conteúdo de uma pilha na ordem em que
os elementos foram inseridos.
Apos a execução da função manter os elementos nas mesmas posições da pilha.
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
void mostraPilha(struct pilha *ps) {
	int x;
	struct pilha aux;
	inicializa(&aux);
	if(vazia(ps)) {
		printf("\nPilha vazia");
		getch();
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
main() {
	struct pilha s;
	int i, x;
	inicializa(&s);
	push(&s, 3);
	push(&s, 10);
	push(&s, 11);
	push(&s, 20);
	push(&s, 40);
	
	printf("\nElemento retirado da pilha: %d", pop(&s));
	printf("\n\nElementos Inseridos:\n\n");
	mostraPilha(&s);
	printf("\n\n\nFim do programa");
	getchar();
	
}
