/*
*Estacionamento em forma de estrutura pilha.
*programa recebe placa do veiculo
*toda vez que sair um veiculo, os outros veiculos deve recever uma manobra adicionada.
*programa dever mostrar veiculo que saiu e a quantidade de manobras que fez.
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define TAMANHO 4

struct veiculo {
	int placa;
	int manobra;
};
struct pilha {
	int topo;
	struct veiculo item[TAMANHO];
};
void inicializar(struct pilha *pp);
int vazia(struct pilha *pp);
int cheia(struct pilha *pp);
void push(struct pilha *pp, struct veiculo pv);
struct veiculo pop(struct pilha *pp);
void zeraManobra(struct pilha *pp);
void contaManobra(struct pilha *pp);
void entradaVeiculo(struct pilha *pp, struct veiculo pv);
void saidaVeiculo(struct pilha *pp, struct pilha *pauxp, struct veiculo *pauxv);

int main() {
	
	struct pilha p;
	struct pilha auxpTopo;
	struct veiculo v;
	struct veiculo auxvPop;
	inicializar(&p);
	inicializar(&auxpTopo);
	
	
	
	getch();
	return 0;
}
void inicializar(struct pilha *pp) {
	pp->topo = -1;
}
int vazia(struct pilha *pp) {
	if(pp->topo == -1) {
		return 1;
	}
	else {
		return 0;
	}
}
int cheia(struct pilha *pp) {
	if(pp->topo == TAMANHO-1) {
		return 1;
	}
	else {
		return 0;
	}
}
void push(struct pilha *pp, struct veiculo pv) {
	if(cheia(pp)) {
		printf("\nPilha cheia!");
		return;
	}
	else {
		pp->item[++(pp->topo)] = pv;
	}
}
struct veiculo pop(struct pilha *pp) {
	if(vazia(pp)) {
		printf("\nPilha vazia!");
		return pp->item[pp->topo];
	}
	else {
		return pp->item[pp->topo--];
	}
}
void zeraManobra(struct pilha *pp) {
	pp->item[pp->topo].manobra = 0;
}
void contaManobra(struct pilha *pp) {
	struct veiculo auxv;
	struct pilha auxp;
	inicializar(&auxp);
	while(!vazia(pp)) {
		auxv = pop(pp);
		push(&auxp, auxv);
	}
	while(!vazia(&auxp)) {
		auxv = pop(&auxp);
		auxv.manobra++;
		push(pp, auxv);
	}
}
void entradaVeiculo(struct pilha *pp, struct veiculo pv) {
	printf("\nDigite a placa do Veiculo: ");
	scanf("%d", &pv.placa);
	push(pp, pv);
}
void saidaVeiculo(struct pilha *pp, struct pilha *pauxp, struct veiculo *pauxv) {
	pauxp->topo = pp->topo;
	*pauxv = pop(pp);
	contaManobra(pp);
}

