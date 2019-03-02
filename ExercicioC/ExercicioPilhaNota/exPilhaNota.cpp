/*
*UM ESTACIONAMENTE CONTEM UMA UNICA ALAMEDA QUE GUARDA ATÉ 10 CARROS.
*EXISTE APENAS UMA ENTRA/SAIDA NO ESTACIONAMENTO EM UMA EXTREMIDADE DA ALAMEDA.
*SE CHEGAR UM CLIENTE PARA TIRAR UM CARRO QUE NÃO O MAIS PROXIMO DA SAÍDA, TODOS OS CARROS BLOQUEANDO O CAMINHO SAIRÃO DO ESTACIONAMENTO.
*O CARRO DO CLIENTE SARÁ MANOBRADO PARA FORA, E OS OUTROS CARROS VOLTARÃO A OCULPAR A MESMA SEQUENCIA INICIAL.
*ESCREVA UM PROGRAMA EM C, QUE TENHA COMO ENTRADA UM "E" DE ENTRADA OU UM "S" DE SAÍDA E O NÚMERO DA PLACA DO CARRO.
*O PROGRAMA DEVE MOSTRAR UMA MENSAGEM SEMPRE QUE UM CARRO CHEAR OU SAIR.
*QUANDO CHEGAR A MENSAGEM DEVE ESPECIFICAR SE EXISTE VAGA PARA O CARRO, SE NÃO HOUVER VAGA O CARRO PARTIRÁ SEM ENTRAR NO ESTACIONAMENTO.
*QUANDO O CARRO SAIR DO ESTACIONAMENTO A MENSAGEM DEVERÁ INCLUIR O NÚMERO DE VEZES QUE O CARRO FOI MANOBRADO PARA FORA DO ESTACIONAMENTO.
*/

#include<stdio.h>
#include<stdlib.h>

#define TAMANHO 10

struct veiculo {
	int placa;
	int manobras;
};
struct pilha {
	int topo;
	struct veiculo item[TAMANHO];
};
void inicializar(struct pilha *ps);
int cheia(struct pilha *ps);
int vazia(struct pilha *ps);
void push(struct pilha *ps, int x);
int pop(struct pilha *ps);
int quantidade(struct pilha *ps);
void mostraPilha(struct pilha *ps);
void menu(int *op);
int fconfirmar(char confirmar);

int mainRet;
int main() {
	struct pilha s;
	struct veiculo valorS;
	int op;
	valorS.placa = 0;
	inicializar(&s);
	do {
		system("cls");
		menu(&op);
		switch(op) {
			case 1:
				printf(":::ENTRADA:::");
				printf("\nDigite o numero da PLACA: ");
				scanf("%d", &valorS.placa);
				printf("______________________________\n");
				push(&s, valorS.placa);
				break;
			case 2:
				char confirmar;
				int conf;
				printf(":::SAIDA:::");
				printf("\nTem certeza que deseja remover o carro de PLACA->%d? S/N: ", s.item[s.topo]);
				fflush(stdin);
				scanf("%c", &confirmar);
				printf("\nCHAR: %c", confirmar);
				conf = fconfirmar(confirmar);
				if(conf == 1) {
					pop(&s);
					break;
				}
				else
					break;
				
			default:
				break;
		}
		
		printf("\nUltimo carro a entrar: PLACA->%d", s.item[s.topo]);
		printf("\nQuantidade de carros no estacionamento: %d", quantidade(&s));
		mostraPilha(&s);
		
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
		ps->item[++(ps->topo)].placa = x;
}
int pop(struct pilha *ps) {
	if(vazia(ps)) {
		printf("\nPilha vazia");
		getchar();
		return -1;
	}
	else
		return ps->item[ps->topo--].placa;
}
int quantidade(struct pilha *ps) {
	struct pilha aux;
	struct veiculo x;
	int qtde = 0;
	inicializar(&aux);
	if(vazia(ps))
		return qtde;
	while(!vazia(ps)) {
		x.placa = pop(ps);
		push(&aux, x.placa);
	}
	while(!vazia(&aux)) {
		x.placa = pop(&aux);
		qtde++;
		push(ps, x.placa);
	}
	return qtde;
}
void mostraPilha(struct pilha *ps) {
	struct pilha aux;
	struct veiculo x;
	int cont = 0;
	inicializar(&aux);
	if(vazia(ps))
		printf("\nPilha vazia");
	while(!vazia(ps)) {
		x.placa = pop(ps);
		push(&aux, x.placa);
	}
	while(!vazia(&aux)) {
		x.placa = pop(&aux);
		printf("\n--> POSICAO(%d) contem PLACA->%d", cont, x.placa);
		push(ps, x.placa);
		cont++;
	}
}
void menu(int *op) {
	int aux = 0;
	*op = -1;
	do {
		system("cls");
		if(aux == 0) {
			if(mainRet == 1) {
				printf("\n\nInvalido! tente novamente s(sim) ou n(nao) para a opcao 2...");
				mainRet = 0;
			}
			printf("\n___ESCOLHA AS OPCOES___");
			printf("\n1. PUSH");
			printf("\n2. POP");
			printf("\n\n\nDigite a opcao: ");
			scanf("%d", op);
		}
		if(aux == 1) {
			printf("\n___ESCOLHA AS OPCOES___");
			printf("\n1. PUSH");
			printf("\n2. POP");
			printf("\n\nOPCAO INVALIDA! ..tente novamente..");
			printf("\nDigite a opcao: ");
			scanf("%d", op);
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
		printf("\n\n______________________________\n\n");
	}
	aux = 0;
}
int fconfirmar(char confirmar) {
	if(confirmar == 's' || confirmar == 'n') {
		if(confirmar == 's')
			return 1;
		else
			return 0;
	}
	else {
		mainRet = 1;
		main();
	}
}
