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

int main() {
	struct pilha p;
	p.topo = -1;
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
				break;
			case 2:
				vazia(&p);
				pop(&p);
				printf("\nTOP atual: %d\n", p.topo);
				printf("VALOR-TOP atual: %d\n", p.item[p.topo]);
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
